// Server1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <winsock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment (lib,"ws2_32")

int main()
{
   //khoi tao thu vien
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    //tao socket cho ket noi
    SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //khai bao dia chi server
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(8000);

    //gan dia chi voi socket
    bind(listener, (SOCKADDR*)&addr, sizeof(addr));

    //chuyen sang trang thai cho ket noi
    listen(listener, 5);

    //chap nhan ket noi
    printf("Waiting for client...\n");
    SOCKET client = accept(listener, NULL, NULL);

    char buf[256];

    //nhan du lieu tu client
    int ret = recv(client, buf, sizeof(buf), 0);

    if (ret <= 0)
    {
        printf("Ket noi bi dong hoac bi huy");
        system("pause");
        return 1;
    } 

    //Xu li du lieu
    printf("Received: %s\n", buf);

    //Doc du lieu tu ban phim va gui sang client
    while (1)
    {
        gets_s(buf);
        if (strcmp(buf, "exit")) break;
        send(client, buf, strlen(buf), 0);
    }
    closesocket(client);
    closesocket(listener);
    //Giai phong winsock
    WSACleanup();

}


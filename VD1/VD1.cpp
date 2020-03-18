#include <stdio.h>
#include <string.h>
#include <conio.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <ws2tcpip.h>
int main()
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    char nhap[100];
    addrinfo* info;
    SOCKADDR_IN addr;
    printf("Nhap chuoi: ");//Nhap
    gets_s(nhap);

    int ret = getaddrinfo(nhap, "http", NULL, &info); //phan giai ten mien
    if (ret == 0)//Phân giải tên miền thành công
    {
        printf("Phan giai thanh cong\n");
        while (info != NULL)
        {
            memcpy(&addr, info->ai_addr, info->ai_addrlen);
            printf("Dia chi IP: %s", inet_ntoa(addr.sin_addr));
            printf("\n");
            info = info->ai_next;
        }
    }
    else //Phân giải tên miền thất bại
    {
        printf("Phan giai that bai");
    }
    return 0;
}

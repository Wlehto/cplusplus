#pragma hdrstop
#pragma argsused

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <iostream>
#include <tchar.h>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int _tmain(int argc, _TCHAR* argv[])
{
    WSADATA wsaData;
    int iResult;

    int recvbuflen = DEFAULT_BUFLEN;

    char *sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];

    SOCKET ConnectSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    //-----------------------------------------------//
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if(iResult != 0)
    {
        std::cout << "WSAStartup fail: " << iResult << std::endl;
        system("pause");
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if(iResult != 0)
    {
        std::cout << "getaddrinfo failed: " << iResult << std::endl;
        WSACleanup();
        system("pause");
        return 1;
    }

    for(ptr = result; ptr != NULL; ptr=ptr->ai_next){

        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

        if(ConnectSocket == INVALID_SOCKET)
        {
            std::cout << "Error at socket(): " << WSAGetLastError() << std::endl;
            WSACleanup();
            system("pause");
            return 1;
        }

        iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if(iResult == SOCKET_ERROR)
        {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if(ConnectSocket == INVALID_SOCKET)
    {
        std::cout << "Unable to connect server!" << std::endl;
        WSACleanup();
        system("pause");
        return 1;
    }

    iResult = send(ConnectSocket, sendbuf, (int) strlen(sendbuf), 0 );
    if(iResult == SOCKET_ERROR)
    {
        std::cout << "send failed" << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        system("pause");
        return 1;
    }

    std::cout << "Bytes sent: " << iResult << std::endl;

    iResult = shutdown(ConnectSocket, SD_SEND);
    if(iResult == SOCKET_ERROR)
    {
        std::cout << "shut down failed: " << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        system("pause");
        return 1;
    }

    do{
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if(iResult > 0)
            std::cout << "Bytes received: " << iResult << std::endl;
        else if(iResult == 0)
            std::cout << "Connection closed" << std::endl;
        else
            std::cout << "recv failed: " << WSAGetLastError() << std::endl;
    }while(iResult > 0);

    iResult = shutdown(ConnectSocket, SD_SEND);
    if(iResult == SOCKET_ERROR)
    {
        std::cout << "shutdown failed: " << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        system("pause");
        return 1;
    }

    closesocket(ConnectSocket);
    WSACleanup();

    system("pause");
    return 0;
}

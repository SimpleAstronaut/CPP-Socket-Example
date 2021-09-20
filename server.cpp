#include <iostream>
#include <Winsock2.h>
#pragma comment (lib,"ws2_32.lib")

int main(){
    std::cout<<"Server Preparing\n";
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    std::cout<<"Server Prepare Succesfully!\n";

    SOCKET Server = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in sockAddr;
    memset(&sockAddr,0,sizeof(sockAddr));
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //gethostbyaddr()
    sockAddr.sin_port = htons(1234);
    bind(Server,(SOCKADDR*)&sockAddr,sizeof(SOCKADDR));
    std::cout<<"Server Start\n";

    listen(Server,20);
    std::cout<<"The server starts listening\n";

    SOCKADDR UsersAddr;
    int nSize = sizeof(SOCKADDR);
    SOCKET Users = accept(Server,(SOCKADDR*)&UsersAddr,&nSize);
    std::cout<<"Incoming Client Connect\n";

    char *str = "Hello World!";
    send(Users,str,strlen(str)+sizeof(char),NULL);

    closesocket(Users);
    closesocket(Server);

    WSACleanup();

    return 0;
}
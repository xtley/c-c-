#include <iostream>
#include "tcpSocket.h"
int main() {
    init_Socket();

    SOCKET serfd=createServerSocket();
    printf("wait client connecnt...\n");
    // 如果有客户端请求连接，那么我就可以
    SOCKET clifd = accept(serfd,NULL,NULL);
    if(INVALID_SOCKET==clifd) {
        err("accept");
    }
    // 可以和客户端进行通信了
    // recv从指定的socket接收消息
    char buff[BUFSIZ]={0};
    if(0<recv(clifd,buff,BUFSIZ,0)) {
        printf("recv:%s\n",buff);
    }


    closesocket(clifd);
    closesocket(serfd);


    close_Socket();

    return 0;
}

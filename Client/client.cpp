#include "tcpSocket.h"
#include <cstring>
int main() {
    init_Socket();
    SOCKET fd = createClientSocket("127.0.0.1");
    // 先说一句话，打个招呼
    char buff[BUFSIZ]="你好我是客户端，QAQ";
    if(SOCKET_ERROR==send(fd,buff,strlen(buff),0))
    {
        err("send");
    }
    closesocket(fd);
    close_Socket();
    return 0;
}

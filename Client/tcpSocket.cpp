#include "tcpSocket.h"
#include <cstdio>
bool init_Socket() {
    // wsa windows socket async windows异步套接字
    // parm1：请求的socket版本 parm2:传出参数
    WSADATA wsadata;
    if(0!=WSAStartup(MAKEWORD(2,2),&wsadata)){
        printf("WSAStartup failed code %d",WSAGetLastError());
        return false;
    }


    return true;
}
bool close_Socket() {
    if(0!=WSACleanup()){
        printf("WSACleanup failed code %d",WSAGetLastError());
        return false;
    }
    return true;
}
SOCKET createClientSocket(const char *ip){
    // 1.创建空的Socket 买新手机
    // parm1:af 地址协议族 ipv4 ipv6
    // parm2:type 传输协议类型 流式套接字 数据包套接字
    // parm3:protocl 使用具体的某个传输协议
    SOCKET fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(fd==INVALID_SOCKET) {
        err("socket");
        return INVALID_SOCKET;
    }
    // 2.与服务器建立连接
    struct sockaddr_in addr;
    addr.sin_family = AF_INET; //和创建socket时的必须一样
    addr.sin_port = htons(PORT); //大端和小端存储
    addr.sin_addr.S_un.S_addr = inet_addr(ip);
    if(INVALID_SOCKET==connect(fd,(struct sockaddr*)&addr,sizeof(addr)))
    {
        err("connect");
        return false;
    }
    return fd;
}
//
// Created by Administrator on 2024-03-30.
//
#ifndef LEARN_BASE_TCPSOCKET_H
#define LEARN_BASE_TCPSOCKET_H
#include <winsock2.h>
#include <cstdio>
#pragma comment(lib,"ws2_32.lib") //库文件

#define err(errMsg) printf("[line:%d]%s failed code %d",__LINE__,errMsg,WSAGetLastError())
#define PORT 8888
// 打开网络库
bool init_Socket();
// 关闭网络库
bool close_Socket();
// 创建服务器socket
SOCKET createServerSocket();






#endif //LEARN_BASE_TCPSOCKET_H

#pragma once

#include <string>
#include <iostream>
#include "hv/TcpClient.h"


class NetCore{
public:
    NetCore(std::string& host, int port);
    ~NetCore();

    void Start();
    void Send(std::string& msg);
private:
    int             m_sock_client;
    hv::TcpClient   m_tcp;
    std::string     m_host;
    int             m_port;
};
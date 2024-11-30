#pragma once

#include <string>
#include <iostream>
#include "hv/TcpClient.h"
#include "Service/protocol.h"

/**
 * @class NetCore
 * @brief 收发消息，格式为json
 * @note 这个类只被protocol.cpp调用
 */
class NetCore{
public:
    NetCore() = default;
    ~NetCore() = default;

    void init(std::string& host, int port, std::shared_ptr<Protocol>protocol);
    void Send(std::string& msg);
private:
    int             m_sock_client;
    hv::TcpClient   m_tcp;
    std::string     m_host;
    int             m_port;

    std::shared_ptr<Protocol>m_protocol;
};
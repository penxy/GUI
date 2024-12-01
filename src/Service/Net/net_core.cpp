#include "net_core.h"
#include <assert.h>

#define __RECONNECT__//重连

/**
 * @def init
 * @param[in] host 服务器地址
 * @param[in] port 服务器端口
 * @param[in] protocol 协议指针
 * @brief 初始化网络
 */
void NetCore::init(std::string& host, int port){
    m_sock_client = m_tcp.createsocket(port, host.c_str());
    assert(m_sock_client >= 0);

    m_tcp.onConnection = [&](const hv::SocketChannelPtr& channel){
        std::string str = channel->peeraddr();
        if(channel->isConnected()){
            std::cout << "Connected: " << str << "\n";
        }else{
            std::cout << "Connected Fail: " << str << "\n";
        }
        if (m_tcp.isReconnect()) {
            printf("reconnect cnt: %d, lost time: %d\n", m_tcp.reconn_setting->cur_retry_cnt, m_tcp.reconn_setting->cur_delay);
        }
    };

    m_tcp.onMessage = [&](const hv::SocketChannelPtr& channel, hv::Buffer* buffer){
        printf("recv: %s\n", (char*)buffer->data());
    };
#ifdef __RECONNECT__
    reconn_setting_t reconn;
    reconn_setting_init(&reconn);
    reconn.min_delay = 1000;
    reconn.max_delay = 10000;
    reconn.delay_policy = 2;
    m_tcp.setReconnect(&reconn);
#endif
    m_tcp.start();
}

void NetCore::Send(std::string& msg){
    m_tcp.send(msg.c_str());
}

#pragma once

#include "const_json.h"
#include "base_service.h"

#include <queue>
#include <semaphore.h>
#include <vector>
#include "Core/core.h"
#include "Net/net_core.h"

class Core;
class NetCore;

/**
 * @class Protocol
 * @brief 生成json并发送，接收json并解析
 */
class Protocol : public BaseService, public std::enable_shared_from_this<Protocol>{
public:
    Protocol(std::shared_ptr<NetCore>net_core);
    ~Protocol();
public:
    void init(std::shared_ptr<Core>core, int account_id);
    void start();
    
    void enqueueSend();                 //由core调用
    void enqueueRecv();                 //由core_net调用
private:
    std::string dequeueSend();
    std::string dequeueRecv();
    
    void createHead();
private: 
    int m_index; //协议序号
    std::priority_queue<std::pair<int, std::string>> m_queue_send;//发送队列, 第一项为优先级
    std::priority_queue<std::pair<int, std::string>> m_queue_recv;//接收队列, 第一项为优先级

    sem_t m_sem_wait;                               //等待信号量

    std::shared_ptr<Core> m_core;                   //解析json后，调用Core的接口
    std::shared_ptr<NetCore>m_net_core;             //发送和接收json

    struct Hand{
        QString account_id;                         //发送者id
        int index;                                  //消息下标
        time_t time;                                //发送时间
    }m_hand;
};
#include "protocol.h"

/**
 * @def init
 * @breif 初始化协议
 * @param[in] core 核心指针
 * @param[in] account_id 账号id
 */
void Protocol::init(std::shared_ptr<Core>core, int account_id){
    sem_init(&m_sem_wait, 0, 0);

    m_core = core;
    m_hand.account_id = account_id;
    m_hand.index = 0;
}
Protocol::~Protocol(){
    sem_destroy(&m_sem_wait);
}

void Protocol::start(){
    while(!m_stop){
        sem_wait(&m_sem_wait);
    


    }
}


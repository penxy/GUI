#pragma once

#include "core_fd.h"
#include "core_gp.h"
#include "core_self.h"
#include "core_recore.h"
#include "Service/protocol.h"

#include <semaphore.h>

#include <QPixmap>

/**
 * @file core.h
 * @class Core
 * @brief 界面要操作数据的所有接口所在
 * @note 所有的改变操作都不会有多个线程同时操作，因此不需要加锁
 * @details 凡是涉及要发送的消息，都需要调用Protocol的enqueueSend()接口
 * @todo 完善并实现接口
 */
class Core : public CoreFd,
             public CoreGp,
             public CoreSelf,
             public CoreRecore,
             public std::enable_shared_from_this<Core> {
public:
    Core(std::shared_ptr<Protocol>protocol) : m_protocol(protocol) {}
    ~Core() = default;
public:
    //fd
    bool sendFriend(int friendId, TypeJson::Send type_send, ...) override;
    std::shared_ptr<Friend> getFriend(int idx) override;

    int getFriendId(int idx) override;
    std::string getFriendName(int idx) override;
    QPixmap getFriendPhoto(int idx) override; 
    
    //gp
    bool sendGroup(int groupId, TypeJson::Send type_send, ...) override;
    std::shared_ptr<Group> getGroup(int idx) override;

    int getGroupId(int idx) override;
    std::string getGroupName(int idx) override;
    QPixmap getGroupPhoto(int idx) override;

    //self
    bool setPass() override;
    bool setName() override;
    bool setStatus() override;

    int getId() override;
    QString getName() override;
    Type::Status getStatus() override;

    //core
    void loadGroupRecore(int idx) override;
    void saveGroupRecore(int idx) override;
    void loadFriendRecore(int idx) override;
    void saveFriendRecore(int idx) override;
private:
    std::shared_ptr<Protocol> m_protocol;
};

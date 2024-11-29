#pragma once
#include "config.h"
#include <QList>

class CoreFd{
public:
    CoreFd() = default;
    virtual ~CoreFd() = default;
    CoreFd(const CoreFd&) = default;
    CoreFd& operator=(const CoreFd&) = default;
    CoreFd(CoreFd&&) = default;
    CoreFd& operator=(CoreFd&&) = default;

    virtual bool sendFriendAction(int friendId, Type::Msg::Action action) = 0;
    virtual bool sendFriendMessage(int friendId, const QString& message) = 0;

    virtual void addFriend(std::shared_ptr<ns::FriendInfo>) = 0;
    virtual void delFriend(int idx) = 0;//以下标为准

    virtual int getFriendId(int idx) = 0;
    virtual std::string getFriendName(int idx) = 0;
    virtual QPixmap getFriendPhoto(int idx) = 0; 
protected:
    QList<std::shared_ptr<ns::FriendInfo>> m_fd_list;
};
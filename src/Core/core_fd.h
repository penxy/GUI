#pragma once
#include "config.h"
#include <QList>
#include <memory>
#include "Service/const_json.h"

#include "Chat/friend.h"

class CoreFd{
public:
    CoreFd() = default;
    virtual ~CoreFd() = default;
    CoreFd(const CoreFd&) = default;
    CoreFd& operator=(const CoreFd&) = default;
    CoreFd(CoreFd&&) = default;
    CoreFd& operator=(CoreFd&&) = default;

    virtual bool sendFriend(int friendId, TypeJson::Send type_send, ...) = 0;
    virtual std::shared_ptr<Friend> getFriend(int idx) = 0;

    virtual int getFriendId(int idx) = 0;
    virtual std::string getFriendName(int idx) = 0;
    virtual QPixmap getFriendPhoto(int idx) = 0; 
protected:
    QList<std::shared_ptr<Friend>> m_fd_list;//好友列表
};
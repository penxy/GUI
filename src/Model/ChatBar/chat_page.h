#pragma once

#include "config.h"
#include "Core/core.h"

class ChatPage : public QWidget{
    Q_OBJECT
public:
    explicit ChatPage(Core *core, QWidget *parent = 0);
public slots:
    void SlotListChangeIdx(Type::Info::Identity identity, int idx);//切换聊天对象
private:
    Type::Info::Identity m_type;

    std::shared_ptr<ns::GroupInfo> m_group_info = nullptr;
    std::shared_ptr<ns::FriendInfo> m_friend_info = nullptr;

    QStackedWidget m_chat_main;
    Core *m_core;
};

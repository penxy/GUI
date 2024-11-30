#pragma once

#include "config.h"
#include "Core/core.h"
#include <QStackedWidget>
#include <memory>

class ChatPage : public QWidget{
    Q_OBJECT
public:
    explicit ChatPage(std::shared_ptr<Core> core, QWidget *parent = 0);
public slots:
    void SlotListChangeIdx(Type::Identity identity, int idx);//切换聊天对象
private:
    Type::Identity m_type;

    std::shared_ptr<Group> m_group_info = nullptr;
    std::shared_ptr<Friend> m_friend_info = nullptr;

    QStackedWidget m_chat_main;
    std::shared_ptr<Core> m_core;
};

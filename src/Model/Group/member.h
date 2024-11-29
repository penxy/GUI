#pragma once
#include "config.h"

//群成员列表项
class Member : public QWidget{
    Q_OBJECT
public:
    explicit Member(std::pair<ns::FriendInfo, Type::Info::Role>& info, QWidget *parent = nullptr);
private:
    QLabel m_lab_photo;
    QLabel m_lab_name;
    QLabel m_lab_id;
    QLabel m_lab_role;
};

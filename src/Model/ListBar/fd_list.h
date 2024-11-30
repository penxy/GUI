#pragma once

#include "core_list.h"

/**
 * @file fd_list.h
 * @class FdList
 * @brief 好友列表
 */
class FdList : public CoreList{
    Q_OBJECT
public:
    explicit FdList(QWidget *parent = 0);
    ~FdList() = default;

    void AddItem(std::shared_ptr<void>person_info) override;
    void DelItem(int person_id) override;
private:
    QList<std::shared_ptr<ns::FriendInfo>>m_id_list;//用于记录下标
};

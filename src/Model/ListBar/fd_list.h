#pragma once

#include "core_list.h"
#include "core_list_item.h"

/**
 * @file fd_list_item.h
 * @class FdListItem
 * @brief 好友列表中的一项
 */
class FdListItem : public CoreListItem{
    Q_OBJECT
public:
    explicit FdListItem(std::shared_ptr<void> info, QWidget *parent = 0);
private:
    std::shared_ptr<ns::FriendInfo>m_info;
};

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

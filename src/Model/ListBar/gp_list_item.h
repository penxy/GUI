#pragma once

#include "core_list_item.h"

/**
 * @file gp_list_item.h
 * @class GpListItem
 * @brief 好友列表中的一项
 */
class GpListItem : public CoreListItem{
    Q_OBJECT
public:
    explicit GpListItem(std::shared_ptr<void> info, QWidget *parent = 0);
private:
    std::shared_ptr<ns::GroupInfo>m_info;
};

#pragma once

#include "core_list.h"

/**
 * @file gp_list.h
 * @class GpList
 * @brief 群组列表
 */
class GpList : public CoreList{
    Q_OBJECT
public:
    explicit GpList(QWidget *parent = nullptr);
    ~GpList() = default;

    /**
     * @brief 添加群
     * @param[in] group_info 群信息
     */
    void AddItem(std::shared_ptr<void>group_info) override;
    /**
     * @brief 删除群
     * @param[in] group_id 群id
     */
    void DelItem(int group_id) override;
private:
    QList<std::shared_ptr<ns::GroupInfo>>m_id_list;//用于记录下标
};
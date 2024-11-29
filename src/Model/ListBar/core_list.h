#pragma once
#include "config.h"

/**
 * @file core_list.h
 * @class CoreList
 * @brief base class for FdList and GpList
 */
class CoreList : public QWidget{
    Q_OBJECT
public:
    explicit CoreList(Type::Info::Identity identity, QWidget *parent = nullptr);
    ~CoreList() = default;
signals:
    void SigListChangeIdx(Type::Info::Identity identity, int idx);
public:
    virtual void AddItem(std::shared_ptr<void>) = 0;
    virtual void DelItem(int) = 0;
protected:
    QListWidget m_wid_list;
private:
    int m_cur_idx = -1;
    Type::Info::Identity m_identity;
};


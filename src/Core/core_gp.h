#pragma once
#include "config.h"
#include <QList>

class CoreGp{
public:
    CoreGp() = default;
    virtual ~CoreGp() = default;
    CoreGp(const CoreGp&) = default;
    CoreGp& operator=(const CoreGp&) = default;
    CoreGp(CoreGp&&) = default;
    CoreGp& operator=(CoreGp&&) = default;

    virtual bool sendGroupAction(int groupId, Type::Msg::Action action) = 0;
    virtual bool sendGroupMessage(int groupId, const QString& message) = 0;

    virtual void addGroup(std::shared_ptr<ns::GroupInfo>) = 0;
    virtual void delGroup(int idx) = 0;//以下标为准

    virtual int getGroupId(int idx) = 0;
    virtual std::string getGroupName(int idx) = 0;
    virtual QPixmap getGroupPhoto(int idx) = 0; 
protected:
    QList<std::shared_ptr<ns::GroupInfo>> m_fd_list;
};
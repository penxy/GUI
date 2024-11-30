#pragma once
#include "config.h"
#include <QList>
#include "Service/const_json.h"

#include "Chat/group.h"

class CoreGp{
public:
    CoreGp() = default;
    virtual ~CoreGp() = default;
    CoreGp(const CoreGp&) = default;
    CoreGp& operator=(const CoreGp&) = default;
    CoreGp(CoreGp&&) = default;
    CoreGp& operator=(CoreGp&&) = default;

    virtual bool sendGroup(int groupId, TypeJson::Send type_send, ...) = 0;
    virtual std::shared_ptr<Group> getGroup(int idx) = 0;

    virtual int getGroupId(int idx) = 0;
    virtual std::string getGroupName(int idx) = 0;
    virtual QPixmap getGroupPhoto(int idx) = 0; 
protected:
    QList<std::shared_ptr<Group>> m_fd_list;
};
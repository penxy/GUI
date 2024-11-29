#pragma once

#include "core_fd.h"
#include "core_gp.h"
#include "core_self.h"
#include "core_recore.h"
#include "Net/net_core.h"

class Core : public CoreFd,
             public CoreGp,
             public CoreSelf,
             public CoreRecore {
public:
    Core() = default;
    ~Core() = default;
public:
    //fd
    bool sendFriendAction(int friendId, Type::Msg::Action action) override;
    bool sendFriendMessage(int friendId, const QString& message) override;

    void addFriend(std::shared_ptr<ns::FriendInfo>) override;
    void delFriend(int idx) override;

    int getFriendId(int idx) override;
    std::string getFriendName(int idx) override;
    QPixmap getFriendPhoto(int idx) override; 
    
    //gp
    bool sendGroupAction(int groupId, Type::Msg::Action action) override;
    bool sendGroupMessage(int groupId, const QString& message) override;
    
    void addGroup(std::shared_ptr<ns::GroupInfo>) override;
    void delGroup(int idx) override;

    int getGroupId(int idx) override;
    std::string getGroupName(int idx) override;
    QPixmap getGroupPhoto(int idx) override; 

    //self
    int getId() override;
    QString getName() override;
    bool resetPass() override;
    bool resetName() override;

    //core
    void loadGroupRecore(int idx) override;
    void saveGroupRecore(int idx) override;
    void loadFriendRecore(int idx) override;
    void saveFriendRecore(int idx) override;
};

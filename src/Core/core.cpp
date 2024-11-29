#include "core.h"

// Core::Core() : CoreFd(), CoreGp(), CoreSelf(), CoreRecore(){}

//fd
bool Core::sendFriendAction(int friendId, Type::Msg::Action action){return true;}
bool Core::sendFriendMessage(int friendId, const QString& message){return true;}
void Core::addFriend(std::shared_ptr<ns::FriendInfo>){}
void Core::delFriend(int idx){}

int Core::getFriendId(int idx){return 0;}
std::string Core::getFriendName(int idx){return "";}
QPixmap Core::getFriendPhoto(int idx){return QPixmap();}

//gp
bool Core::sendGroupAction(int groupId, Type::Msg::Action action){return true;}
bool Core::sendGroupMessage(int groupId, const QString& message){return true;}
void Core::addGroup(std::shared_ptr<ns::GroupInfo>){}
void Core::delGroup(int idx){}

int Core::getGroupId(int idx){return 0;}
std::string Core::getGroupName(int idx){return "";}
QPixmap Core::getGroupPhoto(int idx){return QPixmap();}

//self
int Core::getId(){return 0;}
QString Core::getName(){return "";}
bool Core::resetPass(){return true;}
bool Core::resetName(){return true;}

//core
void Core::loadGroupRecore(int idx){}
void Core::saveGroupRecore(int idx){}
void Core::loadFriendRecore(int idx){}
void Core::saveFriendRecore(int idx){}


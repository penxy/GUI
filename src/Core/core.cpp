#include "core.h"

//fd
bool Core::sendFriend(int friendId, TypeJson::Send type_send, ...){return true;}
std::shared_ptr<Friend> Core::getFriend(int idx){return nullptr;}

int Core::getFriendId(int idx){return 0;}
std::string Core::getFriendName(int idx){return "";}
QPixmap Core::getFriendPhoto(int idx){return QPixmap();}
//gp
bool Core::sendGroup(int groupId, TypeJson::Send type_send, ...){return true;}
std::shared_ptr<Group> Core::getGroup(int idx){return nullptr;}

int Core::getGroupId(int idx){return 0;}
std::string Core::getGroupName(int idx){return "";}
QPixmap Core::getGroupPhoto(int idx){return QPixmap();}
//self
bool Core::setPass(){return true;}
bool Core::setName(){return true;}
void setStatus(){}

int Core::getId(){return 0;}
QString Core::getName(){return "";}
Type::Status getStatus(){return Type::Status::Online;}

//Recore
void Core::loadGroupRecore(int idx){}
void Core::saveGroupRecore(int idx){}
void Core::loadFriendRecore(int idx){}
void Core::saveFriendRecore(int idx){}


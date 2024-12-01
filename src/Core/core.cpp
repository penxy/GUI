#include "core.h"

Core::Core(std::shared_ptr<Protocol>protocol) : QObject(), CoreFd(), CoreGp(), CoreSelf(), CoreRecore(), m_protocol(protocol){

}

//fd
bool Core::sendFriend(int friendId, TypeJson::Send type_send, ...){return true;}
std::shared_ptr<Friend>& Core::getFriend(int idx){auto _f = std::make_shared<Friend>(); return _f;}
QList<std::shared_ptr<Friend>>& Core::getFriendList(){QList<std::shared_ptr<Friend>> _f;return _f;}

ChatId& Core::getFriendId(int idx){ChatId id = ChatId();return id;}
std::string& Core::getFriendName(int idx){std::string s;return s;}
QPixmap& Core::getFriendPhoto(int idx){QPixmap p;return p;}
//gp
bool Core::sendGroup(int groupId, TypeJson::Send type_send, ...){return true;}
std::shared_ptr<Group>& Core::getGroup(int idx){auto _f = std::make_shared<Group>(); return _f;}
QList<std::shared_ptr<Group>>& Core::getGroupList(){QList<std::shared_ptr<Group>> _f;return _f;}

ChatId& Core::getGroupId(int idx){ChatId id = ChatId();return id;}
std::string& Core::getGroupName(int idx){std::string s;return s;}
QPixmap& Core::getGroupPhoto(int idx){QPixmap p;return p;}
//self
bool Core::setPass(const QString& pass){return true;}
bool Core::setName(const QString& name){return true;}
bool Core::setStatus(const Type::Status& status){}

ChatId& Core::getId(){return m_id;}
QString& Core::getName(){return m_name; }
Type::Status& Core::getStatus(){return m_status;}//? why m_status not define?

//Recore
void Core::loadGroupRecore(int idx){}
void Core::saveGroupRecore(int idx){}
void Core::loadFriendRecore(int idx){}
void Core::saveFriendRecore(int idx){}


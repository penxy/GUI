#ifndef __CONFIG_STRUCT_H__
#define __CONFIG_STRUCT_H__


#include <QPixmap>
#include <QList>
#include <memory>
#include <time.h>
#include "cjson/cJSON.h"
#include "config_enum.h"



struct PersonInfo{
    int id;
    std::string name;
    std::string photo;
};

struct GroupInfo{
    int id;
    std::string name;
    std::string photo;
    QList<std::shared_ptr<std::pair<PersonInfo, E_Role>>> members;
};

struct MsgInfo{
    int id;
    std::string content;
    std::string photo; // 发送者头像
    time_t time;
    E_Message type;
    E_Direction direction; // 发送者还是接收者
};


#endif // __CONFIG_STRUCT_H__
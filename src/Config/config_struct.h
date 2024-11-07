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
    QPixmap photo;
};

struct GroupInfo{
    int id;
    std::string name;
    QPixmap photo;
    QList<std::shared_ptr<std::pair<PersonInfo, E_Role>>> members;
};

typedef struct{
    time_t time;
    E_Message type;
    std::string content;
    E_Direction direction; // 发送者还是接收者
}msg_info_t;

struct MsgInfo{
    int id;
    E_Identity identity;

    //E_Identity::Group
    int gid = -1;
    E_Role role;

    msg_info_t msg_info;
};


#endif // __CONFIG_STRUCT_H__
#ifndef __CONFIG_STRUCT_H__
#define __CONFIG_STRUCT_H__


#include <QPixmap>
#include <QList>
#include <memory>
#include "cjson/cJSON.h"
#include "config_enum.h"

typedef enum{
    Owner = 0,
    Admin = 1,
    Member = 2
}E_Role;



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




#endif // __CONFIG_STRUCT_H__
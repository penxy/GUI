#pragma once

#include "config.h"

/**
 * @class CoreSelf
 * @brief 个人信息保存与修改
 */
class CoreSelf{
public:
    CoreSelf() = default;
    virtual ~CoreSelf() = default;
    CoreSelf(const CoreSelf&) = default;
    CoreSelf& operator=(const CoreSelf&) = default;
    CoreSelf(CoreSelf&&) = default;
    CoreSelf& operator=(CoreSelf&&) = default;

    virtual int getId() = 0;
    virtual QString getName() = 0;
    virtual bool setPass() = 0;
    virtual bool setName() = 0;
    virtual bool setStatus() = 0;
    virtual Type::Status getStatus() = 0;
protected:
    int id;
    QString name;
    QString pass;
    Type::Status status;
};
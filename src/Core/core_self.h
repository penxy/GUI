#pragma once

#include <QString>
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
    virtual bool resetPass() = 0;
    virtual bool resetName() = 0;
protected:
    int id;
    QString name;
    QString pass;
};
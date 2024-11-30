#pragma once

#include <QObject>
#include <QPixmap>
#include "chatid.h"
#include "utils/interface.h"

class Chat : public QObject
{
    Q_OBJECT
public:
    virtual ~Chat() = 0;

    virtual void setName(const QString& name) = 0;
    virtual QString getName() const = 0;

    virtual ChatId getId() const = 0;

    virtual void setPix(const QPixmap& pix) = 0;
    virtual QPixmap getPix() const = 0;

    DECLARE_SIGNAL(SigNameChanged, const QString&);
    DECLARE_SIGNAL(SigPixChanged, const QPixmap&);
};

#pragma once

#include "chat.h"

#include <memory>
#include <QPixmap>

/**
 * @file friend.h
 * @class Friend
 */
class Friend : public Chat, public std::enable_shared_from_this<Friend>{
    Q_OBJECT 
public:
    Friend(const ChatId& id, const QString& pix_base64, const QString& name);
    Friend(const Friend& other);
    Friend& operator=(const Friend& other);

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY SigNameChanged FINAL);
    Q_PROPERTY(QPixmap pix READ getPix WRITE setPix NOTIFY SigPixChanged FINAL);

    SIGNAL_IMPL(Friend, SigNameChanged, const QString&);
    SIGNAL_IMPL(Friend, SigPixChanged, const QPixmap&);
public:
    ChatId getId() const override;

    void setName(const QString& name) override;
    QString getName() const override;

    void setPix(const QPixmap& pix) override;
    QPixmap getPix() const override;
private:
    template <typename T> bool setVal(T& savedVal, T newVal);
private:
    ChatId                      m_id;
    QString                     m_name;
    QPixmap                     m_pix;
};
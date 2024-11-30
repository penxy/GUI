#pragma once


#include <QString>
#include <QByteArray>
#include <memory>

class ChatId{
public:
    ChatId() = default;
    ChatId(const QByteArray &id);
    ChatId& operator = (const ChatId &other);

    bool operator == (const ChatId& other) const;
    bool operator != (const ChatId& other) const;
    bool operator < (const ChatId& other) const;    

    QString toString() const;
    QByteArray getByteArray() const;
    std::unique_ptr<ChatId> clone();
private:
    QByteArray m_id;
};
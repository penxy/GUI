#pragma once

#include <QDialog>
#include "config.h"
#include <memory>

class Card : public QDialog {
    Q_OBJECT
public:
    explicit Card(Type::Info::Identity identity, std::shared_ptr<void>info, QWidget *parent = nullptr);
    // virtual void SetInfo(std::shared_ptr<void> info) = 0;
signals:
    void SigAdd(Type::Info::Identity identity, int id);
protected:
    QPixmap m_photo;
private:
    Type::Info::Identity m_identity;
};

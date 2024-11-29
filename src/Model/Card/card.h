#pragma once

#include <QDialog>
#include "config.h"

class Card : public QDialog {
    Q_OBJECT
public:
    explicit Card(Type::Info::Identity identity, std::shared_ptr<void>info, QWidget *parent = nullptr);
    // virtual void SetInfo(std::shared_ptr<void> info) = 0;
signals:
    void SigAdd(Type::Info::Identity identity, int id);
protected:
    QLabel m_lab_id;
    QLabel m_lab_name;
    QPixmap m_photo;
    LabelPhoto m_lab_photo;
private:
    Type::Info::Identity m_identity;
    QPushButton m_btn_add;
};

#include "card.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <memory>

#include "Base/label_photo.h"
#include "utils/tool.h"

Card::Card(Type::Info::Identity identity, std::shared_ptr<void>info, QWidget *parent) : QDialog(parent), m_identity(identity) {
    QLabel *m_lab_id = new QLabel(this);
    QLabel *m_lab_name = new QLabel(this);
    QPushButton *m_btn_add = new QPushButton(this);
    LabelPhoto *m_lab_photo = new LabelPhoto(this);

    if(m_identity == Type::Info::Identity::Friend){
        std::shared_ptr<ns::FriendInfo>m_info = std::static_pointer_cast<ns::FriendInfo>(info);
        m_lab_id->setText(QString::number(m_info.get()->id));
        m_lab_name->setText(QString::fromStdString(m_info.get()->name));
        m_lab_photo->SetPhoto(m_info.get()->photo);
    }else {
        std::shared_ptr<ns::GroupInfo>m_info = std::static_pointer_cast<ns::GroupInfo>(info);
        m_lab_id->setText(QString::number(m_info.get()->id));
        m_lab_name->setText(QString::fromStdString(m_info.get()->name));
        m_lab_photo->SetPhoto(m_info.get()->photo);
    }
    m_btn_add->setText("Add");

    m_lab_photo->setFixedSize(sz::card_photo);
    m_lab_id->setFixedSize(sz::card_id);
    m_lab_name->setFixedSize(sz::card_name);
    m_btn_add->setFixedSize(sz::card_btn);
    this->setFixedSize(sz::dialog_wid);

    QHBoxLayout *layout_photo = new QHBoxLayout;
    layout_photo->addWidget(m_lab_photo);
    QVBoxLayout *layout_info = new QVBoxLayout;
    layout_info->addWidget(m_lab_id);
    layout_info->addWidget(m_lab_name);
    QHBoxLayout *layout_info_main = new QHBoxLayout;
    layout_info_main->setSpacing(40);
    layout_info_main->setContentsMargins(0, 0, 0, 0);
    layout_info_main->setAlignment(Qt::AlignLeft);
    layout_info_main->addLayout(layout_photo);
    layout_info_main->addLayout(layout_info);
    QHBoxLayout *layout_btn = new QHBoxLayout;
    layout_btn->addWidget(m_btn_add);
    layout_btn->setAlignment(Qt::AlignRight);
    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->addLayout(layout_info_main);
    layout_main->addLayout(layout_btn);

    this->setStyleSheet(TOOL.getQss(Tool::TypeQss::Label));

    connect(m_btn_add, &QPushButton::clicked, this, [&](){
        __DELAY__;
        
        m_btn_add->setEnabled(false);
        emit SigAdd(m_identity, m_lab_id->text().toInt());
    });
}
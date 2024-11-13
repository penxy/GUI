#include "widget_talk_top.h"

WidgetTalkTop::WidgetTalkTop(E_Identity type, std::shared_ptr<void> info, QWidget *parent) : QWidget(parent){
    {
        m_photo = new QPixmap();
        if(type == E_Identity::Friend){
            std::shared_ptr<PersonInfo> m_info = std::static_pointer_cast<PersonInfo>(info);
            m_photo = &m_info.get()->photo;
            m_lab_name = new QLabel(QString::fromStdString(m_info.get()->name), this);
        }else{
            std::shared_ptr<GroupInfo> m_info = std::static_pointer_cast<GroupInfo>(info);
            m_photo = &m_info.get()->photo;
            m_lab_name = new QLabel(QString::fromStdString(m_info.get()->name), this);
        }
        m_lab_photo = new LabelPhoto(m_photo, this);
    }
    {
        m_lab_name->setFixedSize(CONST_SIZE_LAB_TALK_TOP);
        m_lab_photo->setFixedSize(CONST_SIZE_PHOTO_TALK_TOP);
        this->setFixedSize(CONST_SIZE_WIDGET_TALK_TOP);
    }
    {
        WidgetBlank *widget_photo = new WidgetBlank(this);
        QHBoxLayout *layout_photo = new QHBoxLayout(widget_photo);
        layout_photo->addWidget(m_lab_photo);

        WidgetBlank *widget_name = new WidgetBlank(this);
        QHBoxLayout *layout_name = new QHBoxLayout(widget_name);
        layout_name->addWidget(m_lab_name);

        QBoxLayout *layout_main = new QBoxLayout(QBoxLayout::LeftToRight, this);
        layout_main->setAlignment(Qt::AlignLeft);
        layout_main->addWidget(widget_photo);
        layout_main->setSpacing(10);
        layout_main->addWidget(widget_name);
    }
    {
        QString qss = QString(R"(
            QLabel {
                font-family: "Microsoft YaHei";
                font-size: 12px;
                font-style: italic;
                font-weight: bold;
                color: rgb(66, 245, 120);
                font: bold italic 18px "Microsoft YaHei";
            }
        )");
        this->setStyleSheet(qss);
    }
}
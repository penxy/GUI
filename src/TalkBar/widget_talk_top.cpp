#include "widget_talk_top.h"

WidgetTalkTop::WidgetTalkTop(const GroupInfo &info, QWidget *parent) : QWidget(parent){
    {
        m_photo = new QPixmap();
        *m_photo = info.photo;

        m_lab_photo = new LabelPhoto(m_photo, this);
        m_lab_name = new QLabel(QString::fromStdString(info.name), this);
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

        QHBoxLayout *layout_main = new QHBoxLayout(this);
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
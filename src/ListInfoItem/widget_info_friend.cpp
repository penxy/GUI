#include "widget_info_friend.h"
#include <QBitmap>
#include <QPainter>

WidgetInfoFriend::WidgetInfoFriend(PersonInfo&& info, QWidget *parent) : QWidget(parent){
    {
        m_photo = new QPixmap();
        m_photo->loadFromData(QByteArray::fromBase64(QString::fromStdString(info.photo).toLocal8Bit()));
 
        m_lab_photo = new LabelPhoto(m_photo, this);
        m_lab_name = new QLabel(this);
        m_lab_id = new QLabel(this);
    }
    {
        m_lab_id->setText(QString::number(info.id));
        m_lab_id->setToolTip("id");
        m_lab_name->setText(QString::fromStdString(info.name));
        m_lab_name->setToolTip("name");
    }
    {
        m_lab_photo->setFixedSize(CONST_SIZE_PHOTO_INFO_FRIEND);
        m_lab_id->setFixedSize(CONST_SIZE_ID_INFO_FRIEND);
        m_lab_name->setFixedSize(CONST_SIZE_NAME_INFO_FRIEND);
        this->setFixedSize(CONST_SIZE_WIDGET_INFO_FRIEND);
    }
    {
        WidgetBlank* widget_photo = new WidgetBlank(this);
        QVBoxLayout* layout_photo = new QVBoxLayout(widget_photo);
        layout_photo->addWidget(m_lab_photo);

        WidgetBlank* widget_id_name = new WidgetBlank(this);
        QVBoxLayout* layout_id_name = new QVBoxLayout(widget_id_name);
        layout_id_name->addWidget(m_lab_id);
        layout_id_name->setSpacing(5);
        layout_id_name->addWidget(m_lab_name);

        QHBoxLayout* layout_main = new QHBoxLayout(this);
        layout_main->addWidget(widget_photo);
        layout_main->addWidget(widget_id_name);
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

int WidgetInfoFriend::GetId() const{
    return m_lab_id->text().toInt();
}

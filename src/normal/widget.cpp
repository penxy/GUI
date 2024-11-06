#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QAction>
#include <QLabel>
#include <iostream>
#include <QImage>
#include <QBuffer>
#include <QDebug>
#include <QPainter>
#include <QDateTime>

#include "Base/widget_blank.h"
#include "Config/config.h"

QString imageToBase64(const QString &imagePath) {
    QImage image(imagePath);
    // 将 QImage 转换为字节数组
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    image.save(&buffer, "PNG"); // 保存为 PNG 格式，也可以选择其他格式
    // 将字节数组编码为 Base64
    QString base64String = byteArray.toBase64();
    return base64String;
}

Widget::Widget(QWidget *parent) : QWidget(parent){
    m_list_widget = new QListWidget(this);
    m_btn = new QPushButton("发送", this);
    m_edit = new QLineEdit(this);
    connect(m_btn, &QPushButton::clicked, this, &Widget::on_pushButton_clicked);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_list_widget);
    layout->addWidget(m_edit);
    layout->addWidget(m_btn);
    setLayout(layout);
}



void Widget::dealMessageTime(QString curMsgTime)
{
    bool isShowTime = false;
    if(m_list_widget->count() > 0) {
        QListWidgetItem* lastItem = m_list_widget->item(m_list_widget->count() - 1);
        lastItem->setFlags(lastItem->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);

        WidgetMsg* messageW = (WidgetMsg*)m_list_widget->itemWidget(lastItem);
        int lastTime = messageW->time().toInt();
        int curTime = curMsgTime.toInt();
        qDebug() << "curTime lastTime:" << curTime - lastTime;
        isShowTime = ((curTime - lastTime) > 60); // 两个消息相差一分钟
    } else {
        isShowTime = true;
    }
    if(isShowTime) {
        WidgetMsg* messageTime = new WidgetMsg(m_list_widget->parentWidget());
        QListWidgetItem* itemTime = new QListWidgetItem(m_list_widget);
        itemTime->setFlags(itemTime->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);


        QSize size = QSize(this->width(), 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, curMsgTime, size, WidgetMsg::User_Time);
        m_list_widget->setItemWidget(itemTime, messageTime);
    }
}

void Widget::resizeEvent(QResizeEvent *event){
    Q_UNUSED(event);
    for(int i = 0; i < m_list_widget->count(); i++) {
        WidgetMsg* messageW = (WidgetMsg*)m_list_widget->itemWidget(m_list_widget->item(i));
        QListWidgetItem* item = m_list_widget->item(i);

        dealMessage(messageW, item, messageW->text(), messageW->time(), messageW->userType());
    }
}

void Widget::dealMessage(WidgetMsg *messageW, QListWidgetItem *item, QString text, QString time,  WidgetMsg::User_Type type)
{
    messageW->setFixedWidth(this->width());
    QSize size = messageW->fontRect(text);
    item->setSizeHint(size);
    messageW->setText(text, time, size, type);
    m_list_widget->setItemWidget(item, messageW);
}



void Widget::on_pushButton_clicked()
{
    QString msg = m_edit->text();
    m_edit->clear();
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
    bool isSending = false; // 发送中

    dealMessageTime(time);
    m_widget_msg_vec.push_back(new WidgetMsg(m_list_widget->parentWidget()));
    QListWidgetItem* item = new QListWidgetItem(m_list_widget);
    dealMessage(m_widget_msg_vec.back(), item, msg, time, WidgetMsg::User_Me);
    if(isSending == true) {
        m_widget_msg_vec.back()->setTextSuccess();
    }
}
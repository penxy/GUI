#include "widget_talk_mid.h"
#include <QDateTime>
/*
dealMessageTime(time);
WidgetMsg* messageW = new WidgetMsg(m_list_widget->parentWidget());
QListWidgetItem* item = new QListWidgetItem(m_list_widget);
dealMessage(messageW, item, msg, time, WidgetMsg::User_She);
*/

WidgetTalkMid::WidgetTalkMid(QWidget *parent) : QWidget(parent){
    m_list_widget = new QListWidget(this);
    this->resize(CONST_SIZE_BASE_WIDGET_TALK_MID);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_list_widget);
}


void WidgetTalkMid::dealMessageTime(QString curMsgTime)
{
    bool isShowTime = false;
    if(m_list_widget->count() > 0) {
        QListWidgetItem* lastItem = m_list_widget->item(m_list_widget->count() - 1);
        WidgetMsg* messageW = (WidgetMsg*)m_list_widget->itemWidget(lastItem);
        int lastTime = messageW->time().toInt();
        int curTime = curMsgTime.toInt();
        isShowTime = ((curTime - lastTime) > 60); // 两个消息相差一分钟
    } else {
        isShowTime = true;
    }
    if(isShowTime) {
        WidgetMsg* messageTime = new WidgetMsg(m_list_widget->parentWidget());
        QListWidgetItem* itemTime = new QListWidgetItem(m_list_widget);

        QSize size = QSize(this->width(), 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, curMsgTime, size, WidgetMsg::User_Time);
        m_list_widget->setItemWidget(itemTime, messageTime);
    }
}

void WidgetTalkMid::dealMessage(WidgetMsg *messageW, QListWidgetItem *item, QString text, QString time,  WidgetMsg::User_Type type)
{
    messageW->setFixedWidth(this->width());
    QSize size = messageW->fontRect(text);
    item->setSizeHint(size);
    messageW->setText(text, time, size, type);
    m_list_widget->setItemWidget(item, messageW);
}



// void Widget::on_pushButton_clicked()
// {
//     QString msg = m_edit->text();
//     m_edit->clear();
//     QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
//     bool isSending = false; // 发送中

//     dealMessageTime(time);
//     m_widget_msg_vec.push_back(new WidgetMsg(m_list_widget->parentWidget()));
//     QListWidgetItem* item = new QListWidgetItem(m_list_widget);
//     dealMessage(m_widget_msg_vec.back(), item, msg, time, WidgetMsg::User_Me);
//     if(isSending == true) {
//         m_widget_msg_vec.back()->setTextSuccess();
//     }
// }

void WidgetTalkMid::resizeEvent(QResizeEvent *event){
    Q_UNUSED(event);
    for(int i = 0; i < m_list_widget->count(); i++) {
        WidgetMsg* messageW = (WidgetMsg*)m_list_widget->itemWidget(m_list_widget->item(i));
        QListWidgetItem* item = m_list_widget->item(i);
        dealMessage(messageW, item, messageW->text(), messageW->time(), messageW->userType());
    }
}


void WidgetTalkMid::SlotMessageSend(E_Message type, const QString &msg){
    QString time = QString::number(QDateTime::currentDateTime().toTime_t());
    bool isSending = false; // 发送中

    dealMessageTime(time);
    m_widget_msg_vec.push_back(new WidgetMsg(m_list_widget->parentWidget()));
    QListWidgetItem* item = new QListWidgetItem(m_list_widget);
    dealMessage(m_widget_msg_vec.back(), item, msg, time, WidgetMsg::User_Me);
    if(isSending == true) {
        m_widget_msg_vec.back()->setTextSuccess();
    }
}
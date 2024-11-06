#include "widget_talk_mid.h"

WidgetTalkMid::WidgetTalkMid(QWidget *parent) : QWidget(parent){

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



// void WidgetTalkMid::on_pushButton_clicked()
// {
//     QString msg = m_edit->text();
//     m_edit->clear();
//     QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
//     bool isSending = true; // 发送中

//     qDebug()<<"addMessage" << msg << time << m_list_widget->count();
//     if(m_list_widget->count()%2) {
//         if(isSending) {
//             dealMessageTime(time);

//             WidgetMsg* messageW = new WidgetMsg(m_list_widget->parentWidget());
//             QListWidgetItem* item = new QListWidgetItem(m_list_widget);
//             dealMessage(messageW, item, msg, time, WidgetMsg::User_Me);
//         } else {
//             bool isOver = true;
//             for(int i = m_list_widget->count() - 1; i > 0; i--) {
//                 WidgetMsg* messageW = (WidgetMsg*)m_list_widget->itemWidget(m_list_widget->item(i));
//                 if(messageW->text() == msg) {
//                     isOver = false;
//                     messageW->setTextSuccess();
//                 }
//             }
//             if(isOver) {
//                 dealMessageTime(time);

//                 WidgetMsg* messageW = new WidgetMsg(m_list_widget->parentWidget());
//                 QListWidgetItem* item = new QListWidgetItem(m_list_widget);
//                 dealMessage(messageW, item, msg, time, WidgetMsg::User_Me);
//                 messageW->setTextSuccess();
//             }
//         }
//     } else {
//         if(msg != "") {
//             dealMessageTime(time);
//             WidgetMsg* messageW = new WidgetMsg(m_list_widget->parentWidget());
//             QListWidgetItem* item = new QListWidgetItem(m_list_widget);
//             dealMessage(messageW, item, msg, time, WidgetMsg::User_She);
//         }
//     }
// }



void WidgetTalkMid::resizeEvent(QResizeEvent *event){
    Q_UNUSED(event);
    // ui->textEdit->resize(this->width() - 20, ui->widget->height() - 20);
    // ui->textEdit->move(10, 10);

    // ui->pushButton->move(ui->textEdit->width()+ui->textEdit->x() - ui->pushButton->width() - 10,
    //                      ui->textEdit->height()+ui->textEdit->y() - ui->pushButton->height() - 10);
    for(int i = 0; i < m_list_widget->count(); i++) {
        WidgetMsg* messageW = (WidgetMsg*)m_list_widget->itemWidget(m_list_widget->item(i));
        QListWidgetItem* item = m_list_widget->item(i);

        dealMessage(messageW, item, messageW->text(), messageW->time(), messageW->userType());
    }
}

/*

dealMessageTime(time);
WidgetMsg* messageW = new WidgetMsg(m_list_widget->parentWidget());
QListWidgetItem* item = new QListWidgetItem(m_list_widget);
dealMessage(messageW, item, msg, time, WidgetMsg::User_She);

*/
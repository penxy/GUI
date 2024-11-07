#ifndef __WIDGET_TALK_MID_H__
#define __WIDGET_TALK_MID_H__

#include "Config/config.h"
#include <QListWidget>
#include "TalkBar/bubble/widget_msg.h"
#include <vector>

class WidgetTalkMid : public QWidget{
    Q_OBJECT
public:
    explicit WidgetTalkMid(QWidget *parent = nullptr);

private:
    void dealMessageTime(QString curMsgTime);
    void dealMessage(WidgetMsg *messageW, QListWidgetItem *item, QString text, QString time,  WidgetMsg::User_Type type);
//     void on_pushButton_clicked();
public slots:
    void SlotMessageSend(E_Message type, const QString &msg);
//     void SlotMessageSendSuccess(int index);
//     void SlotMessageRecv(MsgInfo *msg_info);
protected:
    void resizeEvent(QResizeEvent *);
private:
    QListWidget *m_list_widget;
    std::vector<WidgetMsg*>m_widget_msg_vec;//不需要手动析构
};


#endif // __WIDGET_TALK_MID_H__
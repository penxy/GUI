#ifndef __WIDGET_TALK_MID_H__
#define __WIDGET_TALK_MID_H__

#include "Config/config.h"
#include <QListWidget>
#include "bubble/widget_msg.h"
#include <vector>

class WidgetTalkMid : public QWidget{
    Q_OBJECT
public:
    explicit WidgetTalkMid(QWidget *parent = nullptr);

private:
    void dealMessageTime(QString curMsgTime);
    void dealMessage(WidgetMsg *messageW, QListWidgetItem *item, QString text, QString time,  WidgetMsg::User_Type type);
//     void on_pushButton_clicked();
// public slots:
//     void SlotMessageAppend(MsgInfo *msg_info);
//     void SlotMessageSendSuccess(int index);
protected:
    void resizeEvent(QResizeEvent *);
private:
    QListWidget *m_list_widget;
    std::vector<WidgetMsg*>m_widget_msg_vec;
};


#endif // __WIDGET_TALK_MID_H__
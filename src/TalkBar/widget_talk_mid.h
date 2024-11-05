#ifndef __WIDGET_TALK_MID_H__
#define __WIDGET_TALK_MID_H__

#include "Config/config.h"
#include <QListWidget>

class WidgetTalkMid : public QWidget{
    Q_OBJECT
public:
    explicit WidgetTalkMid(QWidget *parent = nullptr);
// public slots:
//     void SlotMessageAppend(MsgInfo *msg_info);
private:
    QListWidget *m_list_widget;
};


#endif // __WIDGET_TALK_MID_H__
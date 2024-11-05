#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <QWidget>
#include <QListWidget>
#include <QEvent>
#include "ListBar/widget_list_friend.h"
#include "Base/label_role.h"
#include "TalkBar/bubble/label_msg.h"


class Widget : public QWidget{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    //void paintEvent(QPaintEvent *);
private:
    LabelMsg *test;
};





#endif // __WIDGET_H__
#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <QWidget>
#include <QListWidget>
#include <QEvent>
#include <vector>

#include "TalkBar/widget_talk_window.h"

class Widget : public QWidget{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
private:
    WidgetTalkWindow *m_talk_window;
};





#endif // __WIDGET_H__
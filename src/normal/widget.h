#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <QWidget>
#include <QListWidget>
#include <QEvent>
#include <vector>

#include "TalkBar/widget_talk_window.h"
#include "RightPage/widget_right.h"
#include "MainPage/widget_main.h"

class Widget : public QWidget{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
};


#endif // __WIDGET_H__
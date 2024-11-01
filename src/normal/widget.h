#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <QWidget>
#include <QListWidget>
#include "Search/dialog_search.h"


class Widget : public QWidget{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
private:
    QListWidget *m_list_widget;
    DialogSearch *dialog;
    QPushButton *btn;
};





#endif // __WIDGET_H__
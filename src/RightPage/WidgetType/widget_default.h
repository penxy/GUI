#ifndef __WIDGET_DEFAULT_H
#define __WIDGET_DEFAULT_H

#include <QWidget>

class WidgetDefault : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetDefault(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // __WIDGET_DEFAULT_H

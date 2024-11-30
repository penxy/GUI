#pragma once


#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>

class WidBase : public QMainWindow{
    Q_OBJECT
public:
    WidBase(QMainWindow *parent = nullptr);
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    bool mouse_press;
    QPoint mousePoint;
};



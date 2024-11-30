#include "main_wid.h"
#include "widget.h"

MainWid::MainWid(QMainWindow *parent) : WidBase(parent){
    this->setWindowFlags(Qt::FramelessWindowHint);

    Widget *m_main_wid = new Widget(this);
    this->setCentralWidget(m_main_wid);
}

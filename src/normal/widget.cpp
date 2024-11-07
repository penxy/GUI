#include "widget.h"
#include <QAction>
#include <QImage>
#include <QBuffer>
#include <QPainter>
#include <QDateTime>

#include "Config/config.h"

Widget::Widget(QWidget *parent) : QWidget(parent){
    PersonInfo *info = new PersonInfo;
    info->name = "test";
    info->photo = QPixmap(":/Icons/MainWindow/emoji2.png");
    m_talk_window = new WidgetTalkWindow(E_Identity::Friend, (void*)info, this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_talk_window);
}
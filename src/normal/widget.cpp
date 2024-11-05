#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QAction>
#include <QLabel>
#include <iostream>
#include <QImage>
#include <QBuffer>
#include <QDebug>
#include <QPainter>

#include "Base/widget_blank.h"
#include "Config/config.h"

QString imageToBase64(const QString &imagePath) {
    QImage image(imagePath);
    // 将 QImage 转换为字节数组
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    image.save(&buffer, "PNG"); // 保存为 PNG 格式，也可以选择其他格式
    // 将字节数组编码为 Base64
    QString base64String = byteArray.toBase64();
    return base64String;
}

Widget::Widget(QWidget *parent) : QWidget(parent){
    // PersonInfo info;
    // info.id = 1;
    // info.name = "张三";
    // info.photo = imageToBase64(":/Icons/MainWindow/contact3.png").toStdString();
    // //m_friend = new WidgetInfoFriend(std::move(info), this);
    // m_friend_list = new WidgetListFriend(this);
    // m_friend_list->addFriendInfo(std::move(info));
    // PersonInfo info2;
    // info2.id = 2;
    // info2.name = "李四";
    // info2.photo = imageToBase64(":/Icons/MainWindow/contact2.png").toStdString();
    // m_friend_list->addFriendInfo(std::move(info2));

    // PersonInfo info3;
    // info3.id = 3;
    // info3.name = "王五";
    // info3.photo = imageToBase64(":/Icons/MainWindow/contact.png").toStdString();
    // m_friend_list->addFriendInfo(std::move(info3));



    // QVBoxLayout *layout = new QVBoxLayout(this);
    // layout->addWidget(m_friend_list);
    // resize(500, 500);


    test = new LabelMsg(E_Direction::Send, "afssafalsjfgiasfgiafjiasjfijafssafalsjfgiasfgiafjiasjfijasifsaifasifdjsaidaisdasafssafalsjfgiasfgiafjiasjfijasifjsaifasifdjsaidaisdasafssafalsjfgiasfgiafjiasjfijasifjsaifasifdjsaidaisdasafssafalsjfgiasfgiafjiasjfijasifjsaifasifdjsaidaisdasasifjsaifasifdjsaidaisdas" ,this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    //QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    layout->addWidget(test);
}


// void Widget::paintEvent(QPaintEvent *) {
//     QPainter painter(this);
//     painter.setRenderHint(QPainter::Antialiasing); // 设置抗锯齿

//     // 创建一个多边形
//     QPolygon polygon;
//     polygon << QPoint(20, 20) << QPoint(10, 25) << QPoint(20, 30) << QPoint(20, 100) << QPoint(100, 100) << QPoint(100, 20);

//     // 设置笔和刷子
//     painter.setPen(QPen(Qt::blue, 2)); // 设置蓝色笔，宽度为2
//     painter.setBrush(QBrush(QColor(29, 177, 194))); // 设置黄色刷子

//     // 绘制多边形
//     painter.drawPolygon(polygon);

//     // 绘制多边形的边界
//     painter.setPen(QPen(Qt::red, 1)); // 设置红色笔，宽度为1
//     painter.drawPolyline(polygon.data(), polygon.size());
// }
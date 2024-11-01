#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QAction>
#include <QLabel>
#include <iostream>
#include <QImage>
#include <QBuffer>
#include <QDebug>
/*
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
*/

Widget::Widget(QWidget *parent) : QWidget(parent){
    
}
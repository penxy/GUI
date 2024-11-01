#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QAction>
#include <QLabel>
#include <iostream>
#include <QImage>
#include <QBuffer>
#include <QDebug>


Widget::Widget(QWidget *parent) : QWidget(parent){
    resize(400, 600);
    dialog = new DialogSearch(this);

    connect(dialog, &DialogSearch::SendSearch, this, &Widget::Search);
    connect(this, &Widget::Send2SearchGroup, dialog, &DialogSearch::slot_recv_search);
    
    btn = new QPushButton("搜索", this);
    connect(btn, &QPushButton::clicked, this, [&](){
        dialog->show();
    });

    btn->click();
}
/*
"name":"xxx",
    "photo":"xxx",//base64
    "members":[
        {
            "id":"xxx",
            "name":"xxx",
            "role":"xxx",
            "photo":"xxx",//base64
        },
        {
            "id":"xxx",
            "name":"xxx",
            "role":"xxx",
            "photo":"xxx",//base64
        },
    ]
*/
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

void Widget::Search(cJSON *json){
    std::cout << cJSON_Print(json) << std::endl;
    cJSON_Delete(json);

    //TODO
    QString base64_str = imageToBase64(":/Icons/MainWindow/admin.png");

    cJSON *root = cJSON_CreateObject();
    cJSON_AddNumberToObject(root, "id", 1);
    cJSON_AddStringToObject(root, "name", "群名null");
    cJSON_AddStringToObject(root, "photo", base64_str.toStdString().c_str());

    cJSON *items = cJSON_CreateArray();
    cJSON *item1 = cJSON_CreateObject();
    cJSON_AddNumberToObject(item1, "id", 11);
    cJSON_AddStringToObject(item1, "name", "张三");
    cJSON_AddNumberToObject(item1, "role", 1);
    cJSON_AddStringToObject(item1, "photo", base64_str.toStdString().c_str());
    cJSON_AddItemToArray(items, item1);

    cJSON *item2 = cJSON_CreateObject();
    cJSON_AddNumberToObject(item2, "id", 12);
    cJSON_AddStringToObject(item2, "name", "李四");
    cJSON_AddNumberToObject(item2, "role", 0);
    cJSON_AddStringToObject(item2, "photo", base64_str.toStdString().c_str());
    cJSON_AddItemToArray(items, item2);

    cJSON_AddItemToObject(root, "members", items);
    emit Send2SearchGroup(root);
}
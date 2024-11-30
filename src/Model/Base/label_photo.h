#pragma once

#include <QLabel>
/**
 * @file label_photo.h
 * @class LabelPhoto
 * @brief 用于显示图片的标签类
 */
class LabelPhoto : public QLabel{
    Q_OBJECT
public:
    explicit LabelPhoto(QWidget *parent = 0);
    void SetPhoto(QPixmap photo);
};



#pragma once

#include <QLabel>

class LabelPhoto : public QLabel{
    Q_OBJECT
public:
    explicit LabelPhoto(QWidget *parent = 0);
    void SetPhoto(QPixmap photo);
};



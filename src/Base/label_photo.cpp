#include "label_photo.h"

LabelPhoto::LabelPhoto(QPixmap photo, QWidget *parent) : QLabel(parent){
    setPixmap(photo);
    setScaledContents(true);
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QString qss = QString(R"(
        QLabel {
            border: 2px solid #8f8f91;
        }
    )");
    setStyleSheet(qss);
}
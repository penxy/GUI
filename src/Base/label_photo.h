#ifndef __LABEL_PHOTO_H__
#define __LABEL_PHOTO_H__

#include <QLabel>

class LabelPhoto : public QLabel{
    Q_OBJECT
public:
    explicit LabelPhoto(QPixmap photo, QWidget *parent = 0);
};



#endif
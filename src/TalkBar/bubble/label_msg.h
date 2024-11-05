#ifndef __LABEL_MSG_H__
#define __LABEL_MSG_H__

#include "Config/config.h"

class LabelMsg : public QLabel{
public:
    explicit LabelMsg(E_Direction direction, const QString &text, QWidget *parent = nullptr);
};


#endif // __LABEL_MSG_H__
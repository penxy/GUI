#pragma once

#include "config.h"

class ChatTop : public WidgetBlank{
    Q_OBJECT
public:
    explicit ChatTop(QWidget *parent = 0);
    void SetInfo(const std::string& name, const QPixmap& photo);
private:
    LabelPhoto m_lab_photo;
    QLabel m_lab_name;
};

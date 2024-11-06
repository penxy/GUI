#ifndef __LABEL_MSG_H__
#define __LABEL_MSG_H__

#include "Config/config.h"

class LabelMsg : public QLabel{
public:
    explicit LabelMsg(E_Direction direction, const QString& text, QWidget *parent = nullptr);
private:
    E_Direction m_dir;
};

#endif
/*

QString qss = QString(R"(
    QLabel {
        font-family: "Microsoft YaHei";
        font-size: 12px;
        font-style: italic;
        font-weight: bold;
        color: rgb(66, 245, 120);
        font: bold italic 18px "Microsoft YaHei";
    }
)");
this->setStyleSheet(qss);
*/
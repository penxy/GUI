#include "label_msg.h"

LabelMsg::LabelMsg(E_Direction direction, const QString &text, QWidget *parent) : QLabel(parent){
    setMaximumWidth(CONST_SIZE_MAX_WIDTH_LAB_MSG);
    setWordWrap(true);

    setText(text);

    if(direction == E_Direction::Send){
        setStyleSheet("QLabel{background-color:rgb(0, 255, 0);border-radius:10px;}");
    }else{
        setStyleSheet("QLabel{background-color:rgb(255, 255, 255);border-radius:10px;}");
    }

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
}
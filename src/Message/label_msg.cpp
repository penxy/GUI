#include "label_msg.h"



LabelMsg::LabelMsg(E_Direction direction, const QString& text, QWidget *parent) : QLabel(parent), m_dir(direction){
    this->setText(text);
    //this->resize(m_size.width(), m_size.height());
    this->setWordWrap(true);
    // this->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    // this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    this->setFixedHeight(100);

    if(m_dir == E_Direction::Recv) {
        this->setStyleSheet("*{ background-color: #E6E6E6; border-radius: 10px; right-padding: 20px; }");
    }else{
        this->setStyleSheet("*{ background-color: #00BFFF; border-radius: 10px; left-padding: 20px; }");
    }
}



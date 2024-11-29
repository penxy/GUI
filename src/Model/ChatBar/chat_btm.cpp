#include "chat_btm.h"

ChatBtm::ChatBtm(QWidget *parent) : QWidget(parent){
    {
        m_btn_send.setText("发送");
        m_edit.installEventFilter(this);//触发eventFilter

        m_btn_send.setFixedSize(sz::chat_btm_btn);
        this->setMaximumHeight(sz::chat_btm_wid_max_h);
    }
    {
        QHBoxLayout *layout_btn = new QHBoxLayout;
        layout_btn->addWidget(&m_btn_send);
        layout_btn->setAlignment(Qt::AlignRight | Qt::AlignBottom); 

        QVBoxLayout *layout_main = new QVBoxLayout(this);
        layout_main->addWidget(&m_edit);
        layout_main->addLayout(layout_btn);
        layout_main->setAlignment(Qt::AlignBottom);
    }
    {
        connect(&m_btn_send, &QPushButton::clicked, this, [&](){
            emit SigSendMsg(Type::Msg::DataType::Text, m_edit.toPlainText());
            m_edit.clear();
        });
    }
    {
        QString qss = QString(R"(
            QTextEdit {
                border: 0px solid white;
                padding-bottom: 5px;
                border-bottom: 1px solid #dddddd;
                border-top: 1px solid #dddddd;
                color: #dddddd;
            }
            QTextEdit:focus{
                border: 0px solid white;
                padding-bottom: 5px;
                border-bottom: 3px solid #00695c;
                border-top: 1px solid #dddddd;
                color: #111111;
            }
            QTextEdit:selected {
                border: 0px solid white;
                padding-bottom: 5px;
                border-bottom: 3px solid #00695c;
                border-top: 1px solid #dddddd;
                color: #111111;
            }
            QPushButton{
                border: 1px solid #e5e5e5;
                border-radius: 4px;
                padding: 0 10px;
                margin: 0 10px;
                background-color: rgb(108, 245, 66);
            }
        )");
        this->setStyleSheet(qss);
    }
}


bool ChatBtm::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            emit SigSendMsg(Type::Msg::DataType::Text, m_edit.toPlainText());
            m_edit.clear();
            return true; // 事件已处理
        }
    }
    return QWidget::eventFilter(obj, event);
}
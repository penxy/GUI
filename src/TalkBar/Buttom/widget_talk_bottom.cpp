#include "widget_talk_bottom.h"

WidgetTalkBottom::WidgetTalkBottom(QWidget *parent) : QWidget(parent){
    {
        m_btn_send = new QPushButton("发送", this);
        m_edit = new QTextEdit(this);
        m_edit->installEventFilter(this);//触发eventFilter
    }
    {
        m_btn_send->setFixedSize(CONST_SIZE_BTN_TALK_BOTTOM);
        //this->setFixedSize(CONST_SIZE_WIDGET_TALK_BOTTOM);
        this->setMaximumHeight(CONST_HEIGHT_MAX_WIDGET_TALK_BOTTOM);
    }
    {
        WidgetBlank *widget_edit = new WidgetBlank(this);
        QHBoxLayout *layout_edit = new QHBoxLayout(widget_edit);
        layout_edit->addWidget(m_edit);

        WidgetBlank *widget_btn = new WidgetBlank(this);
        QHBoxLayout *layout_btn = new QHBoxLayout(widget_btn);
        layout_btn->addWidget(m_btn_send);
        layout_btn->setAlignment(Qt::AlignTop);

        QHBoxLayout *layout = new QHBoxLayout(this);
        layout->addWidget(widget_edit);
        layout->addWidget(widget_btn);
    }
    {
        connect(m_btn_send, &QPushButton::clicked, this, [&](){
            emit SigSendMsg(E_Message::Text, m_edit->toPlainText());
            m_edit->clear();
        });
    }
    {
        QString qss = QString(R"(
            QTextEdit{
                font-size: 15px;
            }
        )");
        this->setStyleSheet(qss);
    }
}


bool WidgetTalkBottom::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            emit SigSendMsg(E_Message::Text, m_edit->toPlainText());
            m_edit->clear();
            return true; // 事件已处理
        }
    }
    return QWidget::eventFilter(obj, event);
}
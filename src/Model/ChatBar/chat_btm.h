#pragma once

#include "config.h"

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

//TODO: 后续添加其它按钮
class ChatBtm : public QWidget{
    Q_OBJECT
public:
    explicit ChatBtm(QWidget *parent = nullptr);
signals:
    void SigSendMsg(Type::Msg::DataType type, const QString &msg);
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
private:
    QTextEdit m_edit;
    QPushButton m_btn_send;
};

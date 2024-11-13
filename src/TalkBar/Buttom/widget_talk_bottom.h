#ifndef __WIDGET_TALK_BOTTON_H__
#define __WIDGET_TALK_BOTTON_H__

#include "Config/config.h"
#include <QTextEdit>
#include <QPushButton>
#include <QEvent>
#include <QKeyEvent>

//TODO: 后续添加其它按钮
class WidgetTalkBottom : public QWidget{
    Q_OBJECT
public:
    explicit WidgetTalkBottom(QWidget *parent = nullptr);
signals:
    void SigSendMsg(E_Message type, const QString &msg);
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
private:
    QPushButton *m_btn_send;
    QTextEdit *m_edit;
};

#endif // __WIDGET_TALK_BUTTON_H__
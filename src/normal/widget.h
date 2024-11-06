#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <QWidget>
#include <QListWidget>
#include <QEvent>
#include "ListBar/widget_list_friend.h"
#include "Base/label_role.h"
#include "TalkBar/bubble/widget_msg.h"
#include "Message/label_msg.h"
#include <vector>

class Widget : public QWidget{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    //void paintEvent(QPaintEvent *);
    QSize getRealString(QString src);
protected:
    void resizeEvent(QResizeEvent *);
private:
    void dealMessageTime(QString curMsgTime);
    void dealMessage(WidgetMsg *messageW, QListWidgetItem *item, QString text, QString time,  WidgetMsg::User_Type type);
    void on_pushButton_clicked();
private:
    QPushButton *m_btn;
    QListWidget *m_list_widget;
    QLineEdit *m_edit;

    std::vector<WidgetMsg*>m_widget_msg_vec;
};





#endif // __WIDGET_H__
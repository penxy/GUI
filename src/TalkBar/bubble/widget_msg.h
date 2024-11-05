#ifndef __WIDGET_MSG_H__
#define __WIDGET_MSG_H__

#include <QWidget>
#include "Config/config.h"
#include "Base/label_photo.h"
#include "Base/label_role.h"

enum class ChatType{
    Friend,
    Group
};


class WidgetMsg : public QWidget{
    Q_OBJECT
public:
    explicit WidgetMsg(ChatType type, QWidget *parent = nullptr);
private:
    ChatType m_type;

    LabelPhoto *m_lab_photo;

    //if is group chat
    LabelRole *m_person_role;
    QLabel *m_person_name;
};




#endif //__WIDGET_MSG_H__
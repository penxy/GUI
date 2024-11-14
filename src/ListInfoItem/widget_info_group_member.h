#ifndef __WIDGET_INFO_GROUP_MEMBER_H__
#define __WIDGET_INFO_GROUP_MEMBER_H__
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include "Config/config_struct.h"

//群成员列表项
class WidgetInfoGroupMember : public QWidget{
    Q_OBJECT
public:
    explicit WidgetInfoGroupMember(std::pair<PersonInfo, E_Role>& info, QWidget *parent = nullptr);
private:
    QLabel *m_lab_photo;
    QLabel *m_lab_name;
    QLabel *m_lab_id;
    QLabel *m_lab_role;
    QPixmap m_photo;
};

#endif // __WIDGET_INFO_GROUP_MEMBER_H__
#ifndef __DIALOG_GROUP_H__
#define __DIALOG_GROUP_H__

#include <QDialog>
#include <QList>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

#include "Config/config.h"
#include "ListInfoItem/widget_info_group_member.h"

//TODO 改成DialogGroup
class DialogGroup : public QDialog{
    Q_OBJECT
public:
    explicit DialogGroup(QDialog *parent = 0);
    void SetInfo(GroupInfo &info);
signals:
    void SigAddGroup(cJSON* json);
private:
    QPixmap *m_photo;
    QLabel *m_lab_photo;

    QLabel *m_lab_id;
    QLabel *m_lab_member_count;

    QLabel *m_lab_name;

    QLineEdit *m_edit_msg;
    QPushButton *m_btn_add_group;
    QListWidget *m_widget_group_member_list;//保存QWidgetInfoGroupMember
};





#endif
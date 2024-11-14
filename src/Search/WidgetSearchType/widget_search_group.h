#ifndef __WIGDET_SEARCH_GROUP_H__
#define __WIDGET_SEARCH_GROUP_H__

#include "Config/config.h"
#include <QListWidget>

class WidgetSearchGroup : public QWidget{
    Q_OBJECT
public:
    explicit WidgetSearchGroup(QWidget *parent = nullptr);

    void SetInfo(std::shared_ptr<GroupInfo>info);
signals:
    void SigAddGroup(cJSON* json);
private:
    std::shared_ptr<QPixmap>m_photo = nullptr;
    QLabel *m_lab_photo;

    QLabel *m_lab_id;
    QLabel *m_lab_member_count;

    QLabel *m_lab_name;

    QLineEdit *m_edit_msg;
    QPushButton *m_btn_add_group;
    QListWidget *m_widget_group_member_list;//保存QWidgetInfoGroupMember
};








#endif // __WIGDET_SEARCH_GROUP_H__
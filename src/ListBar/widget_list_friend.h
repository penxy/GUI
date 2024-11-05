#ifndef __WIDGET_LIST_FRIEND_H__
#define __WIDGET_LIST_FRIEND_H__

#include "Config/config.h"
#include "ListInfoItem/widget_info_friend.h"

#include <QListWidget>
#include <QList>

class WidgetListFriend : public QWidget{
    Q_OBJECT
public:
    explicit WidgetListFriend(QWidget *parent = 0);

    void addFriendInfo(PersonInfo&& person_info);
    void delFriendInfo(int person_id);
private:
    QListWidget *m_widget_list;
    QList<int>m_id_list;//用于记录下标
};



#endif // __WIDGET_LIST_FRIEND_H__
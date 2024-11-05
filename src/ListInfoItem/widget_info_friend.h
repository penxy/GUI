#ifndef __WIDGET_INFO_FRIEND_H__
#define __WIDGET_INFO_FRIEND_H__

#include "Config/config.h"

#include <QPixmap>
#include <QList>
#include "Base/label_photo.h"


class WidgetInfoFriend : public QWidget{
    Q_OBJECT
public:
    explicit WidgetInfoFriend(PersonInfo&& info, QWidget *parent = 0);
public:
    int GetId() const;
private:
    LabelPhoto *m_lab_photo;
    QLabel *m_lab_id;
    QLabel *m_lab_name;

    QPixmap *m_photo;
};












#endif // __WIDGET_INFO_FRIEND_H__
#ifndef __WIDGET_TALK_TOP_H__
#define __WIDGET_TALK_TOP_H__

#include "Config/config.h"
#include "Base/label_photo.h"

#include <QPixmap>

class WidgetTalkTop : public QWidget{
    Q_OBJECT
public:
    explicit WidgetTalkTop(E_Identity type, std::shared_ptr<void> info, QWidget *parent = 0);
private:
    LabelPhoto *m_lab_photo;
    QPixmap m_photo;
    QLabel *m_lab_name;
};

#endif // __WIDGET_TALK_TOP_H__
#ifndef __WIDGET_TALK_WINDOW_H__
#define __WIDGET_TALK_WINDOW_H__


//对外接口，根据ListBar进行修改
#include "Config/config.h"

#include "TalkBar/Top/widget_talk_top.h"
#include "TalkBar/Mid/widget_talk_mid.h"
#include "TalkBar/Buttom/widget_talk_bottom.h"


class WidgetTalkWindow : public QWidget{
    Q_OBJECT
public:
    explicit WidgetTalkWindow(E_Identity type, void *info, QWidget *parent = 0);
    ~WidgetTalkWindow();
private:
    E_Identity m_type;

    GroupInfo *m_groupInfo = nullptr;
    PersonInfo *m_personInfo = nullptr;

    WidgetTalkTop *m_talkTop;
    WidgetTalkMid *m_talkMid;
    WidgetTalkBottom *m_talkBottom;
};

#endif // __WIDGET_TALK_WINDOW_H__
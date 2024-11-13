#ifndef __WIDGET_RIGHT_H__
#define __WIDGET_RIGHT_H__

#include <QWidget>
#include "ListBar/widget_list_friend.h"
#include "TalkBar/widget_talk_window.h"
#include "Config/config.h"

#include "RightPage/WidgetType/widget_default.h"
#include <QStackedWidget>
#include "ToolBar/widget_tool.h"

/**
 * @brief 工具栏以右，由一个 QStackedWidget 管理，并与 ToolBar 交互
 * 
 */
class WidgetRight : public QWidget{
    Q_OBJECT
public:
    explicit WidgetRight(WidgetTool *widget_tool, QWidget *parent = 0);
public slots:
    void SlotWidgetChange(WidgetTool::TypePage type);
private:
    //TypeRight::Default
    WidgetDefault *m_default;
    //TypeRight::Friend
    WidgetListFriend *m_listFriend;
    WidgetTalkWindow *m_talkwindow;
    //TypeRight::Group

    WidgetTool *m_widget_tool;
    QStackedWidget *m_widget_stack;
};








#endif // __WIDGET_RIGHT_H__
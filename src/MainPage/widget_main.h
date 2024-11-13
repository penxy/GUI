#ifndef __WIDGET_MAIN_H__
#define __WIDGET_MAIN_H__

#include "Config/config.h"
#include "Base/widget_base.h"

#include "TitleBar/titlebar.h"
#include "ToolBar/widget_tool.h"
#include "RightPage/widget_right.h"
#include <QMouseEvent>

class WidgetMain : public QWidget{
    Q_OBJECT
public:
    explicit WidgetMain(QWidget *parent = nullptr);
    ~WidgetMain();
private:
    TitleBar *m_title_bar;

    WidgetTool *m_widget_tool;
    WidgetRight *m_widget_right;
    QPoint m_dragPosition;
};





#endif // __WIDGET_MAIN_H__
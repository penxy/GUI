#ifndef __WIDGET_MAIN_H__
#define __WIDGET_MAIN_H__

#include "TitleBar/titlebar.h"
#include "Base/widget_base.h"
#include <QResizeEvent>

class WidgetMain : public WidgetBase{
    Q_OBJECT
public:
    explicit WidgetMain(QWidget *parent = nullptr);
private:
    void init_ui();
    void init_sig();
private:
    void resizeEvent(QResizeEvent *event);//需要调用WidgetLeft, WidgetTool, WidgetRight的 ReSize()
private:
    TitleBar *m_titleBar;
    QWidget *m_widget_chat;
};





#endif // __WIDGET_MAIN_H__
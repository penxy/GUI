#ifndef __WIDGET_TOOL_H__
#define __WIDGET_TOOL_H__

#include "btn_tool.h"
#include <QWidget>

class WidgetTool : public QWidget{
    Q_OBJECT
public:
    explicit WidgetTool(QWidget *parent = nullptr);
private:
    BtnTool *btn_head;
    BtnTool *btn_search;
    BtnTool *btn_chat_person;
    BtnTool *btn_chat_group;
};



#endif

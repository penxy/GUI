#pragma once
#include "config.h"
#include "ListBar/list_page.h"
#include "ToolBar/tool_page.h"
#include "ChatBar/chat_page.h"
#include "TitleBar/title_bar.h"

#include "Search/find_page.h"
#include "Card/card.h"
#include "Core/core.h"

//连接所有不同页面之间的信号
class Widget : public QWidget{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
public slots:
    void SlotTool(ToolPage::TypeBtn type);                                          //工具栏按钮点击, 打开相应的页面
    void SlotFind(Type::Info::Identity identy, int id);                             //搜索按钮点击
private:
    ListPage *m_list_page;
    ToolPage *m_tool_page;
    ChatPage *m_chat_page;
    TitleBar *m_title_bar;
    
    FindPage *m_find_page;
    
    Card* m_card = nullptr;//    
    Core* m_core = nullptr;
};

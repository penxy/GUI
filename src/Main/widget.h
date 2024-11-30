#pragma once
#include "config.h"
#include "ListBar/list_page.h"
#include "ToolBar/tool_page.h"
#include "ChatBar/chat_page.h"
#include "TitleBar/title_bar.h"

#include "Card/fd_card.h"
#include "Core/core.h"

/**
 * @class Widget
 * @brief  主窗口类
 * @details 显示所有组件，连接所有不同组件之间的信号
 * @todo 需要一个添加 chatid 的dialog
 */
class Widget : public QWidget{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
public slots:
    void SlotTool(ToolPage::TypeBtn type);                                          //工具栏按钮点击, 打开相应的页面
    //void SlotAdd(ChatId id);                                                        //添加ChatId的dialog点击添加
private:
    ListPage *m_list_page;
    ToolPage *m_tool_page;
    ChatPage *m_chat_page;
    TitleBar *m_title_bar;
        
    FdCard *m_card = nullptr;
    std::shared_ptr<Core> m_core;
};

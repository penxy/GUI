#include "widget.h"
#include <QVBoxLayout>
#include <unistd.h>

Widget::Widget(QWidget *parent) : QWidget(parent){
    m_core = std::make_shared<Core>(nullptr);
    m_tool_page = new ToolPage(this);
    m_list_page = new ListPage(m_core->shared_from_this(), this);
    m_chat_page = new ChatPage(m_core->shared_from_this(), this);
    m_title_bar = new TitleBar(this);

    QVBoxLayout *layout_chat = new QVBoxLayout;
    layout_chat->setSpacing(0);
    layout_chat->addWidget(m_title_bar);
    layout_chat->addWidget(m_chat_page);

    QHBoxLayout *layout_main = new QHBoxLayout(this);
    layout_main->setSpacing(0);
    layout_main->addWidget(m_tool_page);
    layout_main->addWidget(m_list_page);
    layout_main->addLayout(layout_chat);

    // this->resize(800, 600);

    //所有对外信号所在
    connect(m_list_page, &ListPage::SigListChangeIdx, m_chat_page, &ChatPage::SlotListChangeIdx);
    connect(m_tool_page, &ToolPage::SigTool, this, &Widget::SlotTool);
    // connect(m_find_page, &FindPage::SigFind, this, &Widget::SlotFind);
}

void Widget::SlotTool(ToolPage::TypeBtn type){
    switch (type){
        case ToolPage::TypeBtn::Add:{
            break;
        }
        case ToolPage::TypeBtn::ChatPerson:{
            m_list_page->setPage(ListPage::TypePage::Friend);
            break;
        }
        case ToolPage::TypeBtn::ChatGroup:{
            m_list_page->setPage(ListPage::TypePage::Group);
            break;
        }
        case ToolPage::TypeBtn::Setting:{
            break;
        }
        default:
            break;
    }
}
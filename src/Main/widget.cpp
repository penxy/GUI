#include "widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent){
    m_core = new Core;
    m_tool_page = new ToolPage(this);
    m_list_page = new ListPage(this);
    m_chat_page = new ChatPage(m_core, this);
    m_title_bar = new TitleBar(this);
    m_find_page = new FindPage(this);

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
    connect(m_find_page, &FindPage::SigFind, this, &Widget::SlotFind);
}

void Widget::SlotTool(ToolPage::TypeBtn type){
    switch (type){
        case ToolPage::TypeBtn::Search:{
            m_find_page->show();
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
void Widget::SlotFind(Type::Info::Identity identy, int id){
    sleep(2);//test
    if(identy == Type::Info::Identity::Friend){
        if(m_card != nullptr){
            delete m_card;
        }
        m_card = new Card(Type::Info::Identity::Friend, 
                            std::static_pointer_cast<void>(std::make_shared<ns::FriendInfo>(ns::FriendInfo(1, "22", QPixmap(":/Icons/image.png")))), 
                            this);
    }
    m_card->show();
}
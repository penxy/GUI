#include "widget_right.h"
#include "Base/Line.h"
#include <memory>

WidgetRight::WidgetRight(WidgetTool *widget_tool, QWidget *parent) : QWidget(parent), m_widget_tool(widget_tool){
    m_widget_stack = new QStackedWidget(this);
    //WidgetTool::TypePage::Head
    {
        WidgetBlank *blank = new WidgetBlank(this);
        m_widget_stack->addWidget(blank);
    }
    //WidgetTool::TypePage::Search
    {
        WidgetBlank *blank = new WidgetBlank(this);
        m_widget_stack->addWidget(blank);
    }
    //WidgetTool::TypePage::ChatPerson
    {
        m_listFriend = new WidgetListFriend(this);
        std::shared_ptr<PersonInfo> person1 = std::make_shared<PersonInfo>(1, "张三", QPixmap(":/Icons/MainWindow/head.png"));
        m_listFriend->addFriendInfo(person1);

        std::shared_ptr<PersonInfo> person2 = std::make_shared<PersonInfo>(2, "李四", QPixmap(":/Icons/MainWindow/head2.png"));
        m_listFriend->addFriendInfo(person2);

        //目前与person1的窗口
        m_talkwindow = new WidgetTalkWindow(E_Identity::Friend, std::static_pointer_cast<void>(person1), this);

        WidgetBlank *widget_talk = new WidgetBlank(this);
        Layout *layout_talk = new Layout(QBoxLayout::Direction::LeftToRight, widget_talk);
        layout_talk->addWidget(m_listFriend);
        layout_talk->addWidget(new Line(this, Line::TypeLine::V));
        layout_talk->addWidget(m_talkwindow);

        m_widget_stack->addWidget(widget_talk);
    }
    //WidgetTool::TypePage::Group
    {
        WidgetBlank *blank = new WidgetBlank(this);
        m_widget_stack->addWidget(blank);
    }
    //WidgetTool::TypePage::Default
    {        
        m_default = new WidgetDefault(this);
        m_widget_stack->addWidget(m_default);
    }
    {
        QVBoxLayout *layout_main = new QVBoxLayout(this);
        layout_main->addWidget(m_widget_stack);
    }
    {
        m_widget_stack->setCurrentIndex((int)WidgetTool::TypePage::Default);
        this->resize(CONST_SIZE_BASE_WIDGET_RIGHT);
    }
    {
        connect(m_widget_tool, &WidgetTool::SigBtnClick, this, &WidgetRight::SlotWidgetChange);
    }
}

void WidgetRight::SlotWidgetChange(WidgetTool::TypePage type){
    m_widget_stack->setCurrentIndex((int)type);
}
#include "widget_talk_window.h"
#include "Base/Line.h"
#include "Base/Layout.h"
#include <thread>


WidgetTalkWindow::WidgetTalkWindow(E_Identity type, std::shared_ptr<void> info, QWidget *parent) : QWidget(parent), m_type(type){
    if(m_type == E_Identity::Friend){
        m_personInfo = std::static_pointer_cast<PersonInfo>(info);
    }else{
        //m_groupInfo = std::make_shared<GroupInfo>(static_cast<GroupInfo*>(info));
    }
    m_talkTop = new WidgetTalkTop(m_type, info, this);
    m_talkMid = new WidgetTalkMid(this);
    m_talkBottom = new WidgetTalkBottom(this);

    {
        this->resize(CONST_SIZE_BASE_TALK_WINDOW);
        this->setMinimumSize(CONST_SIZE_MIN_TALK_WINDOW);
    }

    {
        Line *line_top = new Line(this);
        Line *line_bottom = new Line(this);

        Layout *layout_main = new Layout(QBoxLayout::Direction::TopToBottom, this);
        layout_main->setSpacing(0);
        layout_main->addWidget(m_talkTop);
        layout_main->addWidget(line_top);
        layout_main->addWidget(m_talkMid);
        layout_main->addWidget(line_bottom);
        layout_main->addWidget(m_talkBottom);
    }

    {
        connect(m_talkBottom, &WidgetTalkBottom::SigSendMsg, m_talkMid, &WidgetTalkMid::SlotMessageSend);
    }
    {
        QString qss = QString(R"(
            WidgetBlank{
                border: 5px solid green;
                padding: 2px;
            }
        )");
        this->setStyleSheet(qss);
    }
}

WidgetTalkWindow::~WidgetTalkWindow(){

}


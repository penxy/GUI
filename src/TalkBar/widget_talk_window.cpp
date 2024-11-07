#include "widget_talk_window.h"
#include "Base/Line.h"
#include "Base/Layout.h"

WidgetTalkWindow::WidgetTalkWindow(E_Identity type, void *info, QWidget *parent) : QWidget(parent), m_type(type){
    if(m_type == E_Identity::Friend){
        m_personInfo = (PersonInfo*)(info);
    }else{
        m_groupInfo = (GroupInfo*)(info);
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

        WidgetBlank *widget_top = new WidgetBlank(this);
        widget_top->setFixedHeight(CONST_SIZE_WIDGET_TALK_TOP.height());
        Layout *layout_top = new Layout(QBoxLayout::Direction::LeftToRight, widget_top);
        layout_top->addWidget(m_talkTop);

        WidgetBlank *widget_mid = new WidgetBlank(this);
        Layout *layout_mid = new Layout(QBoxLayout::Direction::LeftToRight, widget_mid);
        layout_mid->addWidget(m_talkMid);

        WidgetBlank *widget_bottom = new WidgetBlank(this);
        widget_bottom->setMaximumHeight(CONST_HEIGHT_MAX_WIDGET_TALK_BOTTOM);
        Layout *layout_bottom = new Layout(QBoxLayout::Direction::LeftToRight, widget_bottom);
        layout_bottom->addWidget(m_talkBottom);

        Layout *layout_main = new Layout(QBoxLayout::Direction::TopToBottom, this);
        layout_main->setSpacing(0);
        layout_main->addWidget(widget_top);
        layout_main->addWidget(line_top);
        layout_main->addWidget(widget_mid);
        layout_main->addWidget(line_bottom);
        layout_main->addWidget(widget_bottom);
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
    (m_type == E_Identity::Friend ? delete m_personInfo : delete m_groupInfo);
}
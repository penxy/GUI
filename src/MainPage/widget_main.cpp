#include "widget_main.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QWidget>
#include "Config/config_ui.h"
#include "Base/Line.h"

WidgetMain::WidgetMain(QWidget *parent) : QWidget(parent){
    {
        this->setWindowFlags(Qt::FramelessWindowHint);  //设置无边框
        // this->setStyleSheet("border:none;background-color:#F0F0F0;");
    }
    m_title_bar = new TitleBar(this);
    m_widget_tool = new WidgetTool(this);
    m_widget_right = new WidgetRight(m_widget_tool, this);

    WidgetBlank *widget_right = new WidgetBlank(this);
    Layout *layout_right = new Layout(QBoxLayout::Direction::TopToBottom, widget_right);
    layout_right->addWidget(m_title_bar);
    layout_right->addWidget(new Line(widget_right));
    layout_right->addWidget(m_widget_right);

    Layout *layout_main = new Layout(QBoxLayout::Direction::LeftToRight, this);
    layout_main->addWidget(m_widget_tool);
    layout_main->addWidget(widget_right);

    this->resize(CONST_SIZE_BASE_WIDGET_MAIN);

    {
      QString qss = QString(R"(
        QStackedWidget{
          border-radius: 10px;
        }
      )");
    }
}


WidgetMain::~WidgetMain(){
  
}
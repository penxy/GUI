#include "widget_main.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QWidget>
#include "Config/config_ui.h"

void WidgetMain::init_ui(){
    m_titleBar = new TitleBar(this);
    m_widget_chat = new QWidget(this);
    m_widget_chat->resize(CONST_SIZE_BASE_WIDGET_MAIN);
    m_widget_chat->setStyleSheet("background-color: #FFFFFF;border: 1px solid #E5E5E5;");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_titleBar);
    mainLayout->setSpacing(5);
    mainLayout->addWidget(m_widget_chat);
    mainLayout->setSpacing(0);

    setLayout(mainLayout);
    this->setMinimumSize(CONST_SIZE_MIN_WIDGET_MAIN);
    resize(CONST_SIZE_BASE_WIDGET_MAIN);
}

void WidgetMain::init_sig(){
    
}

WidgetMain::WidgetMain(QWidget *parent) : WidgetBase(parent){
    init_ui();
    init_sig();
    m_old_size = this->size();
}

void WidgetMain::resizeEvent(QResizeEvent *event){
    QSize new_size = this->window()->size();
    double scale_x = new_size.width() / m_old_size.width();
    double scale_y = new_size.height() / m_old_size.height();
    m_widget_chat->resize(m_widget_chat->size().width() * scale_x, m_widget_chat->size().height() * scale_y);
    m_titleBar->resize(m_titleBar->size().width() * scale_x, m_titleBar->size().height() * scale_y);
    m_old_size = new_size;
}

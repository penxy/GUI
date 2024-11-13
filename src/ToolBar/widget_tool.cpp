#include "widget_tool.h"
#include <QVBoxLayout>
#include "Base/widget_blank.h"
#include "Config/config_ui.h"

WidgetTool::WidgetTool(QWidget *parent) : QWidget(parent){
    {
        QStringList btn_head_path_list;
        btn_head_path_list << ":/Icons/MainWindow/head.png" << ":/Icons/MainWindow/head.png";
        btn_head = new BtnTool(BtnTool::TypeBtn::Head, std::move(btn_head_path_list), this);
        
        QStringList btn_search_path_list;
        btn_search_path_list << ":/Icons/MainWindow/search.png" << ":/Icons/MainWindow/search.png";
        btn_search = new BtnTool(BtnTool::TypeBtn::Search, std::move(btn_search_path_list), this);

        QStringList btn_chat_person_path_list;
        btn_chat_person_path_list << ":/Icons/MainWindow/friend.png" << ":/Icons/MainWindow/friend2.png";
        btn_chat_person = new BtnTool(BtnTool::TypeBtn::ChatPerson, std::move(btn_chat_person_path_list), this);

        QStringList btn_chat_group_path_list;
        btn_chat_group_path_list << ":/Icons/MainWindow/group.png" << ":/Icons/MainWindow/group2.png";
        btn_chat_group = new BtnTool(BtnTool::TypeBtn::ChatGroup, std::move(btn_chat_group_path_list), this);
    }
    {
        btn_head->setFixedSize(CONST_SIZE_BTN_TOOL);
        btn_search->setFixedSize(CONST_SIZE_BTN_TOOL);
        btn_chat_person->setFixedSize(CONST_SIZE_BTN_TOOL);
        btn_chat_group->setFixedSize(CONST_SIZE_BTN_TOOL);
        this->setFixedWidth(CONST_WIDTH_WIDGET_TOOL);
    }
    {
        QBoxLayout *layout_main = new QBoxLayout(QBoxLayout::TopToBottom, this);
        layout_main->setSpacing(5);
        layout_main->setAlignment(Qt::AlignTop);
        layout_main->addWidget(btn_head);
        layout_main->addWidget(btn_search);
        layout_main->addWidget(btn_chat_person);
        layout_main->addWidget(btn_chat_group);
    }
    {
        connect(btn_head, &BtnTool::clicked, this, &WidgetTool::onClicked);
        connect(btn_search, &BtnTool::clicked, this, &WidgetTool::onClicked);
        connect(btn_chat_person, &BtnTool::clicked, this, &WidgetTool::onClicked);
        connect(btn_chat_group, &BtnTool::clicked, this, &WidgetTool::onClicked);
    }
    {
        QString qss = "*{background-color: rgb(71, 67, 65);}";
        this->setStyleSheet(qss);
    }
}

void WidgetTool::onClicked(){
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    
    if(pButton == btn_head){
        qDebug() << "clicked btn_head";
        emit SigBtnClick(TypePage::Head);
    } else if(pButton == btn_search){
        qDebug() << "clicked btn_search";
        emit SigBtnClick(TypePage::Search);
    } else if(pButton == btn_chat_person){
        qDebug() << "clicked btn_chat_person";
        emit SigBtnClick(TypePage::ChatPerson);
    } else if(pButton == btn_chat_group){
        qDebug() << "clicked btn_chat_group";
        emit SigBtnClick(TypePage::ChatGroup);
    } else{
        qDebug() << "clicked btn_other";
    }
}
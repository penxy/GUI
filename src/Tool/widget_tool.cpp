#include "widget_tool.h"
#include <QVBoxLayout>
#include "Base/widget_blank.h"
#include "Config/config_ui.h"

WidgetTool::WidgetTool(QWidget *parent) : QWidget(parent){
    {
        QStringList btn_head_path_list;
        btn_head_path_list << ":/Icons/MainWindow/head.png" << ":/Icons/MainWindow/head.png";
        btn_head = new BtnTool(BtnType::Head, std::move(btn_head_path_list), this);
        
        QStringList btn_search_path_list;
        btn_search_path_list << ":/Icons/MainWindow/search.png" << ":/Icons/MainWindow/search.png";
        btn_search = new BtnTool(BtnType::Search, std::move(btn_search_path_list), this);

        QStringList btn_chat_person_path_list;
        btn_chat_person_path_list << ":/Icons/MainWindow/friend.png" << ":/Icons/MainWindow/friend2.png";
        btn_chat_person = new BtnTool(BtnType::ChatPerson, std::move(btn_chat_person_path_list), this);

        QStringList btn_chat_group_path_list;
        btn_chat_group_path_list << ":/Icons/MainWindow/group.png" << ":/Icons/MainWindow/group2.png";
        btn_chat_group = new BtnTool(BtnType::ChatGroup, std::move(btn_chat_group_path_list), this);
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
        QString qss = "*{background-color: rgb(71, 67, 65);}";
        this->setStyleSheet(qss);
    }
}

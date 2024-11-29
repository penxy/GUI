#include "tool_page.h"
#include <QVBoxLayout>
#include "Base/widget_blank.h"
#include "config.h"

ToolPage::ToolPage(QWidget *parent) : QWidget(parent){
    {
        QStringList btn_head_path_list;
        btn_head_path_list << ":/Icons/MainWindow/head.png" << ":/Icons/MainWindow/head.png" << ":/Icons/MainWindow/head.png";
        btn_head = new ToolBtn(std::move(btn_head_path_list), this);
        
        QStringList btn_search_path_list;
        btn_search_path_list << ":/Icons/MainWindow/search.png" << ":/Icons/MainWindow/search.png" << ":/Icons/MainWindow/search.png";
        btn_search = new ToolBtn(std::move(btn_search_path_list), this);

        QStringList btn_chat_person_path_list;
        btn_chat_person_path_list << ":/Icons/MainWindow/friend.png" << ":/Icons/MainWindow/friend2.png" << ":/Icons/MainWindow/friend3.png";
        btn_chat_person = new ToolBtn(std::move(btn_chat_person_path_list), this);

        QStringList btn_chat_group_path_list;
        btn_chat_group_path_list << ":/Icons/MainWindow/group.png" << ":/Icons/MainWindow/group2.png" << ":/Icons/MainWindow/group3.png";
        btn_chat_group = new ToolBtn(std::move(btn_chat_group_path_list), this);

        QStringList btn_chat_setting_path_list;
        btn_chat_setting_path_list << ":/Icons/MainWindow/settings.png" << ":/Icons/MainWindow/settings2.png" << ":/Icons/MainWindow/settings3.png";
        btn_setting = new ToolBtn(std::move(btn_chat_setting_path_list), this);
    }
    {
        btn_head->setFixedSize(sz::tool_btn);
        btn_search->setFixedSize(sz::tool_btn);
        btn_chat_person->setFixedSize(sz::tool_btn);
        btn_chat_group->setFixedSize(sz::tool_btn);
        this->setFixedWidth(sz::tool_wid);
    }
    {
        QBoxLayout *layout_main = new QBoxLayout(QBoxLayout::TopToBottom, this);
        layout_main->setSpacing(5);
        layout_main->setAlignment(Qt::AlignTop);
        layout_main->addWidget(btn_head);
        layout_main->addWidget(btn_search);
        layout_main->addWidget(btn_chat_person);
        layout_main->addWidget(btn_chat_group);
        layout_main->addWidget(btn_setting);
    }
    {
        connect(btn_head, &ToolBtn::clicked, this, &ToolPage::onClicked);
        connect(btn_search, &ToolBtn::clicked, this, &ToolPage::onClicked);
        connect(btn_chat_person, &ToolBtn::clicked, this, &ToolPage::onClicked);
        connect(btn_chat_group, &ToolBtn::clicked, this, &ToolPage::onClicked);
        connect(btn_setting, &ToolBtn::clicked, this, &ToolPage::onClicked);
    }
    {
        // QString qss = "background-color: rgb(168, 173, 168);";
        // this->setStyleSheet(qss);
    }
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::blue);
    this->setPalette(palette);
}

void ToolPage::onClicked(){
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    
    if(pButton == btn_head){
        qDebug() << "clicked btn_head";
        //emit SigTool(TypeBtn::Head);暂时不考虑
    } else if(pButton == btn_search){
        qDebug() << "clicked btn_search";
        emit SigTool(TypeBtn::Search);
    } else if(pButton == btn_chat_person){
        qDebug() << "clicked btn_chat_person";
        emit SigTool(TypeBtn::ChatPerson);
    } else if(pButton == btn_chat_group){
        qDebug() << "clicked btn_chat_group";
        emit SigTool(TypeBtn::ChatGroup);
    } else if(pButton == btn_setting){
        qDebug() << "clicked btn_setting";
        emit SigTool(TypeBtn::Setting);
    } else{
        qDebug() << "clicked btn_other";
    }
}
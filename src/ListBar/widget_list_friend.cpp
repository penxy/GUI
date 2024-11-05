#include "widget_list_friend.h"

WidgetListFriend::WidgetListFriend(QWidget *parent) : QWidget(parent){
    m_widget_list = new QListWidget(this);

    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->addWidget(m_widget_list);

    QString qss = QString(R"(
        QListWidget::item{
            border: 1px solid rgb(128, 123, 121);
        }
    )");
    this->setStyleSheet(qss);
}

void WidgetListFriend::addFriendInfo(PersonInfo &&info){
    m_id_list.push_back(info.id);
    WidgetInfoFriend *widget_info_friend = new WidgetInfoFriend(std::move(info), this);
    QListWidgetItem *item = new QListWidgetItem(m_widget_list);
    item->setSizeHint(widget_info_friend->sizeHint());
    m_widget_list->setItemWidget(item, widget_info_friend);
}

void WidgetListFriend::delFriendInfo(int id){
    for(int i = 0;i < m_id_list.size(); i++){
        if(m_id_list[i] == id){
            m_id_list.erase(m_id_list.begin() + i);
            delete m_widget_list->takeItem(i);
            break;
        }
    }
}
#include "fd_list.h"
#include "fd_list_item.h"

FdList::FdList(QWidget *parent) : CoreList(Type::Info::Identity::Friend, parent){
}

void FdList::AddItem(std::shared_ptr<void>info){
    qDebug() << "Add Friend";
    m_id_list.push_back(std::static_pointer_cast<ns::FriendInfo>(info));
    FdListItem *wid_fd_item = new FdListItem(info, this);
    QListWidgetItem *item = new QListWidgetItem(&m_wid_list);
    item->setSizeHint(wid_fd_item->sizeHint());
    m_wid_list.setItemWidget(item, wid_fd_item);
}

void FdList::DelItem(int id){
    for(int i = 0;i < m_id_list.size(); i++){
        if(m_id_list[i].get()->id == id){
            m_id_list.erase(m_id_list.begin() + i);
            delete m_wid_list.takeItem(i);
            break;
        }
    }
}
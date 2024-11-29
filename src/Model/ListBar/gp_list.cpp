#include "gp_list.h"
#include "gp_list_item.h"

GpList::GpList(QWidget *parent) : CoreList(Type::Info::Identity::Group, parent){
}

void GpList::AddItem(std::shared_ptr<void>info){
    m_id_list.push_back(std::static_pointer_cast<ns::GroupInfo>(info));
    GpListItem *wid_gp_item = new GpListItem(info, this);
    QListWidgetItem *item = new QListWidgetItem(&m_wid_list);
    item->setSizeHint(wid_gp_item->sizeHint());
    m_wid_list.setItemWidget(item, wid_gp_item);
}

void GpList::DelItem(int id){
    for(int i = 0;i < m_id_list.size(); i++){
        if(m_id_list[i].get()->id == id){
            m_id_list.erase(m_id_list.begin() + i);
            delete m_wid_list.takeItem(i);
            break;
        }
    }
}
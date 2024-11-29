#include "fd_list_item.h"

FdListItem::FdListItem(std::shared_ptr<void> info, QWidget *parent) : CoreListItem(parent){
    m_info = std::static_pointer_cast<ns::FriendInfo>(info);

    m_lab_name.setText(QString::fromStdString(m_info.get()->name));
    m_lab_photo.SetPhoto(m_info.get()->photo);
}
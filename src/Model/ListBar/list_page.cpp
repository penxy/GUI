#include "list_page.h"
#include "fd_list.h"
#include "gp_list.h"

#include <QHBoxLayout>

ListPage::ListPage(QWidget *parent) : QWidget(parent){
    FdList *m_fd_list = new FdList(this);
    GpList *m_gp_list = new GpList(this);
    //test
    for(int i=0;i<2;i++)
        m_fd_list->AddItem(std::static_pointer_cast<ns::FriendInfo>(std::make_shared<ns::FriendInfo>(ns::FriendInfo(1, "aaa", QPixmap(":/Icons/image.png")))));

    m_stack_wid.addWidget(new QWidget(this));
    m_stack_wid.addWidget(m_fd_list);
    m_stack_wid.addWidget(m_gp_list);
    m_stack_wid.setCurrentIndex((int)TypePage::NONE);

    QHBoxLayout *layout_main = new QHBoxLayout(this);
    layout_main->setContentsMargins(0, 0, 0, 0);
    layout_main->addWidget(&m_stack_wid);

    connect(m_fd_list, &FdList::SigListChangeIdx, this, [&](Type::Info::Identity identity, int idx){
        emit SigListChangeIdx(identity, idx);
    });
    connect(m_gp_list, &GpList::SigListChangeIdx, this, [&](Type::Info::Identity identity, int idx){
        emit SigListChangeIdx(identity, idx);
    });

    this->setFixedWidth(sz::list_bar_w);
}
/**
 * @brief 设置当前页面
 */
void ListPage::setPage(TypePage type_page){
    m_stack_wid.setCurrentIndex((int)type_page);
}

void ListPage::addList(Type::Info::Identity indentity, std::shared_ptr<void>info){
    if(indentity == Type::Info::Identity::Friend)
        static_cast<FdList*>(m_stack_wid.widget((int)TypePage::Friend))->AddItem(info);
    else
        static_cast<GpList*>(m_stack_wid.widget((int)TypePage::Group))->AddItem(info);
}
void ListPage::delList(Type::Info::Identity indentity, int id){
    if(indentity == Type::Info::Identity::Friend)
        static_cast<FdList*>(m_stack_wid.widget((int)TypePage::Friend))->DelItem(id);
    else
        static_cast<GpList*>(m_stack_wid.widget((int)TypePage::Group))->DelItem(id);
}
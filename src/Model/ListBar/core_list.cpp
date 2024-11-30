#include "core_list.h"
#include <QVBoxLayout>

CoreList::CoreList(Type::Info::Identity identity, QWidget *parent) : QWidget(parent), m_identity(identity) {
    // this->setFixedWidth(sz::list_bar_w);
    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->addWidget(&m_wid_list);

    connect(&m_wid_list, &QListWidget::itemClicked, this, [&](QListWidgetItem *item){
        if(m_cur_idx != -1 && m_wid_list.row(item) == m_cur_idx) return;
        m_cur_idx = m_wid_list.row(item);
        emit SigListChangeIdx(m_identity, m_cur_idx);
    });

    QString qss = QString(R"(
        QListWidget::item{
            border: 1px solid rgb(128, 123, 121);
        }
    )");
    this->setStyleSheet(qss);
}
#include "core_list_item.h"

CoreListItem::CoreListItem(QWidget *parent) : QWidget(parent){
    m_lab_name.setToolTip("name");

    m_lab_photo.setFixedSize(sz::fd_list_photo);
    m_lab_name.setFixedSize(sz::fd_list_name);
    this->setFixedSize(sz::fd_list_wid);

    QVBoxLayout* layout_photo = new QVBoxLayout;
    layout_photo->setMargin(0);
    layout_photo->addWidget(&m_lab_photo);

    QVBoxLayout* layout_name = new QVBoxLayout;
    layout_name->setSpacing(5);
    layout_name->addWidget(&m_lab_name);
    layout_name->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QHBoxLayout* layout_main = new QHBoxLayout(this);
    layout_main->addLayout(layout_photo);
    layout_main->addLayout(layout_name);

    QString qss = QString(R"(
        QLabel {
            font-family: "Microsoft YaHei";
            font-size: 12px;
            font-style: italic;
            font-weight: bold;
            color: rgb(66, 245, 120);
            font: bold italic 18px "Microsoft YaHei";
        }
    )");
    this->setStyleSheet(qss);
}

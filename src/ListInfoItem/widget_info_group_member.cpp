#include "widget_info_group_member.h"
#include "Config/config_ui.h"
#include "Base/widget_blank.h"
#include <QHBoxLayout>

WidgetInfoGroupMember::WidgetInfoGroupMember(std::shared_ptr<std::pair<PersonInfo, E_Role>> info, QWidget *parent) : QWidget(parent) {
    {
        m_lab_id = new QLabel(this);
        m_lab_name = new QLabel(this);
        m_lab_photo = new QLabel(this);
        m_lab_role = new QLabel(this);
        m_photo = new QPixmap();
    }
    {
        m_lab_id->setFixedSize(CONST_SIZE_LAB_INFO);
        m_lab_name->setFixedSize(CONST_SIZE_LAB_INFO);
        m_lab_photo->setFixedSize(CONST_SIZE_LAB_PHOTO);
        m_lab_role->setFixedSize(CONST_SIZE_LAB_INFO);
    }
    {
        m_lab_id->setToolTip("id");
        m_lab_name->setToolTip("name");
        m_lab_role->setToolTip("role");
        m_lab_photo->setToolTip("photo");
    }
    {
        QString id = QString::number(info.get()->first.id);
        QString name = QString::fromStdString(info.get()->first.name);

        m_lab_id->setText(id);
        m_photo = &info.get()->first.photo;

        QString role;
        if(info.get()->second == E_Role::Owner){
            role = "群主";
        }else if(info.get()->second == E_Role::Admin){
            role = "管理员";
        }else{
            role = "成员";
        }
        m_lab_id->setText(id);
        m_lab_name->setText(name);
        m_lab_role->setText(role);
        m_lab_photo->setPixmap(*m_photo);
        m_lab_photo->setScaledContents(true);
        m_lab_photo->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    }
    {
        WidgetBlank *widget_photo = new WidgetBlank(this);
        QHBoxLayout *layout_photo = new QHBoxLayout(widget_photo);
        layout_photo->addWidget(m_lab_photo);
        layout_photo->setAlignment(Qt::AlignCenter);
        widget_photo->setLayout(layout_photo);

        WidgetBlank *widget_info = new WidgetBlank(this);
        QHBoxLayout *layout_info = new QHBoxLayout(this);
        layout_info->addWidget(m_lab_id);
        layout_info->addWidget(m_lab_name);
        layout_info->addWidget(m_lab_role);
        layout_info->setAlignment(Qt::AlignLeft);
        widget_info->setLayout(layout_info);

        QHBoxLayout *layout_main = new QHBoxLayout(this);
        layout_main->addWidget(widget_photo);
        layout_main->addWidget(widget_info);
        this->setLayout(layout_main);
    }
    {
        QString styleSheet = QString(R"(
            QWidget{
                background-color: rgb(255, 255, 255);
                border: 1px solid rgb(200, 200, 200);
            }
            QLabel{
                border: 1px solid rgb(200, 200, 200);
                border-radius: 5px;
            }
        )");
        this->setStyleSheet(styleSheet);
    }
}
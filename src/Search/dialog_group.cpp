#include "dialog_group.h"
#include "Config/config_ui.h"
#include "Base/widget_blank.h"

#include <QHBoxLayout>




DialogGroup::DialogGroup(QDialog *parent) : QDialog(parent){
    {
        m_lab_photo = new QLabel(this);
        m_lab_id = new QLabel(this);
        m_lab_member_count = new QLabel(this);
        m_lab_name = new QLabel(this);
        m_edit_msg = new QLineEdit(this);
        m_btn_add_group = new QPushButton(this);
        m_photo = new QPixmap();

        m_widget_group_member_list = new QListWidget(this);
    }
    {        
        m_lab_photo->setScaledContents(true);
        m_btn_add_group->setText("添加");
        m_edit_msg->setPlaceholderText("请输入验证信息");
    }
    {
        m_lab_id->              setFixedSize(CONST_SIZE_LAB_SEARCH_GROUP);
        m_lab_member_count->    setFixedSize(CONST_SIZE_LAB_SEARCH_GROUP);
        m_lab_name->            setFixedSize(CONST_SIZE_LAB_NAME_SEARCH_GROUP);
        m_edit_msg->            setFixedSize(CONST_SIZE_EDIT_SEARCH_GROUP);
        m_btn_add_group->       setFixedSize(CONST_SIZE_BTN_SEARCH_GROUP);
        m_lab_photo->           setFixedSize(CONST_SIZE_PHOTO_SEARCH_GROUP);
        this->                  setFixedSize(CONST_SIZE_DIALOG_SEARCH_GROUP);
    }
    {
        WidgetBlank *widget_photo = new WidgetBlank(this);
        QHBoxLayout *layout_photo = new QHBoxLayout(widget_photo);
        layout_photo->addWidget(m_lab_photo);

        WidgetBlank *widget_id_count = new WidgetBlank(this);
        QHBoxLayout *layout_id_count = new QHBoxLayout(widget_id_count);
        layout_id_count->addWidget(m_lab_id);
        layout_id_count->setSpacing(25);
        layout_id_count->addWidget(m_lab_member_count);
        layout_id_count->setSpacing(0);

        WidgetBlank *widget_name = new WidgetBlank(this);
        QHBoxLayout *layout_name = new QHBoxLayout(widget_name);
        layout_name->addWidget(m_lab_name);
        
        WidgetBlank *widget_info = new WidgetBlank(this);
        QVBoxLayout *layout_lab = new QVBoxLayout(widget_info);
        layout_lab->addWidget(widget_id_count);
        layout_lab->addWidget(widget_name);

        WidgetBlank *widget_top = new WidgetBlank(this);
        QHBoxLayout *layout_top = new QHBoxLayout(widget_top);
        layout_top->addWidget(widget_photo);
        layout_top->addWidget(widget_info);

        WidgetBlank *widget_mid = new WidgetBlank(this);
        QVBoxLayout *layout_mid = new QVBoxLayout(widget_mid);
        layout_mid->addWidget(m_widget_group_member_list);

        WidgetBlank *widget_bottom = new WidgetBlank(this);
        QHBoxLayout *layout_bottom = new QHBoxLayout(widget_bottom);
        layout_bottom->addWidget(m_edit_msg);
        layout_bottom->addWidget(m_btn_add_group);

        QVBoxLayout *layout_main = new QVBoxLayout(this);
        layout_main->addWidget(widget_top);
        layout_main->setSpacing(10);
        layout_main->addWidget(widget_mid);
        layout_main->addWidget(widget_bottom);
        layout_main->setSpacing(0);

        QString styleSheet = QString(R"(
            QWidget{
                background-color: rgb(255, 255, 255);
                border: 1px solid rgb(200, 200, 200);
            }
            QLabel{
                border: 1px solid rgb(200, 200, 200);
                border-radius: 5px;
            }
            QListWidget::item{
                border: 1px solid rgb(200, 200, 200);
                border-radius: 5px;
            }
            QPushButton{
                border: 1px solid rgb(200, 200, 200);
                border-radius: 5px;
                fond-size: 12px; 
            }
            QPushButton:hover{
                background-color: green;
            }
        )");
        this->setStyleSheet(styleSheet);
    }
    /* sig */
    {
        connect(m_btn_add_group, &QPushButton::clicked, this, [&](){
            __DELAY__
            m_btn_add_group->setEnabled(false);
            m_btn_add_group->setText("已发送");

            cJSON *root = cJSON_CreateObject();
            cJSON *content = cJSON_CreateObject();
            cJSON_AddNumberToObject(root, "func", (int)E_Send::Action);
            cJSON_AddNumberToObject(content, "Identity", (int)E_Identity::Group);
            cJSON_AddNumberToObject(content, "id", m_lab_id->text().toInt());
            cJSON_AddStringToObject(content, "msg", m_edit_msg->text().toStdString().c_str());
            cJSON_AddItemToObject(root, "content", content);
        });
    }
}

void DialogGroup::SetInfo(GroupInfo &info){
    m_photo->loadFromData(QByteArray::fromBase64(QString::fromStdString(info.photo).toLocal8Bit()));
    m_lab_photo->setPixmap(*m_photo);

    m_lab_id->setText(QString::number(info.id));
    m_lab_member_count->setText(QString::number((int)info.members.size()));
    m_lab_name->setText(QString::fromStdString(info.name));

    /* set-item */
    {
        for(int i = 0;i < (int)info.members.size(); i++){
            WidgetInfoGroupMember *widget_member = new WidgetInfoGroupMember(info.members[i], this);
            QListWidgetItem *item = new QListWidgetItem(m_widget_group_member_list);
            item->setSizeHint(widget_member->sizeHint());
            m_widget_group_member_list->setItemWidget(item, widget_member);
        }
    }
}

#include "dialog_person.h"
#include <QHBoxLayout>
#include "Base/widget_blank.h"

DialogPerson::DialogPerson(QDialog *parent) : QDialog(parent)
{
    {
        m_lab_id = new QLabel(this);
        m_lab_name = new QLabel(this);
        m_lab_photo = new QLabel(this);
        m_edit_msg = new QLineEdit(this);
        m_btn_add_person = new QPushButton(this);
        m_photo = new QPixmap();
    }    

    {
        m_lab_photo->setScaledContents(true);
        m_btn_add_person->setText("添加");
        m_edit_msg->setPlaceholderText("请输入验证信息");
    }

    {
        m_lab_id->setFixedSize(CONST_SIZE_LAB_SEARCH_PERSON);
        m_lab_name->setFixedSize(CONST_SIZE_LAB_SEARCH_PERSON);
        m_lab_photo->setFixedSize(CONST_SIZE_PHOTO_SEARCH_PERSON);
        m_edit_msg->setFixedSize(CONST_SIZE_EDIT_SEARCH_PERSON);
        m_btn_add_person->setFixedSize(CONST_SIZE_BTN_SEARCH_PERSON);
        this->setFixedSize(CONST_SIZE_DIALOG_SEARCH_PERSON);
    }

    {
        WidgetBlank* widget_photo = new WidgetBlank(this);
        QHBoxLayout* layout_photo = new QHBoxLayout(widget_photo);
        layout_photo->addWidget(m_lab_photo);

        WidgetBlank* widget_info = new WidgetBlank(this);
        QVBoxLayout* layout_info = new QVBoxLayout(widget_info);
        layout_info->addWidget(m_lab_id);
        layout_info->addWidget(m_lab_name);

        WidgetBlank* widget_top = new WidgetBlank(this);
        QHBoxLayout* layout_top = new QHBoxLayout(widget_top);
        layout_top->addWidget(widget_photo);
        layout_top->addWidget(widget_info);

        WidgetBlank* widget_bottom = new WidgetBlank(this);
        QHBoxLayout* layout_bottom = new QHBoxLayout(widget_bottom);
        layout_bottom->addWidget(m_edit_msg);
        layout_bottom->addWidget(m_btn_add_person);

        QVBoxLayout* layout_main = new QVBoxLayout(this);
        layout_main->addWidget(widget_top);
        layout_main->addWidget(widget_bottom);
    }
    /*
    {
        "func" : "E_Send::Action",
        "action": "E_Action::Add",
        "content":{
            "Identity" : "E_Identity::Friend",
            "id" : "xxx",
            "msg" : "xxx",//验证消息
        }
    }
    
     */
    {
        connect(m_btn_add_person, &QPushButton::clicked, this, [&](){
            __DELAY__
            
            m_btn_add_person->setEnabled(false);
            m_btn_add_person->setText("已发送");
            cJSON *root = cJSON_CreateObject();
            cJSON_AddNumberToObject(root, "func", (int)E_Send::Action);
            cJSON_AddNumberToObject(root, "action", (int)E_Action::Add);
            cJSON *content = cJSON_CreateObject();
            cJSON_AddNumberToObject(content, "Identity", (int)E_Identity::Friend);
            cJSON_AddNumberToObject(content, "id", m_lab_id->text().toInt());
            cJSON_AddStringToObject(content, "msg", m_edit_msg->text().toStdString().c_str());
            cJSON_AddItemToObject(root, "content", content);
            emit SigAddPerson(root);
        });
    }
}
void DialogPerson::SetInfo(PersonInfo& info) {
    m_lab_id->setText(QString::number(info.id));
    m_lab_name->setText(QString::fromStdString(info.name));
    m_photo = &info.photo;
    m_lab_photo->setPixmap(*m_photo);
}

DialogPerson::~DialogPerson() {
    delete m_photo;
}
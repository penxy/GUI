#include "dialog_search.h"
#include <QAction>
#include <QHBoxLayout>
#include <QTimer>
#include "Config/config_ui.h"

/*
{
    "func" : "E_Send::Action",
    "action": "E_Action::Add",
    "content":{
        "Identity" : "E_Identity::Friend",
        "id" : "xxx",
    }
}
*/

DialogSearch::DialogSearch(QWidget *parent) : QDialog(parent){
    {
        m_widget_person = new DialogPerson(this);
        m_widget_group = new DialogGroup(this);
        m_widget_person->hide();
        m_widget_group->hide();
    }
    
    {
        m_status = new QComboBox(this);
        m_edit_id = new QLineEdit(this);
        m_btn_click = new QPushButton(this);
        m_lab_gif = new QLabel(this);
        m_movie = new QMovie(this);
    }

    {
        m_status->setFixedSize(CONST_SIZE_STATUS_SEARCH);
        m_edit_id->setFixedSize(CONST_SIZE_EDIT_SEARCH);
        m_btn_click->setFixedSize(CONST_SIZE_BTN_SEARCH);
        m_lab_gif->setFixedSize(CONST_SIZE_LAB_SEARCH);
        this->setFixedSize(CONST_SIZE_DIALOG_SEARCH);
    }
    
    {
        m_status->addItem("person");
        m_status->addItem("group");
        m_status->setToolTip("请选择搜索类型");
        m_status->setCurrentIndex(1);
        m_edit_id->setText("1");
        
        m_edit_id->setPlaceholderText("请输入id");
        m_btn_click->setText("搜索");

        m_movie->setFileName(":/Icons/MainWindow/loading2.gif");
        m_lab_gif = new QLabel(this);
        m_lab_gif->setMovie(m_movie);
    }

    {
        QWidget *widget_status = new QWidget(this);
        QHBoxLayout *layout_status = new QHBoxLayout(widget_status);
        layout_status->addWidget(m_status);
        layout_status->setAlignment(Qt::AlignCenter);

        QWidget *widget_edit = new QWidget(this);
        QHBoxLayout *layout_edit = new QHBoxLayout(widget_edit);
        layout_edit->setSpacing(30);
        layout_edit->addWidget(m_edit_id);
        layout_edit->setSpacing(10);
        layout_edit->addWidget(m_btn_click);
        layout_edit->addWidget(m_lab_gif);
        layout_edit->setSpacing(0);
        layout_edit->setAlignment(Qt::AlignCenter);
        widget_edit->setLayout(layout_edit);

        QVBoxLayout *layout_main = new QVBoxLayout(this);
        layout_main->addWidget(widget_status);
        layout_main->addWidget(widget_edit);
        this->setLayout(layout_main);
    }
    
    connect(m_btn_click, &QPushButton::clicked, this, [&](){
        __DELAY__
        m_btn_click->setEnabled(false);
        m_status->setEnabled(false);
        m_movie->start();
        
        cJSON *root = cJSON_CreateObject();  
        cJSON_AddNumberToObject(root, "func", (int)E_Send::Action);
        cJSON_AddNumberToObject(root, "action", (int)E_Action::Find);

        cJSON *content = cJSON_CreateObject();
        (m_status->currentText() == "group" ? 
            cJSON_AddNumberToObject(content, "Identity", (int)E_Identity::Group) : 
            cJSON_AddNumberToObject(content, "Identity", (int)E_Identity::Friend));
        cJSON_AddNumberToObject(content, "id", m_edit_id->text().toInt());

        cJSON_AddItemToObject(root, "content", content);
        emit SigSearch(root);
    });
}

void DialogSearch::SlotSearch(cJSON* json){
    m_btn_click->setEnabled(true);
    m_status->setEnabled(true);
    m_movie->setPaused(true);

    QString status = m_status->currentText();
    if(status == "person"){
        PersonInfo info_person;
        info_person.id = cJSON_GetNumberValue(cJSON_GetObjectItem(json, "id"));
        info_person.name = cJSON_GetStringValue(cJSON_GetObjectItem(json, "name"));
        info_person.photo = cJSON_GetStringValue(cJSON_GetObjectItem(json, "photo"));
        m_widget_person->SetInfo(info_person);
        m_widget_person->exec();
    }else {
        GroupInfo info_group;
        info_group.id = cJSON_GetNumberValue(cJSON_GetObjectItem(json, "id"));
        info_group.name = cJSON_GetStringValue(cJSON_GetObjectItem(json, "name"));
        info_group.photo = cJSON_GetStringValue(cJSON_GetObjectItem(json, "photo"));

        /* members */
        cJSON *items = cJSON_GetObjectItem(json, "members");
        for(int i = 0; i < cJSON_GetArraySize(items); i++){
            cJSON * item = cJSON_GetArrayItem(items, i);

            std::shared_ptr<std::pair<PersonInfo, E_Role>>info_members(new std::pair<PersonInfo, E_Role>);
            info_members.get()->first.id = cJSON_GetNumberValue(cJSON_GetObjectItem(item, "id"));
            info_members.get()->first.name = cJSON_GetStringValue(cJSON_GetObjectItem(item, "name"));
            info_members.get()->first.photo = cJSON_GetStringValue(cJSON_GetObjectItem(item, "photo"));
            info_members.get()->second = static_cast<E_Role>(cJSON_GetNumberValue(cJSON_GetObjectItem(item, "role")));

            info_group.members.push_back(info_members);
        }
        
        m_widget_group->SetInfo(info_group);
        m_widget_group->exec();
    }
    cJSON_Delete(json);//释放内存
}
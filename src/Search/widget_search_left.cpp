#include "Search/widget_search_left.h"

WidgetSearchLeft::WidgetSearchLeft(QWidget *parent) : QWidget(parent){
    m_status = new QComboBox(this);
    m_edit_id = new QLineEdit(this);
    m_btn_click = new QPushButton(this);
    m_lab_gif = new QLabel(this);
    m_movie = new QMovie(this);

    m_status->setFixedSize(CONST_SIZE_STATUS_SEARCH_LEFT);
    m_edit_id->setFixedSize(CONST_SIZE_EDIT_SEARCH_LEFT);
    m_btn_click->setFixedSize(CONST_SIZE_BTN_SEARCH_LEFT);
    m_lab_gif->setFixedSize(CONST_SIZE_LAB_SEARCH_LEFT);
    this->setFixedWidth(CONST_WIDTH_WIDGET_SEARCH_LEFT);

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

    QHBoxLayout *layout_btn = new QHBoxLayout(this);
    layout_btn->addWidget(m_btn_click);
    layout_btn->setSpacing(10);
    layout_btn->addWidget(m_lab_gif);
    layout_btn->setAlignment(Qt::AlignLeft);

    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    layout_main->addWidget(m_status);
    layout_main->setSpacing(10);
    layout_main->addWidget(m_edit_id);
    layout_main->addLayout(layout_btn);

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

void WidgetSearchLeft::GetSearch(cJSON* json){
    m_btn_click->setEnabled(true);
    m_status->setEnabled(true);
    m_movie->setPaused(true);

    QString status = m_status->currentText();
    if(status == "person"){
        int id = cJSON_GetNumberValue(cJSON_GetObjectItem(json, "id"));
        std::string name = cJSON_GetStringValue(cJSON_GetObjectItem(json, "name"));
        QPixmap photo;
        photo.loadFromData(QByteArray::fromBase64(QString::fromStdString(cJSON_GetStringValue(cJSON_GetObjectItem(json, "photo"))).toLocal8Bit()));
        std::shared_ptr<PersonInfo>info_person = std::make_shared<PersonInfo>(id, name.c_str(), photo);
    }else {
        GroupInfo info_group;
        info_group.id = cJSON_GetNumberValue(cJSON_GetObjectItem(json, "id"));
        info_group.name = cJSON_GetStringValue(cJSON_GetObjectItem(json, "name"));
        info_group.photo.loadFromData(QByteArray::fromBase64(QString::fromStdString(cJSON_GetStringValue(cJSON_GetObjectItem(json, "photo"))).toLocal8Bit()));

        /* members */
        cJSON *items = cJSON_GetObjectItem(json, "members");
        for(int i = 0; i < cJSON_GetArraySize(items); i++){
            cJSON * item = cJSON_GetArrayItem(items, i);
            std::pair<PersonInfo, E_Role>info_members;
            info_members.first.id = cJSON_GetNumberValue(cJSON_GetObjectItem(item, "id"));
            info_members.first.name = cJSON_GetStringValue(cJSON_GetObjectItem(item, "name"));
            info_members.first.photo.loadFromData(QByteArray::fromBase64(QString::fromStdString(cJSON_GetStringValue(cJSON_GetObjectItem(json, "photo"))).toLocal8Bit()));
            info_members.second = static_cast<E_Role>(cJSON_GetNumberValue(cJSON_GetObjectItem(item, "role")));
            info_group.members.push_back(info_members);
        }
        //m_widget_group->SetInfo(info_group);
        //m_widget_group->exec();
    }
    cJSON_Delete(json);//释放内存
}
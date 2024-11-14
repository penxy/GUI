#include "widget_search.h"

WidgetSearch::WidgetSearch(QWidget *parent) : QWidget(parent){
    m_wid_left = new WidgetSearchLeft(this);





}

void WidgetSearch::SlotSearch(cJSON* json){
    m_wid_left->GetSearch(json);
}


// void DialogSearch::SlotSearch(cJSON* json){
//     m_btn_click->setEnabled(true);
//     m_status->setEnabled(true);
//     m_movie->setPaused(true);

//     QString status = m_status->currentText();
//     if(status == "person"){
//         PersonInfo info_person;
//         info_person.id = cJSON_GetNumberValue(cJSON_GetObjectItem(json, "id"));
//         info_person.name = cJSON_GetStringValue(cJSON_GetObjectItem(json, "name"));
//         info_person.photo.loadFromData(QByteArray::fromBase64(QString::fromStdString(cJSON_GetStringValue(cJSON_GetObjectItem(json, "photo"))).toLocal8Bit()));
//         m_widget_person->SetInfo(info_person);
//         m_widget_person->exec();
//     }else {
//         GroupInfo info_group;
//         info_group.id = cJSON_GetNumberValue(cJSON_GetObjectItem(json, "id"));
//         info_group.name = cJSON_GetStringValue(cJSON_GetObjectItem(json, "name"));
//         info_group.photo.loadFromData(QByteArray::fromBase64(QString::fromStdString(cJSON_GetStringValue(cJSON_GetObjectItem(json, "photo"))).toLocal8Bit()));

//         /* members */
//         cJSON *items = cJSON_GetObjectItem(json, "members");
//         for(int i = 0; i < cJSON_GetArraySize(items); i++){
//             cJSON * item = cJSON_GetArrayItem(items, i);

//             std::shared_ptr<std::pair<PersonInfo, E_Role>>info_members(new std::pair<PersonInfo, E_Role>);
//             info_members.get()->first.id = cJSON_GetNumberValue(cJSON_GetObjectItem(item, "id"));
//             info_members.get()->first.name = cJSON_GetStringValue(cJSON_GetObjectItem(item, "name"));
//             info_members.get()->first.photo.loadFromData(QByteArray::fromBase64(QString::fromStdString(cJSON_GetStringValue(cJSON_GetObjectItem(json, "photo"))).toLocal8Bit()));
//             info_members.get()->second = static_cast<E_Role>(cJSON_GetNumberValue(cJSON_GetObjectItem(item, "role")));

//             info_group.members.push_back(info_members);
//         }
        
//         m_widget_group->SetInfo(info_group);
//         m_widget_group->exec();
//     }
//     cJSON_Delete(json);//释放内存
// }
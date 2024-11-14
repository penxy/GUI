#ifndef __WIDGET_SEARCH_PERSON_H__
#define __WIDGET_SEARCH_PERSON_H__

#include "Config/config.h"

class WidgetSearchPerson : public QWidget{
    Q_OBJECT
public:
    explicit WidgetSearchPerson(QWidget *parent = 0);
    ~WidgetSearchPerson();

    void SetInfo(std::shared_ptr<PersonInfo>info);
signals:
    void SigAddPerson(cJSON *root);
private:
    QLabel *m_lab_id;
    QLabel *m_lab_name;
    QLabel *m_lab_photo;
    QLineEdit *m_edit_msg;
    QPushButton *m_btn_add_person;
    QPixmap m_photo;
};



#endif // __WIDGET_RIGHT_PERSON_H__
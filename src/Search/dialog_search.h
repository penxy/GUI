#ifndef __DIALOG_SEARCH_H__
#define __DIALOG_SEARCH_H__
#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QMovie>
#include <QLabel>

#include "cjson/cJSON.h"
#include "Config/config_struct.h"
#include "dialog_person.h"
#include "dialog_group.h"

class DialogSearch : public QDialog{
    Q_OBJECT
public:
    explicit DialogSearch(QWidget *parent = 0);
signals:
    void SendSearch(cJSON *root);
public slots:
    void slot_recv_search(cJSON* json);
private:
    QComboBox *m_status;
    QLineEdit *m_edit_id;
    QPushButton *m_btn_click;
    QLabel *m_lab_gif;
    QMovie *m_movie;

    PersonInfo m_info_person;
    GroupInfo m_info_group;

    DialogGroup *m_widget_group;
    DialogPerson *m_widget_person;
};


#endif // __DIALOG_SEARCH_H__
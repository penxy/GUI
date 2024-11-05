#ifndef __DIALOG_PERSON_H__
#define __DIALOG_PERSON_H__

#include <QDialog>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "Config/config.h"

class DialogPerson : public QDialog{
    Q_OBJECT
public:
    explicit DialogPerson(QDialog *parent = 0);
    ~DialogPerson();

    void SetInfo(PersonInfo &info);
signals:
    void SigAddPerson(cJSON *root);
private:
    QLabel *m_lab_id;
    QLabel *m_lab_name;
    QLabel *m_lab_photo;
    QLineEdit *m_edit_msg;
    QPushButton *m_btn_add_person;
    QPixmap *m_photo;
};

#endif /* __DIALOG_PERSON_H__ */
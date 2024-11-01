#ifndef __DIALOG_PERSON_H__
#define __DIALOG_PERSON_H__

#include <QDialog>
#include "Config/config.h"

class DialogPerson : public QDialog{
    Q_OBJECT
public:
    explicit DialogPerson(QDialog *parent = 0);
    void SetInfo(PersonInfo &info);
};

#endif /* __DIALOG_PERSON_H__ */
#ifndef __LABEL_ROLE_H__
#define __LABEL_ROLE_H__

#include <QLabel>
#include "Config/config_enum.h"
#include "Config/config_ui.h"

class LabelRole : public QLabel{
public:
    explicit LabelRole(E_Role role, QWidget *parent = 0);
};


#endif // __LABEL_ROLE_H__
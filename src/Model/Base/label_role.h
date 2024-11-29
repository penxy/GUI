#pragma once

#include <QLabel>
#include "config.h"

class LabelRole : public QLabel{
public:
    explicit LabelRole(Type::Info::Role role, QWidget *parent = 0);
};


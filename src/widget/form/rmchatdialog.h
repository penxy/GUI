#pragma once

#include "ui_rmchatdialog.h"
#include <QDialog>


class RmChatDialog : public QDialog
{
    Q_OBJECT
public:
    explicit RmChatDialog(QWidget* parent = nullptr);
protected:
    Ui_RemoveChatDialog ui;
};

#if 0
#pragma once

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QMovie>
#include <QPushButton>
#include "config.h"
#include "Base/label_photo.h"

/**
 * @file find_page.h
 * @class FindPage
 * @brief search friend or group
 * @deprecated 暂时关闭搜索功能
 */
class FindPage : public QDialog{
    Q_OBJECT
public:
    FindPage(QWidget *parent = nullptr);
signals:
    void SigFind(Type::Info::Identity identy, int id);
private:
    QComboBox m_status;

    QLabel m_lab_id;
    QLineEdit m_edit_id;

    QPushButton m_btn_find;
    QMovie m_movie;
    LabelPhoto m_lab_gif;
};

#endif
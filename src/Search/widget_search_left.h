#ifndef __WIDGET_SEARCH_LEFT_H__
#define __WIDGET_SEARCH_LEFT_H__

#include "Config/config.h"
#include <QComboBox>
#include <QMovie>
#include <QLineEdit>
#include "cjson/cJSON.h"

class WidgetSearchLeft : public QWidget{
    Q_OBJECT
public:
    explicit WidgetSearchLeft(QWidget *parent = 0);
signals:
    void SigSearch(cJSON *root);
public:
    void GetSearch(cJSON* json);
private:
    QComboBox *m_status;
    QLineEdit *m_edit_id;
    QPushButton *m_btn_click;
    QMovie *m_movie;
    QLabel *m_lab_gif;
};

#endif /* __WIDGET_SEARCH_LEFT_H__ */
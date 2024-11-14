#ifndef __WIDGET_SEARCH_H__
#define __WIDGET_SEARCH_H__
#include "Config/config.h"
#include "Search/widget_search_left.h"
#include "Search/widget_search_right.h"
#include <QStackedWidget>

class WidgetSearch : public QWidget{
    Q_OBJECT
public:
    explicit WidgetSearch(QWidget *parent = nullptr);
public slots:
    void SlotSearch(cJSON* json);
private:
    WidgetSearchLeft *m_wid_left;
    QStackedWidget *m_wid_right_stack;
};

#endif
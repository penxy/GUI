#pragma once

#include "tool_btn.h"
#include "utils/interface.h"
#include <QWidget>


/**
 * @file tool_page.h
 * @brief 最左侧的工具栏页面
 * @todo 怎么把这个页面的背景搞成黑色
 */
class ToolPage : public QWidget{
    Q_OBJECT
public:
    explicit ToolPage(QWidget *parent = nullptr);
    enum class TypeBtn{
        Head,//头像
        Search,
        ChatPerson,
        ChatGroup,
        Setting
    };
    // DECLARE_SIGNAL(SigTool, TypeBtn btn);
signals:
    void SigTool(TypeBtn type);
private:
    void onClicked();
private:
    ToolBtn *btn_head;
    ToolBtn *btn_search;
    ToolBtn *btn_chat_person;
    ToolBtn *btn_chat_group;
    ToolBtn *btn_setting;
};

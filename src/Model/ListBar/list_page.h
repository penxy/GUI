#pragma once
#include "config.h"

#include <QStackedWidget>
#include <memory>

/**
 * @file list_page.h
 * @class ListPage
 * @brief 中间的好友、群列表页
 * @note 所有对外的接口，信号，槽函数都在这里
 */
class ListPage : public QWidget{
    Q_OBJECT
public:
    explicit ListPage(QWidget *parent = nullptr);
    ~ListPage() = default;

    enum class TypePage{
        NONE,
        Friend,
        Group
    };
    void setPage(TypePage type_page);
    void addList(Type::Info::Identity, std::shared_ptr<void>);
    void delList(Type::Info::Identity, int);
signals:
    void SigListChangeIdx(Type::Info::Identity identity, int idx);
private:
    QStackedWidget m_stack_wid;
};
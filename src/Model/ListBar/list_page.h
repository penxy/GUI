#pragma once
#include "config.h"


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
    void SetPage(TypePage type_page);
signals:
    void SigListChangeIdx(Type::Info::Identity identity, int idx);
public slots:
    void SlotListAdd(Type::Info::Identity, std::shared_ptr<void>);
    void SlotListDel(Type::Info::Identity, int);
private:
    QStackedWidget m_stack_wid;
};
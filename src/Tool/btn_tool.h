#ifndef __BTN_TOOL_H__
#define __BTN_TOOL_H__

#include <QPushButton>
#include <QEvent>

typedef enum {
    Head,//头像
    Search,
    ChatPerson,
    ChatGroup
}BtnType;


class BtnTool : public QPushButton{
    Q_OBJECT
public:
    explicit BtnTool(BtnType type, QStringList&& path_list, QWidget *parent = nullptr);
protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
private:
    BtnType m_type;

    QString m_path_move_in;
    QString m_path_move_out;
};

#endif
#ifndef __BTN_TOOL_H__
#define __BTN_TOOL_H__

#include <QPushButton>
#include <QEvent>


class BtnTool : public QPushButton{
    Q_OBJECT
public:
    enum class TypeBtn{
        Head,//头像
        Search,
        ChatPerson,
        ChatGroup
    };
    explicit BtnTool(TypeBtn type, QStringList&& path_list, QWidget *parent = nullptr);
protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
private:
    TypeBtn m_type;

    QString m_path_move_in;
    QString m_path_move_out;
};

#endif
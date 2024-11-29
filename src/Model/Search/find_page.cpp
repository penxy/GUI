#include "find_page.h"
#include "Base/Layout.h"
#include "config_ui.h"
#include "utils/tool.h"

FindPage::FindPage(QWidget *parent) : QDialog(parent){
    m_status.addItem("friend");
    m_status.addItem("group");
    m_lab_id.setText("id");
    m_edit_id.setPlaceholderText("input you want to find id");
    m_btn_find.setText("find");

    m_movie.setFileName(":/Icons/MainWindow/loading2.gif");
    m_lab_gif.setMovie(&m_movie);
    m_lab_gif.setStyleSheet("");

    m_edit_id.setFixedHeight(40);
    m_lab_gif.setFixedSize(sz::find_gif);
    m_btn_find.setFixedSize(sz::find_btn);
    this->setFixedSize(sz::dialog_wid);

    WidgetBlank *wid_box = new WidgetBlank;
    QHBoxLayout *layout_box = new QHBoxLayout(wid_box);
    layout_box->addWidget(&m_status);

    WidgetBlank *wid_id = new WidgetBlank;
    QHBoxLayout *layout_id = new QHBoxLayout(wid_id);
    layout_id->addWidget(&m_lab_id);
    layout_id->addSpacing(20);
    layout_id->addWidget(&m_edit_id);

    WidgetBlank *wid_btn = new WidgetBlank;
    QHBoxLayout *layout_btn = new QHBoxLayout(wid_btn);
    layout_btn->addWidget(&m_lab_gif);
    layout_btn->setSpacing(100);
    layout_btn->addWidget(&m_btn_find);

    WidgetBlank *wid_main = new WidgetBlank(this);
    QVBoxLayout *layout_main = new QVBoxLayout(wid_main);
    layout_main->setSpacing(0);
    layout_main->addWidget(wid_box);
    layout_main->addWidget(wid_id);
    layout_main->addWidget(wid_btn);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(wid_main);

    QString qss = R"(
        FindPage{
            border-image: url(":/Icons/back-gound.png");
        }
    )";
    this->setStyleSheet(TOOL.getQss(Tool::TypeQss::ComBox).append(TOOL.getQss(Tool::TypeQss::QLabel)).append(qss));

    connect(&m_btn_find, &QPushButton::clicked, this, [&](){
        __DELAY__

        m_btn_find.setEnabled(false);
        m_movie.start();

        //emit SigFind((m_status.currentText() == "Friend" ? Type::Info::Identity::Friend : Type::Info::Identity::Group), m_edit_id.text().toInt());
    });
}

#include "btn_tool.h"
#include "Config/config_ui.h"

#include <QBitmap>
#include <QPixmap>
#include <QPainter>
#include <unistd.h>

BtnTool::BtnTool(TypeBtn type, QStringList&& path_list, QWidget *parent) : QPushButton(parent), m_type(type){
    m_path_move_in = path_list.at(0);
    m_path_move_out = path_list.at(1);
    
    setFixedSize(CONST_SIZE_BTN_TOOL);
    setIconSize(CONST_SIZE_BTN_TOOL);
    setIcon(QIcon(m_path_move_out));
    setStyleSheet("border:none;");
}

void BtnTool::enterEvent(QEvent *event){
    setIcon(QIcon(m_path_move_in));
}

void BtnTool::leaveEvent(QEvent *event){
    setIcon(QIcon(m_path_move_out));
}


/*
//画个框
        QSize size(CONST_SIZE_BTN_TOOL);
        QBitmap mask(size);
        QPainter painter(&mask);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
        painter.setBrush(QColor(0, 0, 0));
        painter.drawRoundedRect(0, 0, size.width(), size.height(), 99, 99);

        QPixmap image;
        image.scaled(size);
        image.setMask(mask);
        
        setIcon(QIcon(image));
        setIconSize(this->size());
        setStyleSheet("border:none;");

*/
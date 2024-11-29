#pragma once

#include "single_model.h"
#include "config.h"
#include <QFile>

class Tool : public Singleton<Tool> {
    friend class Singleton<Tool>;
public:
    Tool (const Tool&) = delete;
    Tool& operator = (const Tool&) = delete;
protected:
    Tool() = default;
public: 
    enum TypeQss{
        ComBox,
        QLabel
    };

    QString getQss(TypeQss type){
        std::string file;
        switch (type) {
            case ComBox:{
                file = FLAGS_qss + "/ComBox.qss";
                break;
            }
            case QLabel:{
                file = FLAGS_qss + "/QLabel.qss";
                break;
            }
            default:
                break;
        }
        QFile fileQss(file.c_str());
        if(fileQss.open(QIODevice::ReadOnly)){
            return QString::fromStdString(fileQss.readAll().toStdString());
        }
        return QString();
    }
};

#define TOOL Tool::get_inst()
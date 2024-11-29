#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "Base/widget_blank.h"
#include "Base/Layout.h"
#include "Base/label_photo.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QPixmap>
#include <QIcon>
#include <QFile>
#include <QList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStackedWidget>
#include <QSize>
#include <QTextEdit>
#include <QKeyEvent>
#include <QFrame>
#include <QVector>


#include <memory>
#include <iostream>
#include <QDebug>

#include "gflags/gflags.h"
#include "utils/interface.h"

// #include "nlohmann/json.hpp"
// using json = nlohmann::json;
//==================================enum===================================//
namespace Type{
    class Info{
    public:
        enum class Role{
            Owner = 0,
            Admin = 1,
            Member = 2
        };
        enum class SelfConfig{
            Name,
            Password
        };
        enum class Identity{
            Friend,
            Group
        };
    };

    enum class Json{
        Request,
        Response
    };

    class Msg{
    public:
        enum class DataType{
            Text,
        };
        enum class Category{
            Message,
            Action,
            File,             // 文件传输, Up/Down/Send[E_File]
        };
        enum class Direction{//发送方向
            Send,
            Recv
        };
        enum class Action{
            Regiest,
            Add,
            Delete,
            Accept,
            Reject, 
            Find, 
            Status,           //[<Status>online/offline]
            ChangeInfo,
        };
        // status
        enum class Status{
            Online,
            Busy,
            Leave,
            Hide
        };
    };
}

//=======================================Class=======================================

namespace ns{
    struct SelfSetting{
        int id;
        std::string name;
        QPixmap photo;
        std::string password;//[MD5]
        Type::Msg::Status status;
    };
    struct FriendInfo{
        int id;
        std::string name;
        QPixmap photo;
        FriendInfo() = default;
        FriendInfo(int id, const char *name, QPixmap photo) : id(id), name(name), photo(photo) {};
    };
    struct GroupInfo{
        int id;
        std::string name;
        QPixmap photo;
        QList<std::pair<FriendInfo, Type::Info::Role>> members;
        GroupInfo() = default;
        GroupInfo(int id, const char *name, QPixmap photo, QList<std::pair<FriendInfo, Type::Info::Role>> members) : id(id), name(name), photo(photo), members(members) {};
    };
    struct MsgContent{
        time_t time;
        std::string content;
        Type::Msg::Direction direction; // 发送者还是接收者
    };
    struct MsgJson{
        int id;
        Type::Msg::Category identity;

        //E_Identity::Group
        int gid = -1;
        Type::Info::Role role;

        MsgContent msg_info;
    };
};

//=======================================define=======================================
#include <QTimer>

//防止按钮多次点击
#define __DELAY__ QTimer::singleShot(200, this, [&](){});

//=======================================Size=========================================

namespace sz{
#ifndef sc
    #define sc static constexpr const
#endif
#ifndef QSize
    #define QSize ::QSize
#endif
    /* dialog-size */
    sc QSize dialog_wid                                                  = QSize(400, 300);

    sc QSize main_window_wid                                             = QSize(1200, 800);
    /* size-widget-tool */
    sc QSize tool_btn                                                    = QSize(50, 50);
    sc int tool_wid                                                      = 55;

    /* size-friend-list */
    sc QSize fd_list_name                                                = QSize(120, 30);
    sc QSize fd_list_photo                                               = QSize(57, 57);
    sc QSize fd_list_wid                                                 = QSize(200, 70);
    
    sc int list_bar_w                                                    = 300;
    /* size-role */
    sc QSize role                                                        = QSize(30, 20);

    /* size-member */
    sc int member_h                                                 = 50;
    sc QSize member_lab                                             = QSize(60, 30);
    sc QSize member_photo                                           = QSize(45, 45);

    /* size-title */
    sc int title_bar_h                                                   = 30;

    //============================================Talk============================================
    /* size-talk-top */
    sc QSize chat_top_lab                                                = QSize(150, 30);
    sc QSize chat_top_photo                                              = QSize(45, 45);
    sc QSize chat_top_wid                                                = QSize(250, 70);

    /* size-talk-mid */                                     
    sc QSize chat_mid_wid_base                                           = QSize(450, 600);

    /* size-talk-buttom */                                      
    sc QSize chat_btm_btn                                                = QSize(70, 30);
    sc int chat_btm_wid_max_h                                            = 120;

    /* size-talk-window */                                      
    sc QSize chat_wid_min                                                = QSize(400, 600);
    sc QSize chat_wid_base                                               = QSize(500, 600);
    //============================================Talk============================================

    //============================================Card============================================
    sc QSize card_id                                                     = QSize(100, 30);
    sc QSize card_name                                                   = QSize(100, 30);
    sc QSize card_photo                                                  = QSize(120, 120);
    sc QSize card_btn                                                    = QSize(70, 30);
    //============================================Card============================================

    //============================================Search============================================
    sc QSize find_gif                                                    = QSize(40, 40);
    sc QSize find_btn                                                    = QSize(60, 40);
    //============================================Search============================================

    /* size-widget-main */
    sc QSize main_wid_base                           = QSize(fd_list_wid.width() + tool_wid + chat_wid_min.width() + 30, 
                                                                                chat_wid_base.height() + title_bar_h + 15);
#ifdef QSize
    #undef QSize
#endif
#ifdef sc
    #undef sc
#endif // sc
}

DECLARE_string(qss);
#endif // __CONFIG_H__
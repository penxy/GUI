#ifndef __WIDGET_CONFIG_H__
#define __WIDGET_CONFIG_H__

#include <QSize>
#include <QHBoxLayout>
#include <QDebug>
#include <iostream>

/* size-main-widget */
static constexpr const QSize CONST_SIZE_MIN_WIDGET_MAIN         = QSize(500, 500);
static constexpr const QSize CONST_SIZE_BASE_WIDGET_MAIN        = QSize(700, 500);

/* size-Dialog-search */
static constexpr const QSize CONST_SIZE_DIALOG_SEARCH           = QSize(350, 200);

static constexpr const QSize CONST_SIZE_LAB_SEARCH              = QSize(10, 10);
static constexpr const QSize CONST_SIZE_EDIT_SEARCH             = QSize(200, 30);
static constexpr const QSize CONST_SIZE_BTN_SEARCH              = QSize(50, 30);
static constexpr const QSize CONST_SIZE_STATUS_SEARCH           = QSize(200, 30);

/* size-Dialog-search-group */
static constexpr const QSize CONST_SIZE_DIALOG_SEARCH_GROUP     = QSize(450, 550);
static constexpr const QSize CONST_SIZE_LAB_SEARCH_GROUP        = QSize(80, 30);//id, count
static constexpr const QSize CONST_SIZE_PHOTO_SEARCH_GROUP      = QSize(80, 80);
static constexpr const QSize CONST_SIZE_LAB_NAME_SEARCH_GROUP   = QSize(200, 30);
static constexpr const QSize CONST_SIZE_BTN_SEARCH_GROUP        = QSize(60, 30);
static constexpr const QSize CONST_SIZE_EDIT_SEARCH_GROUP       = QSize(200, 30);

/* size-Dialog-search-person */
static constexpr const QSize CONST_SIZE_DIALOG_SEARCH_PERSON     = QSize(450, 300);
static constexpr const QSize CONST_SIZE_LAB_SEARCH_PERSON        = QSize(80, 30);//id, count
static constexpr const QSize CONST_SIZE_PHOTO_SEARCH_PERSON      = QSize(80, 80);
static constexpr const QSize CONST_SIZE_BTN_SEARCH_PERSON        = QSize(60, 30);
static constexpr const QSize CONST_SIZE_EDIT_SEARCH_PERSON       = QSize(200, 30);


/* size-btn-tool */
static constexpr const QSize CONST_SIZE_BTN_TOOL                 = QSize(50, 50);
/* size-widget-tool */
static constexpr const int CONST_WIDTH_WIDGET_TOOL               = 60;


/* size-friend-info */
static constexpr const QSize CONST_SIZE_ID_INFO_FRIEND           = QSize(80, 30);
static constexpr const QSize CONST_SIZE_NAME_INFO_FRIEND         = QSize(120, 30);
static constexpr const QSize CONST_SIZE_PHOTO_INFO_FRIEND        = QSize(57, 57);
static constexpr const QSize CONST_SIZE_WIDGET_INFO_FRIEND       = QSize(200, 80);

/* size-role */
static constexpr const QSize CONST_SIZE_ROLE                     = QSize(30, 20);




/* size-width-msg */
static constexpr const QSize CONST_SIZE_WIDGET_MSG               = QSize(400, 120);
static constexpr const QSize CONST_SIZE_SPACER_HORIZONTAL_MSG    = QSize(300, 30);
static constexpr const QSize CONST_SIZE_SPACER_VERTICAL_MSG      = QSize(30, 300);
static constexpr const QSize CONST_SIZE_PHOTO_MSG                = QSize(50, 50); 

/* size-talk-top */
static constexpr const QSize CONST_SIZE_LAB_TALK_TOP             = QSize(150, 30);
static constexpr const QSize CONST_SIZE_PHOTO_TALK_TOP           = QSize(45, 45);
static constexpr const QSize CONST_SIZE_WIDGET_TALK_TOP          = QSize(250, 70);

/* size-talk-mid */
static constexpr const QSize CONST_SIZE_BASE_WIDGET_TALK_MID     = QSize(450, 600);

/* size-talk-buttom */
static constexpr const QSize CONST_SIZE_BTN_TALK_BOTTOM          = QSize(50, 30);
static constexpr const int CONST_HEIGHT_MAX_WIDGET_TALK_BOTTOM   = 120;

/* size-talk-window */
static constexpr const QSize CONST_SIZE_MIN_TALK_WINDOW          = QSize(400, 900);
static constexpr const QSize CONST_SIZE_BASE_TALK_WINDOW         = QSize(500, 1400);

#endif // __WIDGET_CONFIG_H__

#ifndef __WIDGET_CONFIG_H__
#define __WIDGET_CONFIG_H__

#include <QSize>
#include <QHBoxLayout>
#include <QDebug>
#include <iostream>



 


/* size-Dialog-search-person */



/* size-btn-tool */
static constexpr const QSize CONST_SIZE_BTN_TOOL                 = QSize(50, 50);
/* size-widget-tool */
static constexpr const int CONST_WIDTH_WIDGET_TOOL               = 55;


/* size-friend-info-list */
static constexpr const QSize CONST_SIZE_ID_INFO_FRIEND           = QSize(80, 30);
static constexpr const QSize CONST_SIZE_NAME_INFO_FRIEND         = QSize(120, 30);
static constexpr const QSize CONST_SIZE_PHOTO_INFO_FRIEND        = QSize(57, 57);
static constexpr const QSize CONST_SIZE_WIDGET_INFO_FRIEND       = QSize(200, 70);

/* size-role */
static constexpr const QSize CONST_SIZE_ROLE                     = QSize(30, 20);

/* size-list-group-member */
static constexpr const int CONST_SIZE_HEIGHT_INFO                = 50;
static constexpr const QSize CONST_SIZE_LAB_INFO                 = QSize(60, 30);
static constexpr const QSize CONST_SIZE_LAB_PHOTO                = QSize(45, 45);

/* size-width-msg */
static constexpr const QSize CONST_SIZE_WIDGET_MSG               = QSize(400, 120);
static constexpr const QSize CONST_SIZE_SPACER_HORIZONTAL_MSG    = QSize(300, 30);
static constexpr const QSize CONST_SIZE_SPACER_VERTICAL_MSG      = QSize(30, 300);
static constexpr const QSize CONST_SIZE_PHOTO_MSG                = QSize(50, 50); 




/* size-list-bar */
static constexpr const int CONST_WIDTH_WIDGET_LIST_BAR           = 300;


/* size-title */
static constexpr const int CONST_HEIGHT_TITLE_BAR                = 30;

//============================================Talk============================================
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
static constexpr const QSize CONST_SIZE_MIN_TALK_WINDOW          = QSize(400, 600);
static constexpr const QSize CONST_SIZE_BASE_TALK_WINDOW         = QSize(500, 600);


/* size-page-right */
static constexpr const QSize CONST_SIZE_BASE_WIDGET_RIGHT        = QSize(CONST_SIZE_BASE_TALK_WINDOW.width() + CONST_WIDTH_WIDGET_TOOL, CONST_SIZE_BASE_TALK_WINDOW.height());
//============================================Talk============================================


//============================================Search============================================
/* size-search-left */ 
static constexpr const int CONST_WIDTH_WIDGET_SEARCH_LEFT             = CONST_WIDTH_WIDGET_LIST_BAR;
static constexpr const QSize CONST_SIZE_LAB_SEARCH_LEFT               = QSize(10, 10);
static constexpr const QSize CONST_SIZE_EDIT_SEARCH_LEFT              = QSize(180, 30);
static constexpr const QSize CONST_SIZE_BTN_SEARCH_LEFT               = QSize(50, 30);
static constexpr const QSize CONST_SIZE_STATUS_SEARCH_LEFT            = QSize(180, 30);
/* size-search-person */
static constexpr const QSize CONST_SIZE_BASE_WIDGET_SEARCH_PERSON       = CONST_SIZE_BASE_WIDGET_RIGHT;
static constexpr const QSize CONST_SIZE_LAB_SEARCH_PERSON               = QSize(80, 30);//id, count
static constexpr const QSize CONST_SIZE_PHOTO_SEARCH_PERSON             = QSize(80, 80);
static constexpr const QSize CONST_SIZE_BTN_SEARCH_PERSON               = QSize(60, 30);
static constexpr const QSize CONST_SIZE_EDIT_SEARCH_PERSON              = QSize(200, 30);
/* size-search-group */ 
static constexpr const QSize CONST_SIZE_BASE_WIDGET_SEARCH_GROUP        = CONST_SIZE_BASE_WIDGET_SEARCH_PERSON;
static constexpr const QSize CONST_SIZE_LAB_SEARCH_GROUP                = QSize(80, 30);//id, count
static constexpr const QSize CONST_SIZE_PHOTO_SEARCH_GROUP              = QSize(80, 80);
static constexpr const QSize CONST_SIZE_LAB_NAME_SEARCH_GROUP           = QSize(200, 30);
static constexpr const QSize CONST_SIZE_BTN_SEARCH_GROUP                = QSize(60, 30);
static constexpr const QSize CONST_SIZE_EDIT_SEARCH_GROUP               = QSize(200, 30);

//============================================Search============================================




/* size-widget-main */
static constexpr const QSize CONST_SIZE_BASE_WIDGET_MAIN         = QSize(CONST_SIZE_BASE_WIDGET_RIGHT.width() + CONST_WIDTH_WIDGET_TOOL, CONST_SIZE_BASE_TALK_WINDOW.height() + CONST_HEIGHT_TITLE_BAR);


#endif // __WIDGET_CONFIG_H__

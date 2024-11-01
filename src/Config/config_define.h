#ifndef __CONFIG_DEFINE_H__
#define __CONFIG_DEFINE_H__


#include <QTimer>

//防止按钮多次点击
#define __DELAY__ QTimer::singleShot(200, this, [&](){});




#endif // __CONFIG_DEFINE_H__
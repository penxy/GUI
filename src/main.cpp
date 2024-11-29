#if 1
#include <QApplication>
#include "Main/main_wid.h"
#include "Search/find_page.h"
#include <signal.h>
#include <unistd.h>
#include <chrono>
#include <stdio.h>
#include "Card/card.h"

#include "test/wid_test.h"

int main(int argc, char *argv[])  
{  
    google::ParseCommandLineFlags(&argc, &argv, true);
    // alarm(2);
    QApplication app(argc, argv);
    auto time_start = std::chrono::system_clock::now();
    //Card wMain(Type::Info::Identity::Friend, std::static_pointer_cast<void>(std::make_shared<ns::FriendInfo>(ns::FriendInfo(1, "22", QPixmap(":/Icons/image.png")))));
    MainWid wMain;
    printf("use time: %lldms\n", (long long int)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - time_start).count());
    wMain.show();
    return app.exec();
}
#else
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPalette>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // 创建主窗口
    QWidget window;
    window.setWindowTitle("QPalette示例");
    // 创建按钮
    QPushButton button("按钮", &window);
    // 创建调色板
    QPalette palette;
    // 设置窗口背景颜色
    palette.setColor(QPalette::Window, Qt::blue);
    // 设置按钮背景颜色和文本颜色
    palette.setColor(QPalette::Button, Qt::green);
    palette.setColor(QPalette::ButtonText, Qt::white);
    // 应用调色板到窗口
    window.setPalette(palette);
    // 显示窗口
    window.show();
    return app.exec();
}
#endif

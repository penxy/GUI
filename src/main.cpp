#include <QApplication>
#include "Main/main_wid.h"
#include "Search/find_page.h"
#include <signal.h>
#include <unistd.h>
#include <chrono>
#include <stdio.h>
#include "Card/fd_card.h"
#include "args.h"
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
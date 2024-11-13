#include <QApplication>
#include "normal/widget.h"
#include <signal.h>
#include <unistd.h>
#include "MainPage/widget_main.h"
#include <chrono>
#include <stdio.h>

int main(int argc, char *argv[])  
{  
    // alarm(4);
    QApplication app(argc, argv);
    auto time_start = std::chrono::system_clock::now();
    WidgetMain wMain;
    printf("use time: %lldms\n", (long long int)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - time_start).count());
    wMain.show();
    return app.exec();
}

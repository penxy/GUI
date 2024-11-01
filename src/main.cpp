#include <QApplication>
#include "Search/dialog_search.h"  
#include "normal/widget.h"
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])  
{  
    alarm(6);
    QApplication app(argc, argv);
    
    return app.exec();
}

#pragma

#include "Base/wid_base.h"
#include <QMouseEvent>

class MainWid : public WidBase{
    Q_OBJECT
public:
    explicit MainWid(QMainWindow *parent = 0);
};

#include "Layout.h"

Layout::Layout(QBoxLayout::Direction direction, QWidget *parent) : QBoxLayout(direction, parent){
    this->setMargin(0);
}

    

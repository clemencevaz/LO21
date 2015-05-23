#include <iostream>
#include <QApplication>
#include <QWindow>
#include "ProjC.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    agenda& a=agenda::getInstance();
    a.show();
    
    return app.exec();
}
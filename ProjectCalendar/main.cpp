#include <iostream>
#include <QApplication>
#include <QWindow>
#include "ProjC.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    agenda a;
    a.show();
    /*
    QApplication app(argc, argv);
    QLabel* identificateurLabel;
    QHBoxLayout* coucheH1;
    identificateurLabel= new QLabel("identificateur");
    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(identificateurLabel);
    setLayout(coucheH1);*/
    return app.exec();
}

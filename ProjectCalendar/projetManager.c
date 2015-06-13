
#include "projetManager.h"

projectViewer::projectViewer(QWidget *parent): QtMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

}

projectViewer::~projectViewer(){
    delete ui;
}

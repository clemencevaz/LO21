#include "projectviewer.h"
#include "ui_projectviewer.h"

ProjectViewer::ProjectViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectViewer)
{
    ui->setupUi(this);
}

ProjectViewer::~ProjectViewer()
{
    delete ui;
}

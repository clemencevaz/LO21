#include "newprojectwindow.h"
#include "ui_newprojectwindow.h"
#include "projetManager.h"
#include "projet.h"

NewProjectWindow::NewProjectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectWindow)
{
    ui->setupUi(this);
}

NewProjectWindow::~NewProjectWindow()
{
    delete ui;
}


void NewProjectWindow::on_saveNewProjButton_clicked()
{
    ProjetManager& man = ProjetManager::getManager();
    QString nomProj = ui->newProjName->text();
    Projet* newProj = new Projet(nomProj);
    man.addProjet(newProj);
    this->close();
}

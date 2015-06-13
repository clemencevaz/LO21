#include "newproject.h"
#include "projet.h"
#include "ui_newproject.h"

NewProject::NewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProject)
{
    ui->setupUi(this);
}

NewProject::~NewProject()
{
    delete ui;
}

void NewProject::on_saveNewProj_clicked()
{
    QString nom = ui->newProjName->text();
    Projet newProj = new Projet(nom);
    ProjetManager& man = ProjetManager::getManager();
    man.addProjet(newProj);

}

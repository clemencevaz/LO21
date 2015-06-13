#include "projectmain.h"
#include "ui_projectmain.h"
#include "projet.h"
#include "projetManager.h"
#include <QTreeWidgetItem>

projectMain::projectMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::projectMain)
{
    ui->setupUi(this);

    QTreeWidgetItem *item;
    QTreeWidgetItem *child;

    ProjetManager& man = ProjetManager::getManager();
        /*On utilise l'iterator de PM pour avoir tous les Projets et les lister*/
    for(ProjetManager::Iterator  i = man.getIterator(); i.end(); i.next()){
        item = new QTreeWidgetItem();
        item->setText(0, i.current()->getNom());

        for(Projet::Iterator* j = i.current()->getIterator(); j->end(); j->next()){
            child = new QTreeWidgetItem();
            child->setText(0,j->current()->get_titre());
            item->addChild(child);
        }
        //ui->projTreeView->addTopLevelItem(item);
        ui->projTreeView->addTopLevelItem(item);
    }

}

projectMain::~projectMain()
{
    delete ui;
}



void projectMain::on_taskProgram_clicked()
{

}


void projectMain::on_projTreeView_itemActivated(QTreeWidgetItem *item, int column)
{
    QString projNom = item->text(0);
    ProjetManager& man = ProjetManager::getManager();
    for(ProjetManager::Iterator i = man.getIterator(); i.end(); i.next()){
        if (i.current()->getNom() == projNom){
            ui->projNameLabel->setText(projNom);
            ui->projTasksNbLabel->setText(QVariant(i.current()->getNbTasks()).toString());
            break;
        }
    }
}

void projectMain::on_projTreeView_activated(const QModelIndex &index)
{

}

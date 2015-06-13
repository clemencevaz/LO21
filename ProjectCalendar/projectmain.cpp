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
    //il faut donner la tache t
//    FenetreProgrammerTache* fenetre=new FenetreProgrammerTache(TacheUnitaire& t);
//    fenetre.show();
}

void projectMain::on_projTreeView_activated(const QModelIndex &index)
{

}

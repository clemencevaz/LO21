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
        item->setText(1,"proj");
        for(Projet::Iterator* j = i.current()->getIterator(); j->end(); j->next()){
            child = new QTreeWidgetItem();
            child->setText(0,j->current()->get_titre());
            child->setText(1,"task");
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


void projectMain::on_projTreeView_itemActivated(QTreeWidgetItem *item, int column)
{
    ProjetManager& man = ProjetManager::getManager();
    if (item->text(1) == "proj"){
        QString projNom = item->text(0);
        for(ProjetManager::Iterator i = man.getIterator(); i.end(); i.next()){
            if (i.current()->getNom() == projNom){
                ui->projNameLabel->setText(projNom);
                ui->projTasksNbLabel->setText(QVariant(i.current()->getNbTasks()).toString());
                break;
            }
        }
    }else if (item->text(1) == "task"){
        QTreeWidgetItem* parent = item->parent();
        QString projNom = parent->text(0);
        Projet* projParent = new Projet("");
        for(ProjetManager::Iterator i = man.getIterator(); i.end(); i.next()){
            if (i.current()->getNom() == projNom){
                projParent = i.current();
                break;
            }
        }

        for (Projet::Iterator* it = projParent->getIterator();  it->end(); it->next()){
            if(it->current()->get_titre() == item->text(0)){
                ui->taskNameLabel->setText(it->current()->get_titre());
                ui->taskDescriptionLabel->setText("Description de La Tache s'il y en avait");
                QString date = "";
                date+= QVariant(it->current()->get_date_disp().getJour()).toString() + "/";
                date+= QVariant(it->current()->get_date_disp().getMois()).toString() + "/";
                date+= QVariant(it->current()->get_date_disp().getAnnee()).toString();

                ui->taskBeginLabel->setText(date);

                date = "";
                date+= QVariant(it->current()->get_echeance().getJour()).toString() + "/";
                date+= QVariant(it->current()->get_echeance().getMois()).toString() + "/";
                date+= QVariant(it->current()->get_echeance().getAnnee()).toString();

                ui->taskEndLabel_2->setText(date);
                break;
            }
        }
    }
}

void projectMain::on_projTreeView_activated(const QModelIndex &index)
{

}

void projectMain::on_taskProgram_2_clicked()
{

}

void projectMain::on_composeButton_clicked()
{

}

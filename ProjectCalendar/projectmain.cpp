#include "projectmain.h"
#include "ui_projectmain.h"
#include "projet.h"
#include "projetManager.h"
#include <QTreeWidgetItem>

projectMain::projectMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::projectMain)
{
    QTreeWidgetItem *item;

    ui->setupUi(this);
    ProjetManager& man = ProjetManager::getManager();
        /*On utilise l'iterator de PM pour avoir tous les Projets et les lister*/
        for(ProjetManager::Iterator  i = man.getIterator(); i.end(); i.next()){
            item = new QTreeWidgetItem();
            item->setText(0, i.current()->getNom());
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

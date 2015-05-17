#include "tacheediteur.h"

#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>
/*
TacheEditeur::TacheEditeur(Tache& tacheToEdit, QWidget *parent) :
        QWidget(parent),tache(tacheToEdit){
    this->setWindowTitle(QString("Edition de la tâche ")+tacheToEdit.getId());


    // creation des labels
    identificateurLabel= new QLabel("identificateur",this);;
    titreLabel= new QLabel("titre",this);;
    disponibiliteLabel= new QLabel("disponibilité",this);;
    echeanceLabel= new QLabel("échéance",this);
    dureeLabel= new QLabel("durée",this);

    // création des composants éditables
    identificateur = new QLineEdit(tacheToEdit.getId(),this);
    titre = new QTextEdit(tacheToEdit.getTitre(),this);

    preemptive=new QCheckBox("preemptive",this);;
    preemptive->setChecked(tacheToEdit.isPreemptive());

    disponibilite=new QDateEdit(tacheToEdit.getDateDisponibilite(),this);
    echeance=new QDateEdit(tacheToEdit.getDateEcheance(),this);
    hDuree=new QSpinBox(this);
    hDuree->setMinimum(0); hDuree->setSuffix(" heure(s)");
    hDuree->setValue(tacheToEdit.getDuree().getHeure());
    mDuree=new QSpinBox(this);
    mDuree->setRange(0,59); mDuree->setSuffix(" minute(s)");
    mDuree->setValue(tacheToEdit.getDuree().getMinute());

    sauver= new QPushButton("Sauver", this);
    sauver->setEnabled(false);
    annuler= new QPushButton("Annuler", this);
    // diposition des couches
    coucheH1 = new QHBoxLayout;
    coucheH1->addWidget(identificateurLabel);
    coucheH1->addWidget(identificateur);
    coucheH1->addWidget(preemptive);
    coucheH2 = new QHBoxLayout;
    coucheH2->addWidget(titreLabel);
    coucheH2->addWidget(titre);

    coucheH3 = new QHBoxLayout;
    coucheH3->addWidget(disponibiliteLabel);
    coucheH3->addWidget(disponibilite);
    coucheH3->addWidget(echeanceLabel);
    coucheH3->addWidget(echeance);
    coucheH3->addWidget(dureeLabel);
    coucheH3->addWidget(hDuree);
    coucheH3->addWidget(mDuree);
    coucheH4 = new QHBoxLayout;
    coucheH4->addWidget(annuler);
    coucheH4->addWidget(sauver);

    couche = new QVBoxLayout;
    couche->addLayout(coucheH1);
    couche->addLayout(coucheH2);
    couche->addLayout(coucheH3);
    couche->addLayout(coucheH4);
    setLayout(couche);
    // connections
    QObject::connect(sauver,SIGNAL(clicked()),this,SLOT(sauverTache()));
    QObject::connect(identificateur,SIGNAL(textEdited(QString)),this,SLOT(activerSauver(QString)));
    QObject::connect(titre,SIGNAL(textChanged()),this,SLOT(activerSauver()));
    QObject::connect(preemptive,SIGNAL(clicked()),this,SLOT(activerSauver()));
    QObject::connect(hDuree,SIGNAL(valueChanged(QString)),this,SLOT(activerSauver(QString)));
    QObject::connect(mDuree,SIGNAL(valueChanged(QString)),this,SLOT(activerSauver(QString)));
    QObject::connect(echeance,SIGNAL(dateChanged(const QDate&)),this,SLOT(coherenceDates(const QDate&)));
    QObject::connect(disponibilite,SIGNAL(dateChanged(const QDate&)),this,SLOT(coherenceDates(const QDate&)));
    QObject::connect(annuler,SIGNAL(clicked()),this,SLOT(close()));
}

void TacheEditeur::sauverTache(){
    if (TacheManager::getInstance().isTacheExistante(identificateur->text())&& &TacheManager::getInstance().getTache(identificateur->text())!=&tache){
         QMessageBox::warning(this, "Sauvegarde impossible", "Identificateur tâche déjà existant...");
    }
    tache.setId(identificateur->text());
    if (preemptive->isChecked()) tache.setPreemptive(); else tache.setNonPreemptive();
    tache.setTitre(titre->toPlainText());
    tache.setDuree(Duree(hDuree->value(),mDuree->value()));
    tache.setDatesDisponibiliteEcheance(disponibilite->date(),echeance->date());
    QMessageBox::information(this, "Sauvegarde", "Tache sauvegardée...");
    sauver->setEnabled(false);
}

void TacheEditeur::activerSauver(QString){
    sauver->setEnabled(true);
}

void TacheEditeur::coherenceDates(const QDate & date){
    sauver->setEnabled(true);
    if (date==disponibilite->date() && echeance->date()<disponibilite->date()) echeance->setDate(disponibilite->date());
    if (date==echeance->date() && echeance->date()<disponibilite->date()) disponibilite->setDate(echeance->date());
}
*/



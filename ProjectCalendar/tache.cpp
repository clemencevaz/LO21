#include "ProjC.h"
#include "projetManager.h"


FenetreChoixTypeTache::FenetreChoixTypeTache(){
    titreLabel= new QLabel("Créer une tâche");
    coucheV1= new QVBoxLayout;
    unitaire=new QRadioButton("Tache unitaire");
    composite=new QRadioButton("Tache composite");
    coucheV1->addWidget(unitaire);
    coucheV1->addWidget(composite);
    valide=new QPushButton("Valider");
    coucheV1->addWidget(valide);
    setLayout(coucheV1);
   QObject::connect(valide,SIGNAL(clicked()),this,SLOT(fenetreTacheUnitaire()));
}



void FenetreChoixTypeTache::fenetreTacheUnitaire(){
  if(unitaire->isChecked()){
    FenetreCreerTacheUnitaire * fenetreuni = new FenetreCreerTacheUnitaire;
    fenetreuni->show();
   }
  else if (composite->isChecked()){
    FenetreCreerTacheComposite * fenetrecompo = new FenetreCreerTacheComposite;
    fenetrecompo->show();
  }
}


//TACHE UNITAIRE

FenetreCreerTacheUnitaire::FenetreCreerTacheUnitaire(){
    titreLabel= new QLabel("Créer une tâche");
    nom= new QLabel("Titre: ");
    textprojet=new QLabel("Projet: ");
    textdatedispo=new QLabel("Date de disponibilité: ");
    textedateeche= new QLabel("Date d'échéance");
    textpreemptive=new QLabel("Preemptive");
    duree=new QLabel("Durée (h-m): ");
    titre=new QLineEdit();
    datedispo= new QDateEdit();
    dateeche=new QDateEdit();
    hActDuree=new  QSpinBox();
    mActDuree=new  QSpinBox();
    preemptive=new QCheckBox();
    projet=new QComboBox();

    for(ProjetManager::Iterator i =ProjetManager::getManager().getIterator(); i.end(); i.next()){
        projet->addItem(i.current()->getNom());
    }


    coucheV1= new QVBoxLayout;
    coucheh1 = new QHBoxLayout;
    coucheh2 = new QHBoxLayout;

    datedispo->setDate(QDate::currentDate());
    dateeche->setDate(QDate::currentDate());

    coucheV1->addWidget(titreLabel);
    coucheV1->addWidget(nom);
    coucheV1->addWidget(titre);
    coucheV1->addWidget(textprojet);
    coucheV1->addWidget(projet);
    coucheV1->addWidget(textpreemptive);
    coucheV1->addWidget(preemptive);

    coucheh2->addWidget(textdatedispo);
    coucheh2->addWidget(datedispo);
    coucheh2->addWidget(textedateeche);
    coucheh2->addWidget(dateeche);
    coucheV1->addLayout(coucheh2);

    coucheh1->addWidget(duree);
    coucheh1->addWidget(hActDuree);
    coucheh1->addWidget(mActDuree);

    coucheV1->addLayout(coucheh1);

    Enregistrer=new QPushButton("Enregistrer");
    coucheV1->addWidget(Enregistrer);

    setLayout(coucheV1);

    QObject::connect(Enregistrer,SIGNAL(clicked()),this,SLOT(sauverTache()));
}

void FenetreCreerTacheUnitaire::sauverTache(){
    if(TacheUnitaire* newtach=new TacheUnitaire(titre->text(),Date(datedispo->date().day(),datedispo->date().month(),datedispo->date().year()),
                                               Date(dateeche->date().day(),dateeche->date().month(),dateeche->date().year()),1,Duree(hActDuree->value(),mActDuree->value()),preemptive->checkState()))
    {
        QMessageBox msgBox;
        msgBox.setText("La Tache a été ajoutée");
        msgBox.exec();
        Projet* p=ProjetManager::getManager().getProjet(projet->currentIndex());
        (*p).addTache(newtach);
        this->close();
    }
}


//TACHE COMPOSITE
FenetreCreerTacheComposite::FenetreCreerTacheComposite(){
    titreLabel= new QLabel("Créer une tâche composite");
    nom= new QLabel("Titre: ");
    textprojet=new QLabel("Projet: ");
    textdatedispo=new QLabel("Date de disponibilité: ");
    textedateeche= new QLabel("Date d'échéance");
    titre=new QLineEdit();
    datedispo= new QDateEdit();
    dateeche=new QDateEdit();
    projet=new QComboBox();

    for(ProjetManager::Iterator i =ProjetManager::getManager().getIterator(); i.end(); i.next()){
        projet->addItem(i.current()->getNom());
    }


    coucheV1= new QVBoxLayout;
    coucheh1 = new QHBoxLayout;

    datedispo->setDate(QDate::currentDate());
    dateeche->setDate(QDate::currentDate());

    coucheV1->addWidget(titreLabel);
    coucheV1->addWidget(nom);
    coucheV1->addWidget(titre);
    coucheV1->addWidget(textprojet);
    coucheV1->addWidget(projet);

    coucheh1->addWidget(textdatedispo);
    coucheh1->addWidget(datedispo);
    coucheh1->addWidget(textedateeche);
    coucheh1->addWidget(dateeche);



    coucheV1->addLayout(coucheh1);

    Enregistrer=new QPushButton("Enregistrer");
    coucheV1->addWidget(Enregistrer);

    setLayout(coucheV1);

    QObject::connect(Enregistrer,SIGNAL(clicked()),this,SLOT(sauverTacheC()));
}

void FenetreCreerTacheComposite::sauverTacheC(){
    if(TacheComposite* newtach=new TacheComposite(titre->text(),Date(datedispo->date().day(),datedispo->date().month(),datedispo->date().year()),
                                                  Date(dateeche->date().day(),dateeche->date().month(),dateeche->date().year()),1))
    {
        QMessageBox msgBox;
        msgBox.setText("La Tache a été ajoutée");
        msgBox.exec();
        Projet* p=ProjetManager::getManager().getProjet(projet->currentIndex());
        (*p).addTache(newtach);
        this->close();
    }
}

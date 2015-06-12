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

FenetreChoixProjet::FenetreChoixProjet(){
  coucheV1= new QVBoxLayout;
  listeprojets=new QComboBox (listeprojets);
  Enregistrer=new QPushButton("Enregistrer");
  coucheV1->addWidget(Enregistrer);

  setLayout(coucheV1);

  /*ProjetManager& p = ProjetManager::getManager();
  ProjetManager::Iterator * it;
  for (it=ProjetManager::getIterator();it!=end();it.next())
      listeprojets.addItem(*it->titre);*/

  QObject::connect(Enregistrer,SIGNAL(clicked()),this,SLOT(FenetreChoixTypeTache()));
}

void FenetreChoixTypeTache::fenetreTacheUnitaire(){
  if(unitaire->isChecked()){
    FenetreCreerTacheUnitaire::FenetreCreerTacheUnitaire * fenetreuni = new FenetreCreerTacheUnitaire::FenetreCreerTacheUnitaire;
    fenetreuni->show();
   }
  else if (composite->isChecked()){
    FenetreCreerTacheComposite::FenetreCreerTacheComposite * fenetrecompo = new FenetreCreerTacheComposite::FenetreCreerTacheComposite;
    fenetrecompo->show();
  }
}


//TACHE UNITAIRE

FenetreCreerTacheUnitaire::FenetreCreerTacheUnitaire(){
    titreLabel= new QLabel("Créer une tâche");
    nom= new QLabel("Nom: ");
    description=new QLabel("Description: ");
    duree=new QLabel("Durée (h-m): ");
    ActNom=new QLineEdit();
    ActDesc =new QTextEdit();
    hActDuree=new  QSpinBox();
    mActDuree=new  QSpinBox();

    coucheV1= new QVBoxLayout;
    coucheh1 = new QHBoxLayout;

    coucheV1->addWidget(titreLabel);
    coucheV1->addWidget(nom);
    coucheV1->addWidget(ActNom);
    coucheV1->addWidget(description);
    coucheV1->addWidget(ActDesc);

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
   /* if(Activite* activite=new Activite(ActNom->text(),ActDesc->toPlainText(),Duree(hActDuree->value(),mActDuree->value())))
    {
        QMessageBox msgBox;
        msgBox.setText("L'Activité a été crée");
        msgBox.exec();
        FenetreProgrammerActivite* programactivite= new FenetreProgrammerActivite(*activite);
        programactivite->show();
        this->close();
    }*/
}


//TACHE COMPOSITE
FenetreCreerTacheComposite::FenetreCreerTacheComposite(){
  titreLabel= new QLabel("Créer une tâche composite");
  nom= new QLabel("Nom: ");
  ActNom=new QLineEdit();
  ActDesc =new QTextEdit();

  coucheV1= new QVBoxLayout;
  coucheh1 = new QHBoxLayout;

  coucheV1->addWidget(titreLabel);
  coucheV1->addWidget(nom);
  coucheV1->addWidget(ActNom);
  coucheV1->addWidget(ActDesc);

  coucheV1->addLayout(coucheh1);

  Enregistrer=new QPushButton("Enregistrer");
  coucheV1->addWidget(Enregistrer);

  setLayout(coucheV1);

  QObject::connect(Enregistrer,SIGNAL(clicked()),this,SLOT(sauverTacheC()));
}

void FenetreCreerTacheComposite::sauverTacheC(){

}

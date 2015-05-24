#include "activite.h"

FenetreCreerActivite::FenetreCreerActivite(){
    titreLabel= new QLabel("Créer une activite");
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

    QObject::connect(Enregistrer,SIGNAL(clicked()),this,SLOT(sauverActivite()));

}
void FenetreCreerActivite::sauverActivite(){
    if(Activite* activite=new Activite(ActNom->text(),ActDesc->toPlainText(),Duree(hActDuree->value(),mActDuree->value())))
    {
        QMessageBox msgBox;
        msgBox.setText("L'Activité a été crée");
        msgBox.exec();
    }
    this->close();
}

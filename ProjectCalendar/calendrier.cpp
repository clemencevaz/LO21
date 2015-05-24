#include "calendrier.h"
agenda::AgendaHandler agenda::agendahandler = agenda::AgendaHandler();

agenda& agenda::getInstance() {
    if(agendahandler.instance==0) agendahandler.instance = new agenda;
    return* agendahandler.instance;
}

void agenda::libererInstance() {
    delete agendahandler.instance;
    agendahandler.instance=0;
}

agenda::agenda() {
    progs.reserve(10);
    titreLabel= new QLabel("Agenda");
    CreerActivite=new QPushButton("Créer une Activité", this);
    Afficher=new QPushButton("Afficher",this);

    coucheh1 = new QHBoxLayout;
    coucheh1->addWidget(titreLabel);
    coucheh1->addWidget(CreerActivite);
    coucheh1->addWidget(Afficher);
    setLayout(coucheh1);

    QObject::connect(CreerActivite,SIGNAL(clicked()),this,SLOT(fenetreActivite()));
    QObject::connect(Afficher,SIGNAL(clicked()),this,SLOT(afficher()));


}

void agenda::afficher(){

    for(std::vector<programmation*>::const_iterator it=progs.cbegin();it!=progs.cend();it++)
        if(*it!=0)
        {
            (*it)->afficher();
        }
}

void programmationActivite::afficher() const {
//    QLabel* nom;
//    QLabel* description;
//    QLabel* duree;
//    QLabel* date;
//    QLabel* horaire;
//    QHBoxLayout* coucheH1;
//    QVBoxLayout* coucheV1;
//    nom= new QLabel();
//    //nom->setText(this->getActivite().getNom());
//    description=new QLabel();
//    //description->setText(this->getActivite().getDescription());
//    duree=new QLabel();
//    //duree->setText(this->getActivite().getDuree().getDureeEnMinutes());
//    date=new QLabel();
//    date->setText(QVariant(programmation::getDate().getJour()).toString());
//    horaire=new QLabel();
//    horaire->setText(programmation::getHoraire().getHeure()+":"+programmation::getHoraire().getMinute());
//    coucheH1=new QHBoxLayout();
//    coucheV1=new QVBoxLayout();

//    coucheV1->addWidget(nom);
//    coucheV1->addWidget(description);
//    coucheV1->addWidget(duree);
//    coucheH1->addWidget(date);
//    coucheH1->addWidget(horaire);


        QString msg;
        msg+="Affichage de l'activité :";
        //msg+=activite.getDescription();
        QMessageBox msgBox;
        msgBox.setText(msg);
        msgBox.exec();
}

void agenda::fenetreActivite(){
    FenetreCreerActivite* fenetre= new FenetreCreerActivite;
    fenetre->show();
}

programmation& agenda::ajouterProgrammationTache(const TIME::Date& d, const TIME::Horaire& h) {
    programmationTache* newprog=new programmationTache(d,h);
    progs.push_back(newprog);
    return *newprog;
}
programmation& agenda::ajouterProgrammationActivite(const Activite& a, const TIME::Date& d, const TIME::Horaire& h) {
    programmationActivite* newprog=new programmationActivite(a,d,h);
    progs.push_back(newprog);
    return *newprog;
}

FenetreProgrammerActivite::FenetreProgrammerActivite(Activite& a): activite(a){
    titreLabel = new QLabel("Programmer une activité");
    nom = new QLabel(this);
    nom->setText(QVariant(a.getNom()).toString());
    description=new QLabel();
    description->setText(a.getDescription());
    duree=new QLabel();
    duree->setText(QVariant(a.getDuree().getDureeEnMinutes()).toString());
    date= new QLabel("Date: ");
    horaire= new QLabel("Horaire: (h-m)");
    ProgDate= new QDateEdit();
    ProgDate->setDate(QDate::currentDate());
    ProgHh= new QSpinBox();
    ProgHm = new QSpinBox();

    coucheV1= new QVBoxLayout();
    coucheV1->addWidget(titreLabel);
    coucheV1->addWidget(nom);
    coucheV1->addWidget(description);
    coucheV1->addWidget(duree);

    coucheH1= new QHBoxLayout();
    coucheH1->addWidget(date);
    coucheH1->addWidget(ProgDate);

    coucheH2= new QHBoxLayout();
    coucheH2->addWidget(horaire);
    coucheH2->addWidget(ProgHh);
    coucheH2->addWidget(ProgHm);

    Enregistrer=new  QPushButton("Enregistrer");
    coucheV1->addLayout(coucheH1);
    coucheV1->addLayout(coucheH2);
    coucheV1->addWidget(Enregistrer);

    setLayout(coucheV1);
    QObject::connect(Enregistrer,SIGNAL(clicked()),this,SLOT(enregistrer()));

}

void FenetreProgrammerActivite::enregistrer(){
    programmation progact = agenda::getInstance().ajouterProgrammationActivite(activite, Date(ProgDate->date().day(),ProgDate->date().month(),ProgDate->date().year()),Horaire(ProgHh->value(), ProgHm->value()));
    if(&progact!=0){
        QMessageBox msgBox;
        msgBox.setText("L'Activité a été programmée");
        msgBox.exec();
        this->close();
    }
}


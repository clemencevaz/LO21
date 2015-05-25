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
    //Titre en haut de page
    titreLabel= new QLabel("Agenda");

    //barre d'outils
    CreerActivite=new QPushButton("Créer une Activité", this);
    Afficher=new QPushButton("Afficher",this);
    coucheh1 = new QHBoxLayout;
    coucheh1->addWidget(CreerActivite);
    coucheh1->addWidget(Afficher);

    //Affichage de la semaine
    QString msgsemaine;
    msgsemaine+="Semaine du ";
    msgsemaine+="25/05/2015";//date du 1er jour de la semaine
    msgsemaine+=" au ";
    msgsemaine+="31/05/2015";//date du dernier jour de la semaine
    textsemaine=new QLabel(msgsemaine);

    //Affichage des programmations de la semaine
    affprogs=new QGridLayout;
        //jours de la semaine en haut de la grille
    QString jheure("Heure");
    QLabel* Ljheure;
    Ljheure=new QLabel();
    Ljheure->setText(jheure);
    QString j1;
    j1+="Lundi ";
    j1+="25"; //n° du jour du lundi
    QLabel* Lj1;
    Lj1=new QLabel();
    Lj1->setText(j1);
    QString j2;
    j2+="Mardi ";
    j2+="26"; //n° du jour du mardi
    QLabel* Lj2;
    Lj2=new QLabel;
    Lj2->setText(j2);
    QString j3;
    j3+="Mercredi ";
    j3+="27"; //n° du jour du mercredi
    QLabel* Lj3;
    Lj3=new QLabel;
    Lj3->setText(j3);
    QString j4;
    j4+="Jeudi ";
    j4+="28"; //n° du jour du jeudi
    QLabel* Lj4;
    Lj4=new QLabel;
    Lj4->setText(j4);
    QString j5;
    j5+="Vendredi ";
    j5+="29"; //n° du jour du vendredi
    QLabel* Lj5;
    Lj5=new QLabel;
    Lj5->setText(j5);
    QString j6;
    j6+="Samedi ";
    j6+="30"; //n° du jour du samedi
    QLabel* Lj6;
    Lj6=new QLabel;
    Lj6->setText(j6);
    QString j7;
    j7+="Dimanche ";
    j7+="31"; //n° du jour du dimanche
    QLabel* Lj7;
    Lj7= new QLabel;
    Lj7->setText(j7);

    QString textheure;
    unsigned int k=8;
    for(unsigned i=0;i<12;i++)
    {
        textheure=QVariant(k).toString();
        textheure+="h";
        heures[i]=new QLabel;
        heures[i]->setText(textheure);
        affprogs->addWidget(heures[i],i+1,0);
        k++;
    }

    affprogs->addWidget(Ljheure,0,0);
    affprogs->addWidget(Lj1,0,1);
    affprogs->addWidget(Lj2,0,2);
    affprogs->addWidget(Lj3,0,3);
    affprogs->addWidget(Lj4,0,4);
    affprogs->addWidget(Lj5,0,5);
    affprogs->addWidget(Lj6,0,6);
    affprogs->addWidget(Lj7,0,7);

    //page en vertical
    couchev1= new QVBoxLayout;
    couchev1->addWidget(titreLabel);//1 niveau titre
    couchev1->addLayout(coucheh1);//2 niveau barre d'outils
    couchev1->addWidget(textsemaine);//3 niveau information sur la semaine affichée
    couchev1->addLayout(affprogs);

    //Layout
    setLayout(couchev1);

    //actions
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
    Activite act=this->activite;
    QLabel* nom;
//    QLabel* description;
//    QLabel* duree;
//    QLabel* date;
//    QLabel* horaire;
//    QHBoxLayout* coucheH1;
//    QVBoxLayout* coucheV1;
    nom= new QLabel();
    nom->setText(act.getNom());
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
    msg+=act.getNom();
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();

    agenda::getInstance().layout()->addWidget(nom);
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
    programmationActivite* newprog= new programmationActivite(a,d,h);
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


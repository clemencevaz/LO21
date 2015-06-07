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

Date& agenda::getJour1(){
    return *jour1;
}
void agenda::setJour1(const Date& d){
    jour1=new Date(d);
}

agenda::agenda() {
    progs.reserve(10);
    //Titre en haut de page
    titreLabel= new QLabel("Agenda");

    //barre d'outils
    CreerActivite=new QPushButton("Créer une Activité", this);
    CreerTache=new QPushButton("Créer une Tâche", this);
    Afficher=new QPushButton("Afficher",this);
    coucheh1 = new QHBoxLayout;
    coucheh1->addWidget(CreerActivite);
    coucheh1->addWidget(CreerTache);
    coucheh1->addWidget(Afficher);

    //Affichage de la semaine
    ChoisirJ1= new QPushButton("1er jour");

    QString msgsemaine;
    msgsemaine+="Semaine du ";
    msgsemaine+="25/05/2015";//date du 1er jour de la semaine
    msgsemaine+=" au ";
    msgsemaine+="31/05/2015";//date du dernier jour de la semaine
    textsemaine=new QLabel(msgsemaine);

    jour1=new Date(1,6,2015);

    //Affichage des programmations de la semaine
    affprogs=new QGridLayout;
        //jours de la semaine en haut de la grille
    QString j1;
    j1+="Lundi ";
    j1+=QVariant(jour1->getJour()).toString(); //n° du jour du lundi
    QLabel* Lj1;
    Lj1=new QLabel();
    Lj1->setText(j1);
    QString j2;
    j2+="Mardi ";
    j2+=QVariant(jour1->demain().getJour()).toString(); //n° du jour du mardi
    QLabel* Lj2;
    Lj2=new QLabel;
    Lj2->setText(j2);
    QString j3;
    j3+="Mercredi ";
    j3+=QVariant(jour1->demain().demain().getJour()).toString(); //n° du jour du mercredi
    QLabel* Lj3;
    Lj3=new QLabel;
    Lj3->setText(j3);
    QString j4;
    j4+="Jeudi ";
    j4+=QVariant(jour1->demain().demain().demain().getJour()).toString(); //n° du jour du jeudi
    QLabel* Lj4;
    Lj4=new QLabel;
    Lj4->setText(j4);
    QString j5;
    j5+="Vendredi ";
    j5+=QVariant(jour1->demain().demain().demain().demain().getJour()).toString(); //n° du jour du vendredi
    QLabel* Lj5;
    Lj5=new QLabel;
    Lj5->setText(j5);
    QString j6;
    j6+="Samedi ";
    j6+=QVariant(jour1->demain().demain().demain().demain().demain().getJour()).toString(); //n° du jour du samedi
    QLabel* Lj6;
    Lj6=new QLabel;
    Lj6->setText(j6);
    QString j7;
    j7+="Dimanche ";
    j7+=QVariant(jour1->demain().demain().demain().demain().demain().demain().getJour()).toString(); //n° du jour du dimanche
    QLabel* Lj7;
    Lj7= new QLabel;
    Lj7->setText(j7);


    affprogs->addWidget(Lj1,0,0);
    affprogs->addWidget(Lj2,0,1);
    affprogs->addWidget(Lj3,0,2);
    affprogs->addWidget(Lj4,0,3);
    affprogs->addWidget(Lj5,0,4);
    affprogs->addWidget(Lj6,0,5);
    affprogs->addWidget(Lj7,0,6);



    //page en vertical
    couchev1= new QVBoxLayout;
    couchev1->addWidget(titreLabel);//1 niveau titre
    couchev1->addLayout(coucheh1);//2 niveau barre d'outils
    couchev1->addWidget(ChoisirJ1);//choisir le premier jour
    couchev1->addWidget(textsemaine);//3 niveau information sur la semaine affichée
    couchev1->addLayout(affprogs);

    //Layout
    setLayout(couchev1);

    //actions
    QObject::connect(CreerActivite,SIGNAL(clicked()),this,SLOT(fenetreActivite()));
    QObject::connect(CreerTache,SIGNAL(clicked()),this,SLOT(fenetreCreerTache()));
    QObject::connect(Afficher,SIGNAL(clicked()),this,SLOT(afficher()));
    QObject::connect(ChoisirJ1,SIGNAL(clicked()),this,SLOT(choixj1()));
}
void agenda::choixj1(){
    QCalendarWidget* calendar;
    calendar=new QCalendarWidget();
    calendar->setGridVisible(true);
    calendar->show();

}

void agenda::afficher(){

    //on récupère la taille de chaque vjour
    int tabi[7];
    tabi[0]=(int)vjour1.size();
    tabi[1]=(int)vjour2.size();
    tabi[2]=(int)vjour3.size();
    tabi[3]=(int)vjour4.size();
    tabi[4]=(int)vjour5.size();
    tabi[5]=(int)vjour6.size();
    tabi[6]=(int)vjour7.size();

    //on vide les progs la grille affprogs
    for(int k1=0;k1<6;k1++)//colonne
    {
        for(int k2=0; k2<tabi[k1];k2++)//ligne
        {
            this->deleteChildWidgets(affprogs->itemAtPosition(k2+1,k1));
            this->deleteChildWidgets(affprogs->itemAtPosition(k2+1,k1));
            this->deleteChildWidgets(affprogs->itemAtPosition(k2+1,k1));
        };
    };

    //on vide les vecteurs jours
    vjour1.clear();
    vjour2.clear();
    vjour3.clear();
    vjour4.clear();
    vjour5.clear();
    vjour6.clear();
    vjour7.clear();

    Date* j;
    j= new Date(1,1,2015);
    Date* d;
    d=new Date(1,1,2015);

    //on incrémente les progs de la semaine dans les vjour
    for(std::vector<programmation*>::const_iterator it=progs.begin();it!=progs.end();it++)
    {
        if((*it)!=0)
        {
            *j=(*it)->getDate();
            *d=*jour1;
            if(*d==*j)
                vjour1.push_back(*it);
            *d=d->demain();
            if(*d==*j)
                vjour2.push_back(*it);
            *d=d->demain();
            if(*d==*j)
                vjour3.push_back(*it);
            *d=d->demain();
            if(*d==*j)
                vjour4.push_back(*it);
            *d=d->demain();
            if(*d==*j)
                vjour5.push_back(*it);
            *d=d->demain();
            if(*d==*j)
                vjour6.push_back(*it);
            *d=d->demain();
            if(*d==*j)
                vjour7.push_back(*it);
        }
    }

    //on trie les données par horaire croissant des vecteurs vjour
    std::sort(vjour1.begin(), vjour1.end(), ComparatorByHoraire());
    std::sort(vjour2.begin(), vjour2.end(), ComparatorByHoraire());
    std::sort(vjour3.begin(), vjour3.end(), ComparatorByHoraire());
    std::sort(vjour4.begin(), vjour4.end(), ComparatorByHoraire());
    std::sort(vjour5.begin(), vjour5.end(), ComparatorByHoraire());
    std::sort(vjour6.begin(), vjour6.end(), ComparatorByHoraire());
    std::sort(vjour7.begin(), vjour7.end(), ComparatorByHoraire());

    int jx=1;
    //affichage des programmations
    for(std::vector<programmation*>::const_iterator it=vjour1.begin();it!=vjour1.end();it++)
    {
        (*it)->afficher(); //on met à jour l'affichage de la prog
        affprogs->addLayout((*it)->getLayout(),jx,0); //on implémente la prog dans l'affichage des progs
        jx++;
    }
    jx=1;
    for(std::vector<programmation*>::const_iterator it=vjour2.begin();it!=vjour2.end();it++)
    {
        (*it)->afficher(); //on met à jour l'affichage de la prog
        affprogs->addLayout((*it)->getLayout(),jx,1); //on implémente la prog dans l'affichage des progs
        jx++;
    }
    jx=1;
    for(std::vector<programmation*>::const_iterator it=vjour3.begin();it!=vjour3.end();it++)
    {
        (*it)->afficher(); //on met à jour l'affichage de la prog
        affprogs->addLayout((*it)->getLayout(),jx,2); //on implémente la prog dans l'affichage des progs
        jx++;
    }
    jx=1;
    for(std::vector<programmation*>::const_iterator it=vjour4.begin();it!=vjour4.end();it++)
    {
        (*it)->afficher(); //on met à jour l'affichage de la prog
        affprogs->addLayout((*it)->getLayout(),jx,3); //on implémente la prog dans l'affichage des progs
        jx++;
    }
    jx=1;
    for(std::vector<programmation*>::const_iterator it=vjour5.begin();it!=vjour5.end();it++)
    {
        (*it)->afficher(); //on met à jour l'affichage de la prog
        affprogs->addLayout((*it)->getLayout(),jx,4); //on implémente la prog dans l'affichage des progs
        jx++;
    }
    jx=1;
    for(std::vector<programmation*>::const_iterator it=vjour6.begin();it!=vjour6.end();it++)
    {
        (*it)->afficher(); //on met à jour l'affichage de la prog
        affprogs->addLayout((*it)->getLayout(),jx,5); //on implémente la prog dans l'affichage des progs
        jx++;
    }
    jx=1;
    for(std::vector<programmation*>::const_iterator it=vjour7.begin();it!=vjour7.end();it++)
    {
        (*it)->afficher(); //on met à jour l'affichage de la prog
        affprogs->addLayout((*it)->getLayout(),jx,6); //on implémente la prog dans l'affichage des progs
        jx++;
    }
    j=0;
    d=0;
    delete j;
    delete d;

}

void programmationActivite::afficher() const {
    delete prog->widget();
    Activite act=this->activite;
    QLabel* nom;
    QLabel* description;
    QLabel* duree;
    QLabel* horaire;
    nom= new QLabel();
    nom->setText(act.getNom());
    description=new QLabel();
    description->setText(act.getDescription());
    duree=new QLabel();
    duree->setText(QVariant(act.getDuree().getDureeEnMinutes()).toString());

    horaire=new QLabel();
    horaire->setText(QVariant(this->getHoraire().getHeure()).toString()+":"+QVariant(this->getHoraire().getMinute()).toString());

    prog->addWidget(nom);
    prog->addWidget(horaire);
    prog->addWidget(duree);
    prog->addWidget(description);

//    QString msg;
//    msg+="Affichage de l'activité :";
//    msg+=act.getNom();
//    QMessageBox msgBox;
//    msgBox.setText(msg);
//    msgBox.exec();

}
TIME::Horaire programmationActivite::getHorairefin() const{
    return Horaire(this->getHoraire()+this->getActivite().getDuree());
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
    if(trouverProgrammation(d,h))
    {
        QString msg;
        msg+="Déjà une programmation";
        QMessageBox msgBox;
        msgBox.setText(msg);
        msgBox.exec();
        newprog=0;
        return *newprog;
        //throw CalendarException("erreur, TacheManager, tache deja existante");

    }
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
    programmation& progact = agenda::getInstance().ajouterProgrammationActivite(activite, Date(ProgDate->date().day(),ProgDate->date().month(),ProgDate->date().year()),Horaire(ProgHh->value(), ProgHm->value()));
    if(&progact!=0){
        QMessageBox msgBox;
        msgBox.setText("L'Activité a été programmée");
        msgBox.exec();
        this->close();
    }
    else
    {
        delete &progact;
        QMessageBox msgBox;
        msgBox.setText("L'Activité n'a pas été programmée");
        msgBox.exec();
    }
}
void agenda::deleteChildWidgets(QLayoutItem *item){
    if (item->layout())
    {
        // Process all child items recursively.
        for (int i = 0; i < item->layout()->count(); i++)
        {
            deleteChildWidgets(item->layout()->itemAt(i));
        }
    }
    delete item->widget();
}
programmation* agenda::trouverProgrammation(const Date& d, const Horaire& hdebut){
    for(std::vector<programmation*>::const_iterator it=progs.begin();it!=progs.end();it++)
    {
        //on ne prend que les programmations qui ont cette date de début
        if((*it)->getDate()==d && (*it)->getHoraire()>=hdebut) //&& (*it)->getHorairefin()<hfin)
        {
            return (*it);
        }
    }
    return 0;
}


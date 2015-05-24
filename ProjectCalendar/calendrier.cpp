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
    coucheh1 = new QHBoxLayout;
    coucheh1->addWidget(titreLabel);
    coucheh1->addWidget(CreerActivite);
    setLayout(coucheh1);

    QObject::connect(CreerActivite,SIGNAL(clicked()),this,SLOT(fenetreActivite()));

}

void agenda::fenetreActivite(){
    FenetreCreerActivite* fenetre= new FenetreCreerActivite;
    fenetre->show();
}

programmation& agenda::ajouterProgrammationTache(const TIME::Date& d, const TIME::Horaire& h) {
    programmation* newprog=new programmationTache(d,h);
    progs.push_back(*newprog);
    return *newprog;
}
programmation& agenda::ajouterProgrammationActivite(const Activite& a, const TIME::Date& d, const TIME::Horaire& h) {
    programmation* newprog=new programmationActivite(a,d,h);
    progs.push_back(*newprog);
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
    if(programmation* progact = agenda::getInstance().ajouterProgrammationActivite(activite, Date(ProgDate->date().day(),ProgDate->date().month(),ProgDate->date().year()),Horaire(ProgHh->value(), ProgHm->value()))){
        QMessageBox msgBox;
        msgBox.setText("L'Activité a été programmée");
        msgBox.exec();
    }
}


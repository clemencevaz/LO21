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



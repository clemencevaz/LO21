#include "calendrier.h"
agenda::AgendaHandler agenda::agendahandler=agenda::AgendaHandler();

agenda& agenda::getInstance(){
    if(agendahandler.instance==0) agendahandler.instance = new agenda;
    return* agendahandler.instance;
}

void agenda::libererInstance(){
    delete agendahandler.instance;
    agendahandler.instance=0;
}

agenda::agenda(){
    progs.reserve(10);
    titreLabel= new QLabel("Agenda");
    coucheh1 = new QHBoxLayout;
    coucheh1->addWidget(titreLabel);
    setLayout(coucheh1);

}

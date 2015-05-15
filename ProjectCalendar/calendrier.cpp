#include "calendrier.h"
agenda::agenda(){
    titreLabel= new QLabel("Agenda");
    coucheh1 = new QHBoxLayout;
    coucheh1->addWidget(titreLabel);
    setLayout(coucheh1);

}

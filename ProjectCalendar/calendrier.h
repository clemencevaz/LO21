#ifndef PROGRAMMATION
#define PROGRAMMATION
#include <QWidget>

#include "timing.h"
#include <vector>
#include <QLabel>
#include <QHBoxLayout>
/*
class programmation{
    const Tache* tache;
    Date date;
    Horaire horaire;
public:
    Programmation(const Tache& t, const Date& d, const Horaire& h):tache(&t), date(d), horaire(h){}
    const Tache& getTache() const { return *tache; }
    Date getDate() const { return date; }
    Horaire getHoraire() const { return horaire; }
};*/

class agenda: public QWidget{
    //Q_OBJECT
    //vector<programmation*> progs;
    QLabel* titreLabel;
    QHBoxLayout* coucheh1;


public:
    agenda();
};

#endif // PROGRAMMATION


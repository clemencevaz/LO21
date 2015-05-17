#ifndef PROGRAMMATION
#define PROGRAMMATION

#include "ProjC.h"



class programmation;

class agenda: public QWidget{
    Q_OBJECT

    std::vector<programmation*> progs;
    QLabel* titreLabel;
    QHBoxLayout* coucheh1;
    agenda();
    ~agenda();
    agenda(const agenda& ag);
    agenda& operator=(const agenda& ag);

    struct AgendaHandler{
        agenda* instance;
        AgendaHandler():instance(0){}
        ~AgendaHandler(){agenda::libererInstance();}
    };
    static AgendaHandler agendahandler;

public:
    static agenda& getInstance();
    static void libererInstance();
    programmation& ajouterProgrammation(const Tache& t, const TIME::Horaire& h, const Date& d);
};

class programmation{
    TIME::Date date;
    TIME::Horaire horaire;
    programmation (const TIME::Date& d, const TIME::Horaire& h):date(d), horaire(h){}
    friend class agenda;
public:
    const TIME::Date getDate() const { return date; }
    const TIME::Horaire getHoraire() const { return horaire; }
};



class programmationActivite: public programmation{
    const Activite& activite;
public:
    programmationActivite(const Activite& a, const TIME::Date& d, const TIME::Horaire& h):programmation(d,h),activite(a){}
    const Activite& getActivite() const { return *activite; }

};


#endif // PROGRAMMATION


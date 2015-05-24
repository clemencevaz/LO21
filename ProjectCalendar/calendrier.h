#ifndef CALENDRIER_h
#define CALENDRIER_h

#include "ProjC.h"
using namespace TIME;
using namespace std;
class programmation;
class programmationActivite;
class programmationTache;

class agenda: public QWidget{
    Q_OBJECT
    std::vector<programmation> progs;
    QLabel* titreLabel;
    QHBoxLayout* coucheh1;
    agenda();
    //~agenda();
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
    //programmation& ajouterProgrammation(const Tache& t, const TIME::Horaire& h, const Date& d);
    programmation& ajouterProgrammationTache(const TIME::Date& d, const TIME::Horaire& h);
    //programmation& ajouterProgrammationActivite(const Activite& a, const TIME::Date& d, const TIME::Horaire& h);

class programmation{
    TIME::Date date;
    TIME::Horaire horaire;
    friend class agenda;
    friend class programmationActivite;
    friend class programmationTache;
    programmation(const TIME::Date& d, const TIME::Horaire& h):date(d),horaire(h){}
    //programmation (const TIME::Date& d, const TIME::Horaire& h):date(d), horaire(h){}
    //const TIME::Date getDate() const { return date; }
    //const TIME::Horaire getHoraire() const { return horaire; }
public:
    //const TIME::Date getDate() const { return date; }
    //const TIME::Horaire getHoraire() const { return horaire; }
};

class programmationTache: public programmation{
    //const Tache& tache;
public:
    programmationTache(const TIME::Date& d, const TIME::Horaire& h):programmation(d,h){}
};

class programmationActivite: public programmation{
    //const Activite& activite;
public:
    //programmationActivite(const Activite& a,const TIME::Date& d, const TIME::Horaire& h):programmation(d,h),activite(a){}
    //programmationActivite(const Activite& a, const TIME::Date& d, const TIME::Horaire& h):programmation(d,h),activite(a){}
    //const Activite& getActivite() const { return *activite; }
};

#endif // PROGRAMMATION

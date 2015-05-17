#ifndef PROGRAMMATION
#define PROGRAMMATION

#include "ProjC.h"

/*class programmation{
    const Tache* tache;
    Date date;
    Horaire horaire;
public:
    Programmation(const Tache& t, const Date& d, const Horaire& h):tache(&t), date(d), horaire(h){}
    const Tache& getTache() const { return *tache; }
    Date getDate() const { return date; }
    Horaire getHoraire() const { return horaire; }
};*/
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

};

#endif // PROGRAMMATION


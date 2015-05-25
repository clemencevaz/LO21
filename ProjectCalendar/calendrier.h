#ifndef PROGRAMMATION
#define PROGRAMMATION

#include "ProjC.h"
using namespace TIME;

class Activite;
class programmation;
class programmationActivite;
class programmationTache;

class agenda: public QWidget{
    Q_OBJECT

    std::vector<programmation*> progs;

    //Affichage
    QLabel* titreLabel;
    QLabel* textsemaine;
    QLabel* heures[12];

    QHBoxLayout* coucheh1;
    QVBoxLayout* couchev1;
    QGridLayout* affprogs;

    QPushButton* CreerActivite;
    QPushButton* Afficher;



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
    programmation& ajouterProgrammationActivite(const Activite& a, const TIME::Date& d, const TIME::Horaire& h);
public slots:
    void fenetreActivite();
    void afficher() ;

};

class programmation{
protected:
    TIME::Date date;
    TIME::Horaire horaire;
private:
    friend class agenda;
    friend class programmationActivite;
    friend class programmationTache;
    programmation(const TIME::Date& d, const TIME::Horaire& h):date(d),horaire(h){}
    //programmation (const TIME::Date& d, const TIME::Horaire& h):date(d), horaire(h){}
public:
    const TIME::Date getDate() const { return date; }
    const TIME::Horaire getHoraire() const { return horaire; }
    //virtual void afficher() ;
    virtual void afficher() const {}
};

class programmationTache: public programmation{
    //const Tache& tache;
public:
    programmationTache(const TIME::Date& d, const TIME::Horaire& h):programmation(d,h){}
};

class programmationActivite: public programmation{
    const Activite& activite;
public:
    programmationActivite(const Activite& a,const TIME::Date& d, const TIME::Horaire& h):programmation(d,h),activite(a){}
    //programmationActivite(const Activite& a, const TIME::Date& d, const TIME::Horaire& h):programmation(d,h),activite(a){}
    const Activite& getActivite() const { return activite; }
    void afficher() const ;

};

class FenetreProgrammerActivite:public QWidget{
    Q_OBJECT
    const Activite& activite;
    QLabel* titreLabel;
    QLabel* nom;
    QLabel* description;
    QLabel* duree;
    QLabel* date;
    QLabel* horaire;
    QDateEdit* ProgDate;
    QSpinBox* ProgHh;
    QSpinBox* ProgHm;
    QVBoxLayout* coucheV1;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QPushButton* Enregistrer;

public:
    FenetreProgrammerActivite(Activite& a);
public slots:
    void enregistrer();
};

#endif // PROGRAMMATION

#ifndef PROGRAMMATION
#define PROGRAMMATION

#include "ProjC.h"
using namespace TIME;

class Activite;
class programmation;
class programmationActivite;
class programmationTache;

class CalendarException{
public:
    //! Constructeur à partir d'une string
    CalendarException(const std::string& m):info(m){}
    const std::string& GetInfo() const { return info; } //<! Retourne l'information stockée dans la classe
private:
    std::string info;
};

class agenda: public QWidget{
    Q_OBJECT

    std::vector<programmation*> progs;

    //vecteurs pour l'affichage des jours
    std::vector<programmation*> vjour1;
    std::vector<programmation*> vjour2;
    std::vector<programmation*> vjour3;
    std::vector<programmation*> vjour4;
    std::vector<programmation*> vjour5;
    std::vector<programmation*> vjour6;
    std::vector<programmation*> vjour7;

    //Affichage
    QLabel* titreLabel;
    QLabel* textsemaine;
    QLabel* heures[12];

    QHBoxLayout* coucheh1;
    QVBoxLayout* couchev1;
    QGridLayout* affprogs;

    QPushButton* CreerActivite;
    QPushButton* CreerTache;
    QPushButton* CreerProjet;
    QPushButton* Afficher;
    QPushButton* ChoisirJ1;

    Date* jour1=new Date(1,6,2015);


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
    Date& getJour1();
    void setJour1(const Date& d);
    void deleteChildWidgets(QLayoutItem *item);
    programmation* trouverProgrammation(const Date& d, const Horaire& hdebut);

    //pour trier les programmations par horaire selon le jour


public slots:
    void fenetreActivite();
    void fenetreTache();
    void afficher() ;
    void choixj1();
};

class programmation{
protected:
    TIME::Date date;
    TIME::Horaire horaire;
    QVBoxLayout* prog;
private:
    friend class agenda;
    friend class programmationActivite;
    friend class programmationTache;
    programmation(const TIME::Date& d, const TIME::Horaire& h):date(d),horaire(h){prog=new QVBoxLayout();}
    //programmation (const TIME::Date& d, const TIME::Horaire& h):date(d), horaire(h){}
public:
    const TIME::Date getDate() const { return date; }
    const TIME::Horaire getHoraire() const { return horaire; }
    QVBoxLayout* getLayout() const {return prog;}
    virtual void afficher() const {}
    //virtual const Activite& getActivite() const {return Activite("",0,Duree(0,0));}
    virtual TIME::Horaire getHorairefin() const{return Horaire(0,0);}
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
    TIME::Horaire getHorairefin() const;


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
class ComparatorByHoraire{
public:
    bool operator() (programmation *a, programmation *b){

        return ((*a).getHoraire() < (*b).getHoraire());
    }
};
class myCalendar: public QCalendarWidget
{
    Q_OBJECT
  public:
    myCalendar() : QCalendarWidget()
    {
      QObject::connect(this, SIGNAL(clicked(const QDate&)), this, SLOT(setj1(const QDate&)));
    }

  public slots:
        void setj1(const QDate& date);

};

#endif // PROGRAMMATION

#ifndef PROGRAMMATION
#define PROGRAMMATION

#include "ProjC.h"
#include"tache.h"


using namespace TIME;
using namespace std;
class Activite;
class programmation;
class TacheUnitaire;
class programmationActivite;
class programmationTache;
/*! \class CalendarException
    \brief Permet de récupérer les erreurs
*/
class CalendarException{
public:
    //! Constructeur à partir d'une string
    CalendarException(const std::string& m):info(m){}
    const std::string& GetInfo() const { return info; } //<! Retourne l'information stockée dans la classe
private:
    std::string info;
};
/*! \class agenda
    \brief Classe qui est la base du projet, à partir duquel tout se fait

    Cette classe est un singleton, car il n'y aura qu'une seule fenêtre qui pourra afficher les programmations, de plus
    la plupart des autres interfaces sont accessible par cet objet.
*/
class agenda: public QWidget{
    Q_OBJECT

    std::vector<programmation*> progs; /*!< Vecteur contenant toutes les programmations, l'agenda fait donc office de
programmation manager*/

    //vecteurs pour l'affichage des jours
    std::vector<programmation*> vjour1;/*!< Vecteur avec toutes les programmations du jour1 affiché*/
    std::vector<programmation*> vjour2;/*!< Vecteur avec toutes les programmations du jour2 affiché*/
    std::vector<programmation*> vjour3;/*!< Vecteur avec toutes les programmations du jour3 affiché*/
    std::vector<programmation*> vjour4;/*!< Vecteur avec toutes les programmations du jour4 affiché*/
    std::vector<programmation*> vjour5;/*!< Vecteur avec toutes les programmations du jour5 affiché*/
    std::vector<programmation*> vjour6;/*!< Vecteur avec toutes les programmations du jour6 affiché*/
    std::vector<programmation*> vjour7;/*!< Vecteur avec toutes les programmations du jour7 affiché*/

    //Affichage
    QLabel* titreLabel;/*!< QLabel pour le titre en haut de la fenêtre*/
    QLabel* textsemaine;/*!< QLabel pour le texte indiquant la semaine affichée*/

    QHBoxLayout* coucheh1;/*!< QHBoxLayout, coucheh1 de l'interface*/
    QVBoxLayout* couchev1;/*!< QHVoxLayout, couchev1 de l'interface*/
    QGridLayout* affprogs;/*!< QGridLayout, pour afficher les programmations*/

    QPushButton* CreerActivite;/*!< Bouton pour créer une activité*/
    QPushButton* CreerTache;/*!< Bouton pour créer une tache*/
    QPushButton* CreerProjet;/*!< Bouton pour créer un projet*/
    QPushButton* Afficher;/*!< Bouton pour mettre à jour l'affichage*/
    QPushButton* ChoisirJ1;/*!< Bouton pour choisir le premier jour de la semaine*/
    QPushButton* ViewProjects; /*!< Bouton pour montrer tous les projets*/

    Date* jour1=new Date(1,6,2015);/*!< Premier jour de la semaine*/


    agenda();/*!< Le constructeur de l'agenda est dans la partie privée*/
    //~agenda();
    agenda(const agenda& ag);/*!< Le constructeur de recopie de l'agenda est dans la partie privée*/
    agenda& operator=(const agenda& ag);/*!< Le constructeur de recopie par l'opérateur = de l'agenda est dans la partie privée*/
    /*! \struct AgendaHandler
        \brief Implémentation du design pattern singleton
    */
    struct AgendaHandler{
        agenda* instance;/*!< singleton - pointeur de l'instance agenda*/
        AgendaHandler():instance(0){}/*!< constructeur de AgendaHandler*/
        ~AgendaHandler(){agenda::libererInstance();}/*!< Destructeur de AgendaHAndler qui appel libérerInstance*/
    };
    static AgendaHandler agendahandler;/*!< objet static AgendaHandler*/

public:
    static agenda& getInstance();/*!< fonction static getInstance qui renvoie la référence de l'agenda*/
    static void libererInstance();/*!< fonction static libererInstance*/
    programmation& ajouterProgrammationTache(Tache& t,const TIME::Date& d, const TIME::Horaire& h,const TIME::Duree& dur);/*!< fonction qui permet d'ajouter une programmation d'une tache*/
    programmation& ajouterProgrammationActivite(const Activite& a, const TIME::Date& d, const TIME::Horaire& h);/*!< fonction qui permet d'ajouter une programmation d'une activité*/
    Date& getJour1();/*!< fonction qui permet de connaître le jour1 de l'affichage*/
    void setJour1(const Date& d);/*!< fonction qui permet de changer le jour1*/
    void deleteChildWidgets(QLayoutItem *item);/*!< fonction qui permet de supprimmer les widgets enfants*/
    programmation* trouverProgrammation(const Date& d, const Horaire& hdebut, const Duree& dur);/*!< fonction qui permet de trouver une programmation en fonction de sa date, horaire et durée*/
    void setTextsemaine(QString s);/*!< fonction qui permet de modifier le texte semaine de l'affichage*/
    programmation* trouverProgparTache(Tache* t) const;


public slots:
    void fenetreMainProj();/*!< Slot qui permet d'ouvrir la fenetre pour montrer la liste de projets*/
    void fenetreActivite();/*!< Slot qui permet d'ouvrir la fenêter pour créer une activité*/
    void fenetreTache();/*!< Slot qui permet d'ouvrir la fenêter pour créer une tache*/
    void fenetreProjet(); /*!< Slot qui permetd'ouvrir la fenetre de creation de projet*/
    void afficher() ;/*!< Slot qui permet de mettre à jour l'affichage*/
    void choixj1();/*!< Slot qui permet d'ouvrir le calendrier pour choisir le jour1*/
};
/*! \class programmation
    \brief Classe mère abstraite des programmations d'activités et de taches unitaires

    Cette classe permet d'accèder aux fonctions et des objets programmations d'activités et de taches
*/
class programmation{
protected:
    TIME::Date date;/*!< Attribut date qui contient la date de la programmation*/
    TIME::Horaire horaire;/*!< Attribut horaire qui contient l'horaire de la programmation*/
    QVBoxLayout* prog;/*!< QVBoxLayout qui contient les éléments d'affichage d'une programmation*/
private:
    friend class agenda;/*!< agenda peut créer une programmation*/
    friend class programmationActivite;/*!< programmationActivité peut créer une programmation*/
    friend class programmationTache;/*!< programmationTache peut créer une programmation*/
    programmation(const TIME::Date& d, const TIME::Horaire& h):date(d),horaire(h){prog=new QVBoxLayout();}/*!< constructeur de programmation qui doit être fait par des fonctions externes*/
public:
    const TIME::Date getDate() const { return date; }/*!< fonction qui renvoie la date de la programmation*/
    const TIME::Horaire getHoraire() const { return horaire; }/*!< fonction qui renvoie l'horaire de la programmation*/
    QVBoxLayout* getLayout() const {return prog;}/*!< fonction qui renvoie le QVBoxLayout de la programmation*/
    virtual void afficher() const =0;/*!< fonction qui permet de créer le QVBoxLayout*/
    virtual TIME::Horaire getHorairefin() const{return Horaire(0,0);}/*!< fonction qui renvoie l'horaire de la programmation*/
    virtual const TacheUnitaire& getTache() const=0;
};
/*! \class programmationTache
    \brief Classe fille de programmation qui créer une programmation d'une tache unitaire
*/
class programmationTache: public programmation{
    const Tache& tache;/*!< référence de la tache unitaire programmée*/
    TIME::Duree duree;
public:
    programmationTache(const TacheUnitaire& t,const TIME::Date& d, const TIME::Horaire& h, const TIME::Duree& dur):programmation(d,h),tache(t),duree(dur){}/*!< constructeur*/
    const Tache& getTache() const {return tache;}/*!< fonction qui renvoie la référence de la tache unitaire*/
    void afficher() const;/*!< fonction qui permet d'agrémenter le QVBoxLayout*/
    TIME::Horaire getHorairefin() const;/*!< fonction qui renvoie l'horaire de fin*/

};

class programmationActivite: public programmation{
    const Activite& activite;/*!< référence de l'a tache unitaire'activité programmée*/
public:
    programmationActivite(const Activite& a,const TIME::Date& d, const TIME::Horaire& h):programmation(d,h),activite(a){}/*!< constructeur*/
    const Activite& getActivite() const { return activite; }/*!< fonction qui renvoie la référence de l''activité*/
    void afficher() const ;/*!< fonction qui permet d'agrémenter le QVBoxLayout*/
    TIME::Horaire getHorairefin() const;/*!< fonction qui renvoie l'horaire de fin*/
    const TacheUnitaire& getTache() const;


};
/*! \class FenetreProgrammerActivite
    \brief Classe qui permet de créer la fenetre pour créer une activité

    Cette classe va créer tous les objets et les slots pour créer une activité
*/
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
/*! \class FenetreProgrammerTache
    \brief Classe qui permet de créer la fenetre pour programmer une tache unitaire

    Cette classe va créer tous les objets et les slots pour créer cette programmation
*/
class FenetreProgrammerTache:public QWidget{
    Q_OBJECT
    Tache& tache;
    QLabel* titreLabel;
    QLabel* nom;
    QLabel* description;
    QLabel* duree;
    QLabel* progDuree;
    QLabel* date;
    QLabel* horaire;
    QDateEdit* ProgDate;
    QSpinBox* ProgHh;
    QSpinBox* ProgHm;
    QSpinBox* Dur;
    QVBoxLayout* coucheV1;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;

    QPushButton* Enregistrer;

public:
    FenetreProgrammerTache(Tache& t);
public slots:
    void enregistrer();
};

/*! \class ComparatorByHoraire
    \brief Comparateur qui permet de trier les programmations dans les vecteurs jours pour l'affichage
*/
class ComparatorByHoraire{
public:
    bool operator() (programmation *a, programmation *b){

        return ((*a).getHoraire() < (*b).getHoraire());
    }
};
/*! \class myCalendar
    \brief Classe qui permet la création d'un calendrier pour choisir le jour1 à afficher
*/
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

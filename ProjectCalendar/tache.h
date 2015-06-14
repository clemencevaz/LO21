#ifndef TACHE
#define TACHE
using namespace std;
#include "ProjC.h"
#include<stdexcept>
using namespace TIME;
class Projet;
/*! \class Tache
    \brief Classe abstraite

    Cette classe contient tous les éléments génériques des différentes taches possibles (unitaire ou composite)
*/
class Tache{

  QString titre;/*!< Titre de la tache*/
  Date dateDisponibilite;/*!< Date de disponibilité de la tache*/
  Date echeance;/*!< Date d'échéance de la tache*/
  vector<Tache*> precedentes;/*!< Vecteur avec toutes les taches précédentes*/
  Duree achevement;/*!< Attribut pour savoir la durée qu'il reste, utile pour les taches preemptives*/
  public:
    Tache(const QString& t, const Date& d_disp, const Date& ech, float ach) : titre(t),dateDisponibilite(d_disp),echeance(ech),achevement(ach){}/*!< Constructeur de tache*/

    const QString& get_titre() const { return titre;}/*!< Renvoie le titre de la tache*/
    const Date& get_date_disp() const {return dateDisponibilite;}/*!< Renvoie la date de disponibilité*/
    const Date& get_echeance() const {return echeance;}/*!< Renvoie la date d'échéance*/
    Duree get_achevement() const {return achevement;}/*!< Renvoie la durée d'achevement*/
    void set_achevement(Duree temps){achevement=temps;}/*!< Permet de cahnger l'achèvement*/
    void addPrecedence(Tache * const t){precedentes.push_back(t);}/*!< Rajoute une tache dans le vecteur précédences*/
    const vector<Tache*> get_precedentes() const {return precedentes;}/*!< Renvoie le vecteur précédences*/
    virtual void addComposite(Tache* t)=0;/*!< fonction virtuelle pure*/
    virtual const Duree& get_duree() const {return Duree(0,0);}/*!< fonction virtuelle*/
    virtual const bool get_preemptive() const {return false;}/*!< fonction virtuelle*/


};
/*! \class TacheUnitaire
    \brief Objet Tache Unitaire

    Cette classe conteint les élements d'une tache unitaire
*/
class TacheUnitaire : public Tache{
  Duree duree;/*!< durée  de la tache*/
  bool preemptive;/*!< booléen pour les préemptives */
	public:
    TacheUnitaire(const QString& t, const Date& d_disp, const Date& ech, float ach, const Duree& d, bool pre):
    Tache(t, d_disp, ech, ach), duree(d), preemptive(pre){
            unsigned int dureelimite;
            dureelimite=d.getDureeEnHeures();
            if (pre==1 || dureelimite>12)
                std::cout<<"La tâche ne peut pas être preemptive";
        }/*!< Constructeur*/
    const Duree& get_duree() const {return duree;}/*!< retourne la durée de la tache*/
    const bool get_preemptive() const override {return preemptive;}/*!< return la valeur du booléen preemptive */
    void addComposite(Tache* t){}/*!< pour les taches composites (complément pour la fonction virtuelle*/

       // ~TacheUnitaire();
};
/*! \class TAcheComposite
    \brief Objet Tache Composite
    Cette Tache ne contient que des taches
*/
class TacheComposite : public Tache{
    vector<Tache*> sous_taches;/*!< vecteur des sous taches */
	public:
    TacheComposite(const QString& t, const Date& d_disp, const Date& ech, float ach):Tache(t, d_disp, ech, ach){}/*!< constructeur*/
    void addComposite(Tache* t);/*!< permet d'ajouter une tache dans le vecteur sous_taches */
    //~TacheComposite();
};
/*! \class FenetreChoixTypeTache
    \brief Fenetre au début quand on veut créer une tache

    Demande à l'utilisateur s'il veut créer une tache composite ou unitaire
*/
class FenetreChoixTypeTache : public QWidget{
      Q_OBJECT
    QLabel* titreLabel;
    QRadioButton* unitaire;
    QRadioButton* composite;
    QVBoxLayout* coucheV1;
    QPushButton* valide;
    QMessageBox msgBox;
public:
    FenetreChoixTypeTache();
public slots:
    void fenetreTacheUnitaire();
};
/*! \class FenetreCreerTacheUnitaire
    \brief Fenetre pour créer une tache unitaire

*/
class FenetreCreerTacheUnitaire: public QWidget{
    Q_OBJECT
    QLabel* titreLabel;
    QLabel* nom;
    QLabel* textprojet;
    QLabel* duree;
    QLabel* textdatedispo;
    QLabel* textedateeche;
    QLabel* textpreemptive;
    QLineEdit* titre;
    QTextEdit* ActDesc;
    QDateEdit* datedispo;
    QDateEdit* dateeche;
    QSpinBox* hActDuree;
    QSpinBox* mActDuree;
    QCheckBox* preemptive;
    QHBoxLayout* coucheh1;
    QHBoxLayout* coucheh2;
    QVBoxLayout* coucheV1;
    QComboBox* projet;
    QPushButton* Enregistrer;
public:
    FenetreCreerTacheUnitaire();
public slots:
    void sauverTache();
};
/*! \class FenetreCreerTacheComposite
    \brief Fenetre pour créer une tache composite

*/
class FenetreCreerTacheComposite: public QWidget{
    Q_OBJECT
    QLabel* titreLabel;
    QLabel* nom;
    QLabel* textprojet;
    QLabel* textdatedispo;
    QLabel* textedateeche;
    QLineEdit* titre;
    QDateEdit* datedispo;
    QDateEdit* dateeche;
    QHBoxLayout* coucheh1;
    QVBoxLayout* coucheV1;
    QComboBox* projet;
    QPushButton* Enregistrer;
public:
    FenetreCreerTacheComposite();
public slots:
    void sauverTacheC();
};
/*! \class FenetreAjouterPrecedence
    \brief Fenetre pour ajouter une tache précédente

*/
class FenetreAjouterPrecedence:public QWidget{
    Q_OBJECT
    Tache& tache;
    Projet& projet;
    QComboBox* taches;
    QVBoxLayout* couchev1;
    QPushButton* valider;
public:
    FenetreAjouterPrecedence(Projet& p, Tache& t);
public slots:
    void ajoutPrecedence();

};
/*! \class FenetreAjouterTachedansCompositee
    \brief Fenetre pour ajouter une tache dans le vecteur des précédentes

*/
class FenetreAjouterTachedansComposite:public QWidget{
    Q_OBJECT
    Projet& projet;
    Tache& tachecomposite;

    QComboBox* taches;
    QPushButton* ajouter;
    QVBoxLayout* couchev1;
public:
    FenetreAjouterTachedansComposite(Projet& p, Tache& t);
public slots:
    void addComposite();


};

#endif

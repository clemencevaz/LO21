#ifndef TACHE
#define TACHE
using namespace std;
#include "ProjC.h"
#include<stdexcept>
using namespace TIME;
class Projet;
class Tache{

  QString titre;
  Date dateDisponibilite;
  Date echeance;
  vector<Tache*> precedentes;
  float achevement;
  public:
    Tache(const QString& t, const Date& d_disp, const Date& ech, float ach) : titre(t),dateDisponibilite(d_disp),echeance(ech),achevement(ach){}
   //~Tache(); //pour supprimer la tache du projet
   const QString& get_titre() const { return titre;}
    const Date& get_date_disp() const {return dateDisponibilite;}
    const Date& get_echeance() const {return echeance;}
    float get_achevement() const {return achevement;}
    void set_achevement(float temps){achevement=temps;}
    void addPrecedence(Tache * const t){precedentes.push_back(t);}
    const vector<Tache*> get_precedentes() const {return precedentes;}
};

class TacheUnitaire : public Tache{
  Duree duree;
  bool preemptive;
	public:
    TacheUnitaire(const QString& t, const Date& d_disp, const Date& ech, float ach, const Duree& d, bool pre):
    Tache(t, d_disp, ech, ach), duree(d), preemptive(pre){
            unsigned int dureelimite;
            dureelimite=d.getDureeEnHeures();
            if (pre==1 || dureelimite>12)
                std::cout<<"La tâche ne peut pas être preemptive";
        }
    const Duree& get_duree() const {return duree;}
    const bool get_preemptive() const {return preemptive;}
       // ~TacheUnitaire();
};

class TacheComposite : public Tache{
    vector<Tache*> sous_taches;
	public:
    TacheComposite(const QString& t, const Date& d_disp, const Date& ech, float ach):Tache(t, d_disp, ech, ach){}
    void addComposite(TacheUnitaire& t);
    //~TacheComposite();
};

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
class FenetreAjouterTachedansComposite:public QWidget{
    Q_OBJECT
    Projet& projet;
    TacheComposite& tachecomposite;

    QComboBox* taches;
    QPushButton* ajouter;
    QVBoxLayout* couchev1;
public:
    FenetreAjouterTachedansComposite(Projet& p, TacheComposite& t);
public slots:
    void addComposite();


};

#endif

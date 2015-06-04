#ifndef TACHE
#define TACHE
using namespace std;
#include "ProjC.h"
#include<stdexcept>

class Tache{
	Projet projet_pere;
    QString titre;
	Date dateDisponibilite;
	Date echeance;
    vector<Tache*> precedentes;
	float achevement;

	public:
        Tache(const QString& t, const Date& d_disp, const Date& ech, float ach, const Projet& pere) : titre(t),dateDisponibilite(d_disp),echeance(ech),achevement(ach), projet_pere(pere){}
        ~Tache(); //pour supprimer la tache du projet
        const QString& get_titre() const { return titre;}
		const Date& get_date_disp() const {return dateDisponibilite;}
		const Date& get_echeance() const {return echeance;}
        float get_achevement() const {return achevement;}
        void addPrecedence(Tache * const t){
			precedentes.push_back(t);
		}
};

class TacheUnitaire : public Tache{
	Duree duree;
    bool preemptive;
	public:
        TacheUnitaire(const QString& t, const Date& d_disp, const Date& ech, float ach, const Projet& pere, const Duree& d, bool pre):
        Tache(t, d_disp, ech, ach, pere), duree(d), preemptive(pre){
            unsigned int dureelimite;
            dureelimite=d.getDureeEnHeures();
            if (pre==1 || dureelimite>12)
                std::cout<<"La tâche ne peut pas être preemptive";
        }
        ~TacheUnitaire();
};

class TacheComposite : public Tache{
    vector<Tache*> sous_taches;
	public:
        TacheComposite(const QString& t, const Date& d_disp, const Date& ech, float ach, const Projet& pere, Tache* const composite):
    Tache(t, d_disp, ech, ach, pere){sous_taches.push_back(composite);}
        ~TacheComposite();
};

class FenetreCreerTache: public QWidget{
    Q_OBJECT
    QLabel* titreLabel;
    QLabel* nom;
    QLabel* description;
    QLabel* duree;
    QLineEdit* ActNom;
    QTextEdit* ActDesc;
    QSpinBox* hActDuree;
    QSpinBox* mActDuree;
    QHBoxLayout* coucheh1;
    QVBoxLayout* coucheV1;
    QPushButton* Enregistrer;
public:
    FenetreCreerTache();
public slots:
    void sauverTache();
};
#endif // TACHE

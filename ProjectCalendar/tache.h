#ifndef TACHE
#define TACHE
using namespace std;
#include "ProjC.h"


class Tache{
    Projet projet_pere;
    string titre;
    Date dateDisponibilite;
    Date echeance;
    vector<tache*> precedentes;
    float achevement;
    
public:
    tache(const string& t, const Date& d_disp, const Date& ech, float ach, const Projet& pere) : titre(t),dateDisponibilite(d_disp),echeance(ech),achevement(ach), projet_pere(pere){}
    ~tache(); //pour supprimer la tache du projet
    const string& get_titre() const { return titre;}
    const Date& get_date_disp() const {return dateDisponibilite;}
    const Date& get_echeance() const {return echeance;}
    float get_achevement() const {return achevement;}
    
    
    void addPrecedence(tache& t){
        precedentes.push_back(t);
    }
};



class TacheUnitaire : public tache{
    Duree duree;
    bool preeemptive;
public:
    tache_unitaire(const string& t, const Date& d_disp, const Date& ech, const Tache& precedentes, float ach, const projet& pere, duree d, bool pre):
    tache(t, d_disp, ech, precedentes, pere, duree), duree(d), preemptive(pre){}
    ~tache_unitaire();
};

class TacheComposite : public tache{
    vector<tache*> sous_taches;
public:
    tache_composite(const tache& sous_tache){sous_taches.push_back(sous_tache);}
    ~tache_composite();
};




#endif // TACHE

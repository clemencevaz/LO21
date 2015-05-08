#ifndef PROGRAMMATION
#define PROGRAMMATION
#include <vector>
class programmation{
    const Tache* tache;
    Date date;
    Horaire horaire;
public:
    Programmation(const Tache& t, const Date& d, const Horaire& h):tache(&t), date(d), horaire(h){}
    const Tache& getTache() const { return *tache; }
    Date getDate() const { return date; }
    Horaire getHoraire() const { return horaire; }
};

class agenda{
    vector<programmation*> progs;
};

#endif // PROGRAMMATION


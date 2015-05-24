#ifndef ACTIVITE
#define ACTIVITE

#include "ProjC.h"

class Activite{
private:
    QString nom;
    QString description;
    TIME::Duree duree;
public:
    Activite(const QString& n, const QString& d, const TIME::Duree& dur):nom(n), description(d), duree(dur){}
    const QString& getNom(){return nom;}
    const QString& getDescription(){return description;}
    const TIME::Duree& getDuree(){return duree;}
};

#endif // ACTIVITE


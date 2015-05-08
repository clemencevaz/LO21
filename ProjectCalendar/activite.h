#ifndef ACTIVITE
#define ACTIVITE
#include <QString>

class Activite{
private:
    QString nom;
    QString description;
    Duree duree;
public:
    Activite(const QString& n, const QString& d, const Duree& dur):nom(n), description(d), duree(dur){}
    const QString& getNom(){return nom;}
    const QString& getDescription(){return description;}
    const Duree& getDuree(){return duree;}
};

#endif // ACTIVITE


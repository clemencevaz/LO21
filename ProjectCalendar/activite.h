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
    const QString& getNom() const {return nom;}
    const QString& getDescription() const {return description;}
    const TIME::Duree& getDuree() const {return duree;}

};

class FenetreCreerActivite: public QWidget{
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
    FenetreCreerActivite();
public slots:
    void sauverActivite();
};

#endif // ACTIVITE


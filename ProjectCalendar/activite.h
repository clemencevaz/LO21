#ifndef ACTIVITE
#define ACTIVITE

#include "ProjC.h"
/*! \class Activite
    \brief Une activité est un évènement qui ne n'est pas contenu par un projet

    La classe contient les éléments essentiels à une activité, rendez vous...en laissant le choix à l'utilisateur de l'utilsier comme il le veut

*/
class Activite{
private:
    QString nom;/*!< Attribut nom de l'activité*/
    QString description;/*!< Description de l'activité*/
    TIME::Duree duree;/*!< Durée de l'activité*/
public:
    Activite(const QString& n, const QString& d, const TIME::Duree& dur):nom(n), description(d), duree(dur){}/*!< Constructeur de l'activité*/
    const QString& getNom() const {return nom;}/*!< Fonction qui renvoie le nom de l'activité*/
    const QString& getDescription() const {return description;}/*!< Fonction qui renvoie la description de l'activité*/
    const TIME::Duree& getDuree() const {return duree;}/*!< Fonction qui renvoie la description de l'activité */

};
/*! \class FenetreCreerActivite
    \brief Objet qui permet de construire la fenêtre pour créer une activité


*/
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
    FenetreCreerActivite();/*!< Constructeur de la fenêtre */
public slots:
    void sauverActivite();/*!< Fonction permet de sauvegarder une activité */
};

#endif // ACTIVITE


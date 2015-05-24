#ifndef TACHEEDITEUR_H
#define TACHEEDITEUR_H


#include "ProjC.h"
class Tache;
class TacheEditeur : public QWidget{
    Q_OBJECT
    Tache& tache;
    QLineEdit* identificateur;
    QLabel* identificateurLabel;
    QTextEdit* titre;
    QLabel* titreLabel;
    QCheckBox* preemptive;
    QDateEdit* disponibilite;
    QLabel* disponibiliteLabel;
    QDateEdit* echeance;
    QLabel* echeanceLabel;
    QLabel* dureeLabel;
    QSpinBox* hDuree;
    QSpinBox* mDuree;
    QPushButton* sauver;
    QPushButton* annuler;
    QVBoxLayout* couche;
    QHBoxLayout* coucheH1;
    QHBoxLayout* coucheH2;
    QHBoxLayout* coucheH3;
    QHBoxLayout* coucheH4;
public:
    //explicit TacheEditeur(Tache& tacheToEdit, QWidget *parent = 0);
signals:
public slots:
    //void sauverTache();
private slots:
    //void activerSauver(QString str="");
    //void coherenceDates(const QDate & date);
};

#endif // TACHEEDITEUR_H

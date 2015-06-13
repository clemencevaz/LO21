#ifndef PROJET
#define PROJET
#include "ProjC.h"

class Tache;


/*!	\class Projet
	\brief La classe qui definit les projets


	Un projet a un nom, et des taches, il n'a pas de due date,
	celle-ci ne depend que de la date d'echeance de la derniere
	tache a effectuer. 
*/
	
class Projet{
	friend class Iterator;
private:
	QString nom; /*!< le Nom du projet, en QString*/
    std::vector<Tache*> taches; /*!< Le vecteur des taches qui sont comprises dans le projet*/

public:
	//! Le constructeur Public du Projet
	/*!
		Le constructeur du Projet reserve 20 places pour les taches
		\param n Nom du projet en QString
	*/
    Projet(const QString& n): nom(n){
		taches.reserve(20);
	}

	//!Le destructeur du Projet
	/*!
		Le destructeur du Projet qui elimine toutes les taches
		qui lui sont associees
	*/
	~Projet(){
//        for (Projet::getIterator() i = ; i < taches.size(); i++){
//			delete taches[i];
//		}
    }

    /*********
     Accessors
    *********/
    //! getTaches permet de recuperer tout le vecteur des taches
    /*!
		Methode dangereuse, etant donne qu'elle renvoit le vecteur complet
    */
    const std::vector<Tache*> getTaches() const{ return taches; }

    QString getNom(){
    	return nom;
    }

	/**********
	/ Setters
    *********/

    //! Permet d'ajouter une tache au projet
    /*!
		addTache permet d'ajouter une tache au projet
		\param tache en tant que reference a une tache
    */
    void addTache(Tache* tache){ taches.push_back(tache); }

    /*void addTaches(const vector<tache*> addingTaches){
		for (int i = 0; i < addingTaches.size(); i++){
			taches.push_back(addTaches[i]);
		}
	}*/

	//! Permet de detruire une tache du vecteur
	/*!
		Enelve une tache du projet tout en la laissant en memoire
	*/
    void deleteTache(Tache* tache){
        for (unsigned int i = 0; i < taches.size(); i++){
            if (taches[i] == tache){
				taches.erase(taches.begin()+i);
			}
		}
	}

    inline bool operator==(Projet* proj){
        if (proj->nom == this->nom){
			return true;
		}else{
			return false;
		}
	}
	/*! \class Iterator
		\brief La classe iterator du vecteur de projet
	
		Cette classe permet d'iterer les taches du vecteur de projet.
		En effet il est dangereux de laisser le vecteur au public, on
		implemente alors un iterator qui rendra les taches une a une
	*/
	class Iterator{
		friend class Projet;

	private:
        std::vector<Tache*> tac;
        unsigned int i; //index

		Iterator(std::vector<Tache*> taches):tac(taches), i(0){}
	public:
		~Iterator();

        Tache* current(){
			return tac[i];
		}

		void next(){ 
			if (end()){
//                throw new CalendarException("next dans iterator fini");
			}else{
				i++;
			}
		}

		bool end(){
			if (i >= tac.max_size()){
				return true;
			}else{
				return false;
			}
		}

	};
	

    Iterator* getIterator() const { return new Iterator(taches); }


};


#endif

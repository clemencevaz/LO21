#ifndef PROJET
#define PROJET
#include "ProjC.h"
#include "tache.h"

class Projet{
	friend class Iterator;
private:
	QString nom;
    std::vector<Tache*> taches;

public:
    Projet(const QString& n): nom(n){
		taches.reserve(10);
	}

	~Projet(){
		for (int i = 0; i < taches.size(); i++){
			delete taches[i];
		}
    }
  };

    *********
     Accessors
    *********
    const std::vector<Tache*> getTaches() const{ return taches; }


	/**********
	/ Setters
    *********/
    void addTache(const Tache& tache){ taches.push_back(tache); }

    /*void addTaches(const vector<tache*> addingTaches){
		for (int i = 0; i < addingTaches.size(); i++){
			taches.push_back(addTaches[i]);
		}
	}*/


	//TODO:
		// Creer iterateur
    void deleteTache(const Tache& tache){
		for (int i = 0; i < taches.size(); i++){
            if (&taches[i] == tache){
				taches.erase(taches.begin()+i);
			}
		}
	}



	class Iterator{
		friend class Projet;

	private:
		int i; //index
		std::vector<Tache*> tac;

		Iterator(std::vector<Tache*> taches):tac(taches), i(0){}
	public:
		~Iterator();

        Tache& current(){
			return tac[i];
		}

		void next(){ 
			if (end()){
				throw CalendarException("next dans iterator fini");
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

		static Iterator getIterator() const { return new Iterator(taches); }
	};

};
*/
#endif

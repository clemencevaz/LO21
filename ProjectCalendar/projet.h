#ifndef PROJET
#define PROJET

using namespace std;

class projet{
	friend class Iterator;
private:
	qstring nom;
	vector<tache> taches; 
public:
	projet(const qstring& n): nom(n){
		taches.reserve(10);
	}

	~projet(){
		for (int i = 0; i < taches.size(); i++){
			delete taches[i];
		}
	}

	/**********
	/ Accessors
	**********/
	const vector<tache> getTaches() const{ return taches; }


	/**********
	/ Setters
	**********/
	void addTache(const tache& tache){ taches.push_back(tache); }

	void addTaches(const vector<tache*> addingTaches){
		for (int i = 0; i < addingTaches.size(); i++){
			taches.push_back(addTaches[i]);
		}
	}


	//TODO:
		// Creer iterateur
	void deleteTache(const tache& tache){
		for (int i = 0; i < taches.size(); i++){
			if (&taches[i] === tache){
				taches.erase(taches.begin()+i);
			}
		}
	}

	class Iterator;

	class Iterator{
	private:
		int i; //index
		Iterator(){
			i = 0;
		}
	public:
		tache& current(){
			return project::taches[i];
		}

		void next(){ 
			if (i>project::taches.max_size()){
				end();
			}else{
				i++;
			}
		}

		bool end(){
			if (i >= project::taches.max_size()){
				return true;
			}else{
				return false;
			}
		}

		Iterator getIterator(){ return new Iterator(); }
	};

};

#endif // PROJET


#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H
#include "ProjC.h"

class ProjetManager;

class ProjetManager{

friend class Iterator;
private:
	std::vector<Project*> projects;
	ProjetManager();
public:
	~ProjetManager();
	ProjetManager& getManager(){
		return new ProjetManager();
	};

	void addProjet(Projet& proj){
		projects.push_back(proj);
	};

	void removeProject(Projet& proj){
		for (int i = 0; i < projects.size(); i++){
			if (&projects[i] == proj){
				projects.erase(projects.begin()+i);
			}
		}
	}


	class Iterator{
	
		friend class ProjetManager;
		 
	private:
		std::vector<Project*> projs;
		int i;

		Iterator(std::vector<Project*> projects):projs(projects),i(0){}

	public:
		~Iterator();

		Projet& current(){
			return projs[i];
		}

		void next(){
			if (end()){
				throw CalendarException("next() sur un iterateur fini");
			}else{
				i++;
			}
		}

		bool end(){
			if (i >= projs.max_size()){
				return true;
			}else{
				return false;
			}
		}
	};

	Iterator getIterator() const { return Iterator(projects); }
};

#endif
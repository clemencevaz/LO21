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


	class Iterator;

	class Iterator{
	private:
		int i;
		Iterator():i(0){};
	public:
		~Iterator();

		Projet& current(){
			return ProjetManager::projects[i];
		}

		void next(){
			if (i>ProjetManager::projects.max_size()){
				end();
			}else{
				i++;
			}
		}

		bool end(){
			if (i >= ProjetManager::projects.max_size()){
				return true;
			}else{
				return false;
			}
		}
	};


};

#endif
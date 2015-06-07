#ifndef PROJETMANAGER
#define PROJETMANAGER
#include "ProjC.h"

/*	\class ProjetManager
	\brief Cette classe sert a gerer les differents projets


	Cette classe, un sigleton, permet au developpeur d'avoir 
	une interface directe pour gerer les projets.
	En effet, elle possede un vecteur de projets qui contiendra tous les projets 
	du calendrier.
*/
class ProjetManager{

friend class Iterator;
private:


	std::vector<Project*> projects; /*!< Le vecteur qui contiendra les projets, en pointeur pour la memoire*/

	//! Le constructeur, prive, du Project Manager
	/*!
		Le constructeur du projet permet de reserver un espace de 
		10 projets dans le vecteur.
	*/
	ProjetManager(){
		projects.reserve(10);
	};

	ProjetManager(const ProjetManager &old); // desactivation de la copie
    const ProjetManager &operator=(const ProjetManager &old); // desactivation de "l'assignment"
	
	//!Destructeur de ProjectManager
	/*!
		Etant donne que le lien entre un projet et le projetManager
		est une composition, le destructeur de ProjetManager doit
		aussi detruire toutes les occurrences de projets dans
		le vecteur qui leur est associe.
		Le destructeur est prive, parce qu'il est dangereux de pouvoir 
		eliminer le seul objet qui peut detruire la moitie des evts 
		dans le cal
	*/
	~ProjetManager(){
		for(unsigned int i = 0; i<projects.size(); i++){
			delete projects[i];
		}
	};
public:
	
	//!getManager, retourne l'instance du singleton ProjetManager
	/*!
		Cette methode cree, et retourne une instance unique de 
		ProjetManager. Etant donne qu'elle est statique, elle 
		peut etre appelee de tout code.
	*/
	static ProjetManager& getManager(){
		static ProjetManager *instance = new ProjetManager;

		return *instance;
	}

	//! Permet d'ajouter un projet au vecteur du ProjetManager
	/*!
		\param proj une reference au Projet qui sera ajoute
	*/
	void addProjet(Projet& proj){
		projects.push_back(*proj);
	}

	//! Permet d'eliminer un projet du ProjetManager
	/*!
		Elimine un projet mais le laisse en memoire, sinon utiliser
		deleteProject
		\param proj une reference au projet a eliminer
	*/

	void removeProject(Projet& proj){
		for (int i = 0; i < projects.size(); i++){
			if (&projects[i] == proj){
				projects.erase(projects.begin()+i);
			}
		}
	}

	//! Permet de detruire un projet du ProjetManager
	/*!
		\param proj une reference au projet a detruire
	*/

	void deleteProject(Projet& proj){
		for (int i = 0; i < projects.size(); i++){
			if (&projects[i] == proj){
				delete projects[i];
			}
		}
	}

	//! Iterator de ProjetManager
	/*!
		On cree un iterator pour ne pas laisser le vecteur libre
		En effet il est dangereux de laisser la manipulation du vecteur 
		au public, l'iterator nous permet de rendre projet par projet
		et donc de ne pas publier tout le dataset.
	*/
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
#include "Generation_Base.hpp"
#include <algorithm>
#include <ctime>
#include <cstdlib>

Generation_Base::Generation_Base ()
{
	srand(NULL);
	//TODO Salma
}

Generation_Base::~Generation_Base ()
{
}

Individu Generation_Base::mariage( Individu ind1, Individu ind2 ) {
	Vector v_filles( ind1.second.size() )  ;
	for (int i = 0; i < ind1.second.size(); i++)
	{
		v_filles[i] = (ind1.second[i] + ind2.second[i])/2;
	}
	return make_pair( cond.calculOptimis(v_filles), v_filles);
	//return result;
}

Individu Generation_Base::mariageEtMutation( Individu ind1, Individu ind2, float prob ) {
	Individu result = mariage(ind1,ind2);

	float random = (float) rand() / (float) RAND_MAX; //Quels fonctions aléatoires ?
	if (random < prob) {
		//Choix de l'indice alétoirement
		int indice = rand() % result.second.size(); //Quels fonctions aléatoires ?
		if ( rand() % 2 ) {
			result.second[indice] = min( result.second[indice] + 0.5, ( result.second[indice] + cond.getBorneSup()[indice] ) / 2);
		}
		else
		{
			result.second[indice] = max( result.second[indice] - 0.5, ( result.second[indice] + cond.getBorneInf()[indice] ) / 2);
		}
		result.first = cond.calculOptimis(result.second);
	}

	//Est-ce que result correspond au condition ?
	return result;
}		

void Generation_Base::passerNouvelleGeneration() {
	Population filles_vrac;
	//Creation de la Individu fille par mariage et mutation;
	int i =0;
	for ( Population::const_iterator it = populationNonConforme.begin(); it != populationNonConforme.end(); it++) {
		int j =0;
		for ( Population::const_iterator it2 = populationNonConforme.begin(); it2 != populationNonConforme.end(); it2++) {
			//Evite d'avoir des doublons !
			if( i > j ) {
				filles_vrac.insert( mariage(*it, *it2) );
			}
			else break;
			j++;
		}
		for(  Population::const_iterator it3 = populationConforme.begin(); it3 != populationConforme.end(); it3++) {
			filles_vrac.insert( mariage(*it, *it3) );
		}
		i++;
	}
	i = 0;
	for ( Population::const_iterator it = populationConforme.begin(); it != populationConforme.end(); it++) {
		int j =0;
		for ( Population::const_iterator it2 = populationConforme.begin(); it2 != populationConforme.end(); it2++) {
			//Evite d'avoir des doublons !
			if( i > j ) {
				filles_vrac.insert( mariage(*it, *it2) );
			}
			else break;
			j++;
		}
	}

	pair<Population, Population> filles_tries = triConforme(filles_vrac);

	//Cas conforme
	Population populationConformeSuivante;
	Population::iterator it_mere_conforme = populationNonConforme.begin();
	Population::iterator it_fille_conforme = filles_tries.first.begin();

	for (int i = 0; i < nbIndividuParPopulationConforme; i++)
	{
		if ( it_mere_conforme == populationConforme.end() ) {
			for (int j = i; j < nbIndividuParPopulationConforme && it_fille_conforme != filles_tries.first.end(); j++)
			{
				populationConformeSuivante.insert(*it_fille_conforme);
				it_fille_conforme++;
			}
			break;
		}
		if ( it_fille_conforme == filles_tries.first.end() ) {
			for (int j = i; j < nbIndividuParPopulationConforme && it_mere_conforme != populationConforme.end() ; j++)
			{
				populationConformeSuivante.insert(*it_mere_conforme);
				it_mere_conforme++;
			}
			break;
		}

		if ( it_mere_conforme->first < it_fille_conforme->first) {
			populationConformeSuivante.insert(*it_mere_conforme);
			it_mere_conforme++;
		}
		else {
			populationConformeSuivante.insert(*it_fille_conforme);
			it_fille_conforme++;
		}
	}

	populationConforme.clear();
	populationConforme = populationConformeSuivante;

	//Cas non conforme
	// garder les meilleurs non conformes ne nous interessent pas ! mais peuvent être utiles...
	// le quart des non_conformes est gardé, le reste est généré aléatoirement
	Population populationNonConformeSuivante;
	Population::iterator it_mere_non_confome = populationNonConforme.begin();
	Population::iterator it_fille_non_conforme = filles_tries.second.begin();
	
	for (int i = 0; i < nbIndividuParPopulationNonConforme/4; i++)
	{
		if ( it_mere_non_confome == populationNonConforme.end() ) {
			for (int j = i; j < nbIndividuParPopulationNonConforme/4 && it_fille_non_conforme != filles_tries.second.end(); j++)
			{
				populationNonConformeSuivante.insert(*it_fille_non_conforme);
				it_fille_non_conforme++;
			}
			break;
		}
		if ( it_fille_non_conforme == filles_tries.second.end() ) {
			for (int j = i; j < nbIndividuParPopulationNonConforme/4 && it_mere_non_confome != populationNonConforme.end() ; j++)
			{
				populationNonConformeSuivante.insert(*it_mere_non_confome);
				it_mere_non_confome++;
			}
			break;
		}

		if ( it_mere_non_confome->first < it_fille_non_conforme->first) {
			populationNonConformeSuivante.insert(*it_mere_non_confome);
			it_mere_non_confome++;
		}
		else {
			populationNonConformeSuivante.insert(*it_fille_non_conforme);
			it_fille_non_conforme++;
		}
	}

	//Generation aléatoire du reste de la population non_conforme
	for (int i = nbIndividuParPopulationNonConforme/4; i < nbIndividuParPopulationNonConforme; i++) {
		//TODO : populationNonConformeSuivante.insert( NEW INDIVIDU GENERER ALEATOIREMENT )
	}

	populationNonConforme.clear();
	populationNonConforme = populationNonConformeSuivante;
}

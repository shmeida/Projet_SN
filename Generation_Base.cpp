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
		v_filles[i] = (ind1.second[i] + ind1.second[i])/2;
	}
	return Individu /*result*/ (cond.calculOptimis(v_filles), v_filles);
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
	std::set<Individu> filles;
	//Creation de la Individu fille par mariage et mutation;
	//Possibilite de réduire de moitie le nombre de fille
	int i =0;
	for ( std::set<Individu>::const_iterator it = population.begin(); it < population.end(); it++) {
		int j =0;
		for ( std::set<Individu>::const_iterator it2 = population.begin(); it2 < population.end(); it2++) {
			if( i > j ) {
				filles.insert( mariage(*it, *it2) );
			}
			else break;
			j++;
		}
		i++;
	}

	std::set<Individu> populationSuivante;
	std::set<Individu>::iterator it_mere = population.begin();
	std::set<Individu>::iterator it_fille = filles.begin();
	
	for (int i = 0; i < nbIndividuParPopulation; i++)
	{
		if ( it_mere->first < it_fille->first) {
			populationSuivante.insert(*it_mere);
			it_mere++;
		}
		else {
			populationSuivante.insert(*it_fille);
			it_fille++;
		}
	}

	population.clear();
	population = populationSuivante;
}

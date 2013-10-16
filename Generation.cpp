#include "Generation.hpp"
#include <set>

Generation::Generation ()
{
	//TODO Salma
}

Generation::~Generation ()
{
}


Generation Generation::passerNouvelleGeneration() {
	std::set<Individu> filles;
	//Creation de la Individu fille par mariage et mutation;
	//Possibilité de réduire de moitié le nombre de fille
	for ( std::set<Individu>::const_iterator it = population.begin(); it < population.end(); it++) {
		for ( std::set<Individu>::const_iterator it2 = population.begin(); it2 < population.end(); it2++) {
			if( it != it2 ) {
				filles.insert( mariage(*it, *it2) );
			}
		}
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

	Generation result;
	return result;
}
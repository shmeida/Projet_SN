#include "Generation_Base.hpp"

Generation_Base::Generation_Base ()
{
	//TODO Salma
}

Generation_Base::~Generation_Base ()
{
}

Vector Generation_Base::mariage_ext( Individu ind1, Individu ind2 ) {
	Vector v_filles( ind1.second.size() )  ;
	for (int i = 0; i < ind1.second.size(); i++)
	{
		v_filles[i] = ind1.second[i] + ind1.second[i];
		v_filles[i] /= 2;
	}
	return v_filles;
}

//hghyfhyrff

Individu Generation_Base::mariage( Individu ind1, Individu ind2 ) {
	Vector v_filles = mariage_ext(ind1,ind2);
	Individu result (c.calculF(v_filles), v_filles);
	return result;
}

Individu Generation_Base::mariageEtMutation( Individu ind1, Individu ind2, float prob ) {
	Vector v_filles = mariage_ext(ind1,ind2);

	float random = 0; //Quels fonctions aléatoires ?
	if (random < prob) {
		//Choix de l'indice alétoirement
		int indice = 0; //Quels fonctions aléatoires ?
		v_filles[indice] += 0; // Quels valeurs rajouter ?
	}

	//Est-ce que v_filles correspond au condition ?

	Individu result ( c.calculF(v_filles), v_filles);
	return result;
}		

void Generation_Base::passerNouvelleGeneration() {
	std::set<Individu> filles;
	//Creation de la Individu fille par mariage et mutation;
	//Possibilit?de réduire de moiti?le nombre de fille
	int i =0;
	for ( std::set<Individu>::const_iterator it = population.begin(); it < population.end(); it++) {
		int j =0;
		for ( std::set<Individu>::const_iterator it2 = population.begin(); it2 < population.end(); it2++) {
			if( i < j ) {
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

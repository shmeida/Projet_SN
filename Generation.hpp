#ifndef GENERATION_HPP
#define GENERATION_HPP

#include "Population.hpp"

template< typename G >
class Generation
{
private:
	//Condition c;
	int nbIndividuParPopulation;
	// Ici il nous faut un Set d'un couple (f(x),x) trié sur f(x) que l'on nomme G pour le moment
	typename G population;

public:
	Generation();
	~Generation();
	
	// Laquelle ?
	Generation passerNouvelleGeneration();
	// change a génération actuelle en la nouvelle génération
	void passerNouvelleGeneration2();
	G fusionPopulation ( G pop1, G pop2 );	
	bool condArret(); 

};


#endif

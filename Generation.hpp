#ifndef GENERATION_HPP
#define GENERATION_HPP

#include <set>
#include "Individu.hpp"
#include "Condition.hpp"

class Generation
{
protected:
	Condition c;
	int nbIndividuParPopulation;
	// Ici il nous faut un Set d'un couple (f(x),x) tri� sur f(x) 
	std::set<Individu> population;

	std::set<Individu> fusionIndividu( std::set<Individu> pop1, std::set<Individu> pop2 );
	virtual Individu mariage( Individu ind1, Individu ind2 ) = 0;
	virtual Individu mariageEtMutation( Individu ind1, Individu ind2, float prob ) = 0;
	Vector mariage_ext( Individu ind1, Individu ind2 );

public:
	Generation();
	~Generation();
	
	// Laquelle ?
	Generation passerNouvelleGeneration();
	// change a g�n�ration actuelle en la nouvelle g�n�ration
	void passerNouvelleGeneration2();
	bool condArret(); 

};

#endif

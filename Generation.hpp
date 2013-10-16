#ifndef GENERATION_HPP
#define GENERATION_HPP

#include <set>
#include "Individu.hpp"
#include "Condition.hpp"

/*virtual*/ class Generation
{
protected:
	Condition c;
	int nbIndividuParPopulation;
	// Ici il nous faut un Set d'un couple (f(x),x) trié sur f(x) 
	std::set<Individu> population;

	std::set<Individu> fusionIndividu( std::set<Individu> pop1, std::set<Individu> pop2 );
	virtual Individu mariage( Individu ind1, Individu ind2 ) = 0;
	virtual Individu mariageEtMutation( Individu ind1, Individu ind2, float prob ) = 0;
	Vector mariage_ext( Individu ind1, Individu ind2 );

public:
	Generation();
	~Generation();
	
	// Laquelle ? On choisit la deuxième sinon pb avec Generation qui est abstrait et ca fait chier
	// virtual Generation passerNouvelleGeneration() = 0;
	// change a génération actuelle en la nouvelle génération
	virtual void passerNouvelleGeneration() = 0;
	bool condArret(); 

};

#endif

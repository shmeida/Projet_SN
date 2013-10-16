#ifndef GENERATION_BASE_HPP
#define GENERATION_BASE_HPP

#include "Generation.hpp"

class Generation_Base : public Generation
{
protected:
	Individu mariage( Individu ind1, Individu ind2 );
	Individu mariageEtMutation( Individu ind1, Individu ind2, float prob ) ;
	Vector mariage_ext( Individu ind1, Individu ind2 );

public:
	Generation_Base();
	~Generation_Base();

	void passerNouvelleGeneration();
};

#endif

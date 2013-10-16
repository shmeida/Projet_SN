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

Individu Generation_Base::mariage( Individu ind1, Individu ind2 ) {
	Vector v_filles = mariage_ext(ind1,ind2);
	Individu result = {c.calculF(v_filles), v_filles};
	return result;
}

Individu Generation_Base::mariageEtMutation( Individu ind1, Individu ind2, float prob ) {
	Vector v_filles = mariage_ext(ind1,ind2);
	Individu result = {c.calculF(v_filles), v_filles};
	return result;
}		
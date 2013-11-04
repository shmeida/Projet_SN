#ifndef _CONDITION
#define _CONDITION

#include<iostream>
#include<vector>
#include"Fonction.h"
#include<fstream>
#include<sstream>
#include<cstdlib>

typedef std::vector<double> Vector;
class Condition
{
public:
	Condition();
	~Condition();
	Condition(Condition &);
	Condition operator=(Condition &);
	bool respecteCondition(Vector &);
	Vector getBorneInf();
	Vector getBorneSup();
	void lireFicher();
	void afficherConditions();
private:
	Vector borneInf;
	Vector borneSup;
	std::vector<Fonction> conditions;
	Fonction optimis;
	int dimension;
	int split(vector<string>& vecteur, string chaine, char separateur);
};

#endif
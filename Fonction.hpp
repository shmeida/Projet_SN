#ifndef _FONCTION
#define _FONCTION
#include <string>
#include <list>
#include "Item.hpp"
#include "Vector.hpp"
using namespace std;

class Fonction
{
public:
	Fonction();
	~Fonction();
	void add(double c, char t);
	list<Item> items;
	string expression;
	double calcul(Vector& x);
	void affichage();
};

#endif
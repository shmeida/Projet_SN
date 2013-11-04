#ifndef _FONCTION
#define _FONCTION
#include <string>
#include <list>
#include <vector>
#include "Item.h"
using namespace std;

typedef vector<double> Vector;
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
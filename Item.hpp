#ifndef _ITEM
#define _ITEM
#include <string>
#include "Vector.hpp"
#include <iostream>
using namespace std;

class Item
{
public:
	Item(double c, char t);
	~Item();
	double coif;
	char type;
	double calcul(double x);
	void affichage();
};

#endif
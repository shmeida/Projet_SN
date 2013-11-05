#ifndef _ITEM
#define _ITEM
#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef vector<double> Vector;
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
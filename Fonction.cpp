#include <string>
#include <list>
#include "Fonction.hpp"
using namespace std;


Fonction::Fonction()
{

}

Fonction::~Fonction()
{
}
void Fonction::add(double c, char t)
{
	Item* i = new Item(c, t);
	this->items.push_back(*i);
}
double Fonction::calcul(Vector& x)
{
	double sum=0;
	int i=0;
	list<Item>::iterator plist; 
	plist = this->items.begin();
	sum += plist->calcul(0);
	plist++;
	for(; plist !=this->items.end(); plist++,i++)
		sum += plist->calcul(x[i]);
	return sum;
}

void Fonction::affichage()
{
	list<Item>::iterator plist; 
	for(plist = this->items.begin(); plist !=this->items.end(); plist++)
	{
		(*plist).affichage();
		cout << " ";
	}
	cout << endl;
}

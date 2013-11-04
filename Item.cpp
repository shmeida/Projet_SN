
#include <string>
#include "Item.h"
using namespace std;


	Item::Item()
	{
		
	}
	Item::Item(double c, char t)
	{
		this->coif=c;
		this->type=t;

	}

	
	double Item::calcul(double x)
	{
		switch (this->type)
		{
		case 'a':
			return this->coif * x;
		case 'b':
			return this->coif * x * x;
		case 'c':
			return this->coif * sin(x);
		case 'd':
			return this->coif * cos(x);
		case 'e':
			return this->coif * exp(x);
		case 'f':
			return this->coif * log(x); 
			return this->coif * exp(x);
		case 'z':
			return coif; 
		}
	}

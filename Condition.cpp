#include"Condition.hpp"

using namespace std;

Condition::Condition()
{
	lireFicher();
}

Condition::~Condition()
{
	this->conditions.~vector();
	this->optimis.~Fonction();
}

Condition::Condition(Condition &con)
{
	this->borneInf = con.borneInf;
	this->borneSup = con.borneSup;
	this->dimension = con.dimension;
	this->conditions = con.conditions;
}

Condition Condition::operator=(Condition &con)
{
	Condition* _temp = new Condition(con);
	Condition &_tempReference = *_temp;
	return _tempReference;
}

bool Condition::respecteCondition(Vector & v)
{
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(v[i] < borneInf[i])
			return false;
		if(v[i] > borneSup[i])
			return false;
	}

	for(unsigned int i = 0; i < conditions.size(); i++)
	{
		if(conditions[i].calcul(v) > 0.0)
			return false;
	}
	return true;
}

Vector Condition::getBorneInf()
{
	return this->borneInf;
}

Vector Condition::getBorneSup()
{
	return this->borneSup;
}

void Condition::lireFicher()
{
	ifstream fin("a.txt");
	if(fin==NULL)
		printf("error\n");
	string str,item;
	getline(fin,str);
	Fonction* fon = new Fonction();
	istringstream stream1(str); 
	while(stream1>>item) 
	{
		vector<string> VecStr;
		split(VecStr, item, ',');
		double lol = atof(VecStr[0].c_str());
		char a = VecStr[1].at(0);
		fon->add(lol, a);
	}
	optimis = *fon;

	getline(fin,str);
	istringstream stream2(str);
	while(stream2>>item) 
	{
		borneInf.push_back( atof(item.c_str()));
	}

	getline(fin,str);
	istringstream stream3(str);
	while(stream3>>item) 
	{
		borneSup.push_back( atof(item.c_str()));
	}

	while(getline(fin,str))
	{
		cout<<str<<endl;
		Fonction* fon = new Fonction();
		istringstream stream4(str); 
		while(stream4>>item) 
		{
			vector<string> VecStr;
			split(VecStr, item, ',');
			double lol = atof(VecStr[0].c_str());
			char a = VecStr[1].at(0);
			fon->add(lol, a);
		}
		conditions.push_back(*fon);
	}
}

int Condition::split(vector<string>& vecteur, string chaine, char separateur)
{
	vecteur.clear();

	string::size_type stTemp = chaine.find(separateur);

	while(stTemp != string::npos)
	{
		vecteur.push_back(chaine.substr(0, stTemp));
		chaine = chaine.substr(stTemp + 1);
		stTemp = chaine.find(separateur);
	}

	vecteur.push_back(chaine);

	return vecteur.size();
}

void Condition::afficherConditions()
{
	for(unsigned int i = 0; i< conditions.size(); i++)
	{
		conditions[i].affichage();
	}
}



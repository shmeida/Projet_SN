#include"Condition.h" 
#include<iostream>
using namespace std;
int main()
{
	Condition con;
	for(unsigned int i = 0; i< con.getBorneSup().size(); i++)
	{
		cout << con.getBorneSup()[i] << " ";
	}
	cout << endl;
	Vector v;
	v.push_back(5);
	v.push_back(1);
	bool r = con.respecteCondition(v);
	cout << r;
	getchar();
}
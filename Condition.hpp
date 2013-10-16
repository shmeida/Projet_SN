#ifndef CONDTION_HPP
#define CONDTION_HPP

#ifndef MY_VECTOR
#define MY_VECTOR
#include <vector>
typedef std::vector<double> Vector;
#endif

class Condition
{
public:
	double calculF(Vector x);
}

#endif
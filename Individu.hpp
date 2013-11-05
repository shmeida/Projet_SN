#ifndef Individu_HPP
#define Individu_HPP

#ifndef MY_VECTOR
#define MY_VECTOR
#include <vector>
typedef std::vector<double> Vector;
#endif

struct Individu : public std::pair<float, Vector> {};

bool operator< (Individu const& p1, Individu const& p2 );

#endif
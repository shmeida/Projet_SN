#ifndef Individu_HPP
#define Individu_HPP

#include "Vector.hpp"

typedef std::pair<double, Vector> Individu;

//struct Individu : public  {};

bool operator< (Individu const& p1, Individu const& p2 );

#endif
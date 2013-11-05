#ifndef Individu_HPP
#define Individu_HPP

#include "Vector.hpp"

struct Individu : public std::pair<double, Vector> {};

bool operator< (Individu const& p1, Individu const& p2 );

#endif
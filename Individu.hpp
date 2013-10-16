#ifndef Individu_HPP
#define Individu_HPP

#ifndef MY_VECTOR
#define MY_VECTOR
#include <vector>
typedef std::vector<double> Vector;
#endif

struct Individu : public std::pair<int, Vector> {};

bool operator<(Individu const& p1, Individu const& p2 )
{
  return (p1.first < p2.first);
}

#endif
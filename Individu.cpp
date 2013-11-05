#include "Individu.hpp"

bool operator< (Individu const& p1, Individu const& p2 )
{
  return (p1.first < p2.first);
}

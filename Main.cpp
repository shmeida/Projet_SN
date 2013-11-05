#include <iostream>
#include "Individu.hpp"


int main() {
	Individu a, b;
	a.first = 0.1f;
	b.first = 0.2f;

	std::cout << (a < b) << std::endl;

}
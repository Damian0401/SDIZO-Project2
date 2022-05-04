#include <iostream>
#include "include/structures/IncidentMatrix.hpp"

int main()
{
	int tab[] = { 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 0, 4, 4, 1, 5, 3, 4, 6 };

	auto matrix = new SDIZO::IncidentMatrix(6, 5, tab);

	matrix->print(std::cout);

	delete matrix;
}

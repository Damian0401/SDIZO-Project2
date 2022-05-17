#include <iostream>
#include "include/SDIZO.hpp"

int main()
{
	size_t tab[] = {
		0, 1, 2, 
		0, 2, 4, 
		1, 2, 2, 
		1, 3, 4, 
		1, 4, 2, 
		2, 4, 3, 
		3, 4, 3, 
		3, 5, 2, 
		4, 5, 2
	};

	auto matrix = new SDIZO::IncidentMatrix(9, 6, tab);

	matrix->print(std::cout);

	auto mst1 = SDIZO::Prim::generateMst(matrix);

	mst1->print(std::cout);

	auto mst2 = SDIZO::Kruskal::generateMst(matrix);

	mst2->print(std::cout);

	delete mst1;

	delete mst2;

	delete matrix;

	auto list = new SDIZO::NeighborhoodList(9, 6, tab);

	list->print(std::cout);

	auto mst3 = SDIZO::Prim::generateMst(list);

	mst3->print(std::cout);

	auto mst4 = SDIZO::Kruskal::generateMst(list);

	mst4->print(std::cout);

	delete mst3;
	
	delete mst4;

	delete list;
}

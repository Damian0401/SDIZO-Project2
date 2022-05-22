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

	auto pathOne = SDIZO::Dijkstra::findShortestPath(matrix, 0, 4);

	pathOne.print(std::cout);

	delete matrix;

	auto list = new SDIZO::NeighborhoodList(9, 6, tab);

	auto pathTwo = SDIZO::Dijkstra::findShortestPath(list, 0, 4);

	pathTwo.print(std::cout);

	delete list;
}

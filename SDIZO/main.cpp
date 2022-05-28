#include <iostream>
#include "include/SDIZO.hpp"

int main()
{
	std::string basePath = "C:/Users/szkol/Desktop/SDIZO/projekt/SDIZO-Project2/SDIZO/data/";

	SDIZO::GraphReader reader(basePath);

	auto matrix = reader.readMatrixGraph("graph-1.txt");

	auto pathOne = SDIZO::BellmanFord::findShortestPath(matrix, 0, 4);

	pathOne.print(std::cout);

	delete matrix;

	auto list = reader.readListGraph("graph-1.txt");

	auto pathTwo = SDIZO::BellmanFord::findShortestPath(list, 0, 4);

	pathTwo.print(std::cout);

	delete list;
}

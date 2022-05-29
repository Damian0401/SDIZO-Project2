#include <iostream>
#include <random>
#include "include/SDIZO.hpp"

int main()
{
	std::string basePath = "C:/Users/szkol/Desktop/SDIZO/projekt/SDIZO-Project2/SDIZO/data/";

	auto rawData = SDIZO::GraphGenerator::generate(1, 4);

	auto matrix = new SDIZO::IncidentMatrix(rawData.edgeNumber, rawData.vertexNumber, rawData.data);

	matrix->print(std::cout);

	auto list = new SDIZO::NeighborhoodList(rawData.edgeNumber, rawData.vertexNumber, rawData.data);

	list->print(std::cout);

	delete[] rawData.data;
}

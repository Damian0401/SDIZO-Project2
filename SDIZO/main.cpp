#include <iostream>
#include <random>
#include "include/SDIZO.hpp"

int main()
{
	using namespace SDIZO;

	std::string basePath = "C:/Users/szkol/Desktop/SDIZO/projekt/SDIZO-Project2/SDIZO/data/";

	GraphReader reader(basePath);

	auto fileName = "graph-2.txt";

	auto from = 0;
	auto to = 0;

	auto matrix = reader.readMatrixGraph(fileName);

	auto list = reader.readListGraph(fileName);

	std::cout << "Dijkstra" << std::endl;

	auto dijkstraMatrixPath = Dijkstra::findShortestPath(matrix, from, to);
	dijkstraMatrixPath.print(std::cout);

	auto dijkstraListPath = Dijkstra::findShortestPath(list, from, to);
	dijkstraListPath.print(std::cout);

	std::cout << "BellmanFord" << std::endl;

	auto bellmanFordMatrixPath = BellmanFord::findShortestPath(matrix, from, to);
	bellmanFordMatrixPath.print(std::cout);

	auto bellmanFordListPath = BellmanFord::findShortestPath(list, from, to);
	bellmanFordListPath.print(std::cout);

	std::cout << "Kruskal" << std::endl;

	auto kruskalMatrixMst = Kruskal::generateMst(matrix);
	kruskalMatrixMst->print(std::cout);
	delete kruskalMatrixMst;

	auto kruskalListMst = Kruskal::generateMst(list);
	kruskalListMst->print(std::cout);
	delete kruskalListMst;

	std::cout << "Prim" << std::endl;

	auto primMatrixMst = Prim::generateMst(matrix);
	primMatrixMst->print(std::cout);
	delete primMatrixMst;

	auto primListMst = SDIZO::Prim::generateMst(list);
	primListMst->print(std::cout);
	delete primListMst;

	delete matrix;
	delete list;
}

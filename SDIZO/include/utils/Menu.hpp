#pragma once

#include <iostream>
#include "GraphReader.hpp"
#include "GraphGenerator.hpp"
#include "Tests.hpp"
#include "../algorithms/BellmanFord.hpp"
#include "../algorithms/Dijkstra.hpp"
#include "../algorithms/Kruskal.hpp"
#include "../algorithms/Prim.hpp"

namespace SDIZO
{
	class Menu
	{
	public:
		Menu(const std::string& basePath);
		void run();

	private:
		GraphReader reader;
		GraphGenerator generator;
		Tests tests;

		void minimumSpanningTreeSubmenu();
		void shortestPathSubmenu();
		void readGraphFromFile(IncidentMatrix** matrix, NeighborhoodList** list);
		void generateRandomGraph(IncidentMatrix** matrix, NeighborhoodList** list);
		size_t printSubmenuOptions(std::string firstAlgorithm, std::string secondAlgorithm);
		void tryPrintGraph(IncidentMatrix* matrix, NeighborhoodList* list);
		void runPrimAlgorithm(IncidentMatrix* matrix, NeighborhoodList* list);
		void runKruskalAlgorithm(IncidentMatrix* matrix, NeighborhoodList* list);
		void runDijkstraAlgorithm(IncidentMatrix* matrix, NeighborhoodList* list);
		void runBellmanFordAlgorithm(IncidentMatrix* matrix, NeighborhoodList* list);
		void tryDeleteGraph(IncidentMatrix* matrix, NeighborhoodList* list);
		void runTests();
	};
}
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "../structures/Array.hpp"
#include "../structures/IncidentMatrix.hpp"
#include "../structures/NeighborhoodList.hpp"
#include "../utils/Timer.hpp"
#include "../utils/GraphGenerator.hpp"
#include "../utils/Enums.hpp"
#include "../algorithms/Prim.hpp"
#include "../algorithms/Kruskal.hpp"
#include "../algorithms/Dijkstra.hpp"
#include "../algorithms/BellmanFord.hpp"

namespace SDIZO
{
	class Tests
	{
	public:
		Tests(const std::string& basePath, const TimerPrecision& precision, size_t repeats);
		void run(Array<size_t>& vertices);

	private:
		std::string basePath;
		GraphGenerator generator;
		TimerPrecision precision;
		Timer timer;
		size_t repeats;

		long long getAverargeTime(Algorithm algorithm, GraphRepresentation graph, size_t density, size_t vertexNumber);
	};
}
#pragma once

#include "../structures/IncidentMatrix.hpp"
#include "../structures/NeighborhoodList.hpp"
#include "../structures/Path.hpp"
#include "../structures/PathEdge.hpp"

namespace SDIZO
{
	class Dijkstra
	{
	public:
		static Path findShortestPath(IncidentMatrix* incidentMatrix, size_t from, size_t to);
		static Path findShortestPath(NeighborhoodList* neighborhoodList, size_t from, size_t to);
	};
}


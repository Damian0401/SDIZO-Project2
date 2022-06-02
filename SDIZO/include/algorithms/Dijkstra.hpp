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
		/// <summary>
		/// Find the shortest path from one vertex to another 
		/// </summary>
		/// <param name="incidentMatrix"> Graph to be searched </param>
		/// <param name="from"> Start vertex </param>
		/// <param name="to"> End vertex </param>
		/// <returns></returns>
		static Path findShortestPath(IncidentMatrix* incidentMatrix, size_t from, size_t to);
		/// <summary>
		/// Find the shortest path from one vertex to another 
		/// </summary>
		/// <param name="neighborhoodList"> Graph to be searched </param>
		/// <param name="from"> Start vertex </param>
		/// <param name="to"> End vertex </param>
		/// <returns></returns>
		static Path findShortestPath(NeighborhoodList* neighborhoodList, size_t from, size_t to);
	};
}


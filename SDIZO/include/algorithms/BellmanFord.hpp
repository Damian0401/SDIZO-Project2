#pragma once

#include "../structures/IncidentMatrix.hpp"
#include "../structures/NeighborhoodList.hpp"
#include "../structures/Path.hpp"
#include "../structures/PathEdge.hpp"

namespace SDIZO
{
	class BellmanFord
	{
	public:
		/// <summary>
		/// Find the shortest path from one vertex to another 
		/// </summary>
		/// <param name="incidentMatrix"> Graph to Graph to be searched </param>
		/// <param name="from"> Start vertex </param>
		/// <param name="to"> End vetrex </param>
		/// <returns></returns>
		static Path findShortestPath(IncidentMatrix* incidentMatrix, size_t from, size_t to);
		/// <summary>
		/// Find the shortest path from one vertex to another 
		/// </summary>
		/// <param name="neighborhoodList"> Graph to Graph to be searched </param>
		/// <param name="from"> Start vertex </param>
		/// <param name="to"> End vetrex </param>
		/// <returns></returns>
		static Path findShortestPath(NeighborhoodList* neighborhoodList, size_t from, size_t to);
	};
}


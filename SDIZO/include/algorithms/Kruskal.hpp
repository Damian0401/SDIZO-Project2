#pragma once

#include "../structures/IncidentMatrix.hpp"
#include "../structures/NeighborhoodList.hpp"
#include "../structures/EdgeHeap.hpp"

namespace SDIZO
{
	class Kruskal
	{
	public:
		/// <summary>
		/// Generate minimum spinning tree
		/// </summary>
		/// <param name="incidentMatrix"> Graph to be searched </param>
		/// <returns></returns>
		static IncidentMatrix* generateMst(IncidentMatrix* incidentMatrix);
		/// <summary>
		/// Generate minimum spinning tree
		/// </summary>
		/// <param name="neighborhoodList"> Graph to be searched </param>
		/// <returns></returns>
		static NeighborhoodList* generateMst(NeighborhoodList* neighborhoodList);
	};

}
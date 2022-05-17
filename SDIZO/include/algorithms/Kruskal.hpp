#pragma once

#include "../structures/IncidentMatrix.hpp"
#include "../structures/NeighborhoodList.hpp"
#include "../structures/EdgeHeap.hpp"

namespace SDIZO
{
	class Kruskal
	{
	public:
		static IncidentMatrix* generateMst(IncidentMatrix* incidentMatrix);
		static NeighborhoodList* generateMst(NeighborhoodList* neighborhoodList);
	};

}
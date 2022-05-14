#pragma once
#include "../structures/IncidentMatrix.hpp"
#include "../structures/NeighborhoodList.hpp"

namespace SDIZO
{
	class Prim
	{
	public:
		static IncidentMatrix generateMst(const IncidentMatrix& IncidentMatrix);
		static NeighborhoodList generateMst(const NeighborhoodList& IncidentMatrix);
	};
}
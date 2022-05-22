#pragma once

#include "PathEdge.hpp"
#include "Array.hpp"

namespace SDIZO
{
	class Path
	{
	public:
		Path();
		Path(const Path& path); 
		void addEdge(PathEdge edge);
		void print(std::ostream& out);

	private:
		Array<PathEdge> edges;
		size_t totalCost;
	};
}
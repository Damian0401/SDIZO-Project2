#pragma once

#include "Edge.hpp"
#include <iostream>
#include <iomanip>

namespace SDIZO
{
	class NeighborhoodList
	{
	public:
		NeighborhoodList(size_t edgeNumber, size_t vertexNumber, size_t* data);
		~NeighborhoodList();
		void print(std::ostream& out);
		size_t getVertexNumber();
		Edge** getEdges();

	private:
		Edge** edges;
		size_t edgeNumber;
		size_t vertexNumber;
	};
}
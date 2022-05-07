#pragma once

#include "Edge.hpp"
#include <iostream>
#include <iomanip>

namespace SDIZO
{
	class NeighborhoodList
	{
	public:
		NeighborhoodList(int edgeNumber, int vertexNumber, int* data);
		~NeighborhoodList();
		void print(std::ostream& out);

	private:
		Edge** edges;
		int edgeNumber;
		int vertexNumber;
	};
}
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
		/// <summary>
		/// Print graph to the selected ostream
		/// </summary>
		/// <param name="out"></param>
		void print(std::ostream& out);
		/// <summary>
		/// Get number of vertices
		/// </summary>
		/// <returns></returns>
		size_t getVertexNumber();
		/// <summary>
		/// Get edges handler
		/// </summary>
		/// <returns></returns>
		Edge** getEdges();

	private:
		Edge** edges;
		size_t edgeNumber;
		size_t vertexNumber;
	};
}
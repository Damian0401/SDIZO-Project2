#pragma once

#include "../utils/Enums.hpp"
#include <iostream>
#include <iomanip>

namespace SDIZO
{
	class IncidentMatrix
	{
	public:
		IncidentMatrix(size_t edgeNumber, size_t vertexNumber, size_t* data);
		~IncidentMatrix();
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
		/// Get number of edges
		/// </summary>
		/// <returns></returns>
		size_t getEdgeNumber();
		/// <summary>
		/// Get matrix handler
		/// </summary>
		/// <returns></returns>
		MatrixCell** getMatrix();
		/// <summary>
		/// Get array with values
		/// </summary>
		/// <returns></returns>
		size_t* getValues();

	private:
		size_t vertexNumber;
		size_t edgeNumber;
		size_t* edgeValues;
		MatrixCell** matrixHandler;
	};
}
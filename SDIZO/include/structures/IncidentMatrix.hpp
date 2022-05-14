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
		void print(std::ostream& out);

	private:
		size_t vertexNumber;
		size_t edgeNumber;
		size_t* edgeValues;
		MatrixCell** matrixHandler;
	};
}
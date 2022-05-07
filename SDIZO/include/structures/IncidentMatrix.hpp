#pragma once

#include "../utils/Enums.hpp"
#include <iostream>
#include <iomanip>

namespace SDIZO
{
	class IncidentMatrix
	{
	public:
		IncidentMatrix(int edgeNumber, int vertexNumber, int* data);
		~IncidentMatrix();
		void print(std::ostream& out);

	private:
		int vertexNumber;
		int edgeNumber;
		int* edgeValues;
		MatrixCell** matrixHandler;
	};
}
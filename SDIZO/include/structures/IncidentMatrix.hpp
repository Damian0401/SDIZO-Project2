#pragma once

#include "../utils/Enums.hpp"
#include <iostream>

namespace SDIZO
{
	class IncidentMatrix
	{
	public:
		IncidentMatrix(int, int, int*);
		~IncidentMatrix();
		void print(std::ostream&);

	private:
		int verticeNumber;
		int edgeNumber;
		int* edgeValues;
		MatrixCell** matrixHandler;
	};
}
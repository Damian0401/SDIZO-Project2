#pragma once

#include <iostream>
#include <fstream>
#include <tuple>
#include "../structures/IncidentMatrix.hpp"
#include "../structures/NeighborhoodList.hpp"

namespace SDIZO
{
	class GraphReader
	{
	public:
		GraphReader(std::string basePath);

		IncidentMatrix* readMatrixGraph(std::string fileName);
		NeighborhoodList* readListGraph(std::string fileName);

	private:
		std::string basePath;

		std::tuple<size_t, size_t, size_t*> readData(std::string fileName);
	};

}
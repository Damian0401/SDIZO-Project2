#pragma once

#include <random>
#include "../structures/RawGraphData.hpp"

namespace SDIZO
{
	class GraphGenerator
	{
	public:
		/// <summary>
		/// Generate random graph
		/// </summary>
		/// <param name="density"> Graph density as float [0 - 1] </param>
		/// <param name="vertexNumber"> Number of vertices </param>
		/// <param name="maxValue"> Max value of the edge </param>
		/// <returns></returns>
		RawGraphData generate(float density, size_t vertexNumber, size_t maxValue = 1000);

	private:

	};
}
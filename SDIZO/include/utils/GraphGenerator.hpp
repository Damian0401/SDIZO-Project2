#pragma once

#include <random>
#include "../structures/RawGraphData.hpp"

namespace SDIZO
{
	class GraphGenerator
	{
	public:
		RawGraphData generate(float density, size_t vertexNumber, size_t maxValue = 1000);

	private:

	};
}
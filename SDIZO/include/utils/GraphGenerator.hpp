#pragma once

#include <random>
#include "../structures/RawGraphData.hpp"

namespace SDIZO
{
	class GraphGenerator
	{
	public:
		static RawGraphData generate(float density, size_t vertexNumber, size_t maxValue = 10);

	private:

	};
}
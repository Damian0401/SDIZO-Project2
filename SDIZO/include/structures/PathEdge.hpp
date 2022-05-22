#pragma once

#include <iostream>

namespace SDIZO
{
	struct PathEdge
	{
		size_t value;
		size_t previous;
		size_t next;

		PathEdge(size_t value, size_t previous, size_t next)
			: value(value), previous(previous), next(next) {}

		PathEdge() : value(0), previous(0), next(0) {}

		friend std::ostream& operator<<(std::ostream& stream, const PathEdge& edge)
		{
			stream << "from " << edge.previous << " to " << edge.next << " for " << edge.value;

			return stream;
		}

		friend bool operator==(PathEdge const& first, PathEdge const& second)
		{
			return first.value == second.value;
		}
	};
}
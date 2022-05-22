#pragma once

#include <iostream>

namespace SDIZO
{
	struct Edge
	{
		Edge* previous;
		Edge* next;
		size_t origin;
		size_t destination;
		size_t value;

		Edge(size_t origin, size_t destination, size_t value)
			: origin(origin), destination(destination),
			value(value), previous(nullptr), next(nullptr) {}

		Edge() : origin(0), destination(0), value(0),
			previous(nullptr), next(nullptr) {}

		friend std::ostream& operator<<(std::ostream& stream, const Edge& edge)
		{
			stream << edge.origin << " --> " << edge.destination << " [" << edge.value << ']';

			return stream;
		}

		friend bool operator==(Edge const& first, Edge const& second)
		{
			return first.value == second.value;
		}
	};
}
#pragma once

namespace SDIZO
{
	struct Edge
	{
		Edge(size_t origin, size_t destination, size_t value)
			: origin(origin), destination(destination), 
			value(value), previous(nullptr), next(nullptr) {}

		Edge* previous;
		Edge* next;
		size_t origin;
		size_t destination;
		size_t value;
	};
}
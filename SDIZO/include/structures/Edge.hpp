#pragma once

namespace SDIZO
{
	struct Edge
	{
		Edge(int origin, int destination, int value)
			: origin(origin), destination(destination), 
			value(value), previous(nullptr), next(nullptr) {}

		Edge* previous;
		Edge* next;
		int origin;
		int destination;
		int value;
	};
}
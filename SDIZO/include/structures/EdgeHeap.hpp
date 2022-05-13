#pragma once

#include "Edge.hpp"
#include <iostream>

namespace SDIZO
{
	class EdgeHeap
	{
	public:
		EdgeHeap(bool clearOnDelete = true);
		~EdgeHeap();
		void push(Edge* edge);
		Edge* pop();
		bool isEmpty();
	private:
		bool clearOnDelete;
		size_t size;
		Edge** root;

		void fixUp();
		void fixDown();
	};
}

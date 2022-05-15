#include "..\..\include\structures\NeighborhoodList.hpp"

SDIZO::NeighborhoodList::NeighborhoodList(size_t edgeNumber, size_t vertexNumber, size_t* data)
{
	this->edgeNumber = edgeNumber;
	this->vertexNumber = vertexNumber;
	this->edges = new Edge* [vertexNumber];

	for (size_t i = 0; i < vertexNumber; i++)
	{
		this->edges[i] = nullptr;
	}

	Edge* edge = nullptr;
	size_t dataNumber = 3 * edgeNumber;
	size_t currentIndex = 0;

	while (currentIndex < dataNumber)
	{
		edge = this->edges[data[currentIndex]];

		if (edge == nullptr)
		{
			this->edges[data[currentIndex]] = new Edge(data[currentIndex], data[currentIndex + 1], data[currentIndex + 2]);
			currentIndex += 3;
			continue;
		}

		while (edge->next != nullptr)
		{
			edge = edge->next;
		}

		edge->next = new Edge(data[currentIndex], data[currentIndex + 1], data[currentIndex + 2]);
		edge->next->previous = edge;
		currentIndex += 3;
	}
}

SDIZO::NeighborhoodList::~NeighborhoodList()
{
	if (this->edges != nullptr)
	{
		Edge* edgeToDelete = nullptr;
		for (size_t i = 0; i < this->vertexNumber; i++)
		{
			edgeToDelete = this->edges[i];

			if (edgeToDelete == nullptr)
			{
				continue;
			}

			while (edgeToDelete->next != nullptr)
			{
				edgeToDelete = edgeToDelete->next;
				delete edgeToDelete->previous;
			}
			delete edgeToDelete;
		}
		delete[] this->edges;
	}
}

void SDIZO::NeighborhoodList::print(std::ostream& out)
{
	Edge* edge = nullptr;

	for (size_t i = 0; i < this->vertexNumber; i++)
	{
		out << i << " --> ";

		edge = this->edges[i];

		if (edge == nullptr)
		{
			out << std::endl;
			continue;
		}

		while (edge != nullptr)
		{
			out << std::setw(2) << edge->destination << '[' << std::setw(2) << edge->value << "] | ";
			edge = edge->next;
		}

		out << std::endl;
	}
}

size_t SDIZO::NeighborhoodList::getVertexNumber()
{
	return this->vertexNumber;
}

SDIZO::Edge** SDIZO::NeighborhoodList::getEdges()
{
	return this->edges;
}

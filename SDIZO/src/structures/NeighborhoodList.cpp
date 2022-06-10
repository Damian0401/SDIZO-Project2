#include "..\..\include\structures\NeighborhoodList.hpp"

SDIZO::NeighborhoodList::NeighborhoodList(size_t edgeNumber, size_t vertexNumber, size_t* data)
{
	// Set constants
	this->edgeNumber = edgeNumber;
	this->vertexNumber = vertexNumber;
	this->edges = new Edge* [vertexNumber];

	// Iterate through all vertices
	for (size_t i = 0; i < vertexNumber; i++)
	{
		this->edges[i] = nullptr;
	}

	Edge* edge = nullptr;
	size_t dataNumber = 3 * edgeNumber;
	size_t currentIndex = 0;

	while (currentIndex < dataNumber)
	{
		// Get edge from array
		edge = this->edges[data[currentIndex]];

		// Check if edge exists
		if (edge == nullptr)
		{
			// Create new edge
			this->edges[data[currentIndex]] = new Edge(data[currentIndex], data[currentIndex + 1], data[currentIndex + 2]);
			currentIndex += 3;
			continue;
		}

		// Find the last next edge
		while (edge->next != nullptr)
		{
			edge = edge->next;
		}

		// Create new edge
		edge->next = new Edge(data[currentIndex], data[currentIndex + 1], data[currentIndex + 2]);
		edge->next->previous = edge;
		currentIndex += 3;
	}
}

SDIZO::NeighborhoodList::~NeighborhoodList()
{
	// Check if list is not empty
	if (this->edges != nullptr)
	{
		// Create empty edge handler
		Edge* edgeToDelete = nullptr;

		// Iterate through all vertices
		for (size_t i = 0; i < this->vertexNumber; i++)
		{
			// Get first edge from index
			edgeToDelete = this->edges[i];

			// Check if edge is empty
			if (edgeToDelete == nullptr)
			{
				continue;
			}

			// Iterate through all edges from index
			while (edgeToDelete->next != nullptr)
			{
				// Delete edges
				edgeToDelete = edgeToDelete->next;
				delete edgeToDelete->previous;
			}
			delete edgeToDelete;
		}

		// Delete array with edges
		delete[] this->edges;
	}
}

void SDIZO::NeighborhoodList::print(std::ostream& out)
{
	Edge* edge = nullptr;

	// Iterate through all vertices
	for (size_t i = 0; i < this->vertexNumber; i++)
	{
		out << std::setw(2) << i << " --> ";

		// Get edge from index
		edge = this->edges[i];

		// Check if edge exists
		if (edge == nullptr)
		{
			out << std::endl;
			continue;
		}

		while (edge != nullptr)
		{
			// Display edge
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

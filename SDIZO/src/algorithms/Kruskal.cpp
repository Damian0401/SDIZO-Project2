#include "..\..\include\algorithms\Kruskal.hpp"

SDIZO::IncidentMatrix* SDIZO::Kruskal::generateMst(IncidentMatrix* incidentMatrix)
{
	// Get necessary stuff from the graph 
	size_t vertexNumber = incidentMatrix->getVertexNumber();
	size_t edgeNumber = incidentMatrix->getEdgeNumber();
	size_t* values = incidentMatrix->getValues();
	MatrixCell** matrix = incidentMatrix->getMatrix();
	size_t resultSize = (vertexNumber - 1) * 3;
	size_t* resultBuffor = new size_t[resultSize];
	size_t resultIndex = 0;
	EdgeHeap* heap = new EdgeHeap();

	// Assign unique ids to every tree
	size_t* treeIds = new size_t[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		treeIds[i] = i;
	}

	Edge* buffor = nullptr;
	// Iterate through all edges
	for (size_t edge = 0; edge < edgeNumber; edge++)
	{
		buffor = new Edge(-1, -1, values[edge]);

		// Iterate through all vertices and add them to the heap
		for (size_t vertex = 0; vertex < vertexNumber; vertex++)
		{
			if (matrix[vertex][edge] == MatrixCell::Origin)
			{
				buffor->origin = vertex;
			}

			if (matrix[vertex][edge] == MatrixCell::Destination)
			{
				buffor->destination = vertex;
			}
		}

		heap->push(buffor);
	}

	while (!heap->isEmpty())
	{
		buffor = heap->pop();

		// Check if tree ids are different 
		if (treeIds[buffor->origin] != treeIds[buffor->destination])
		{
			// Add edge to the result
			resultBuffor[3 * resultIndex] = buffor->origin;
			resultBuffor[3 * resultIndex + 1] = buffor->destination;
			resultBuffor[3 * resultIndex + 2] = buffor->value;

			// Correct tree ids
			int oldTreeId = treeIds[buffor->origin];
			int newTreeId = treeIds[buffor->destination];
			for (size_t id = 0; id < vertexNumber; id++)
			{
				if (treeIds[id] == oldTreeId)
				{
					treeIds[id] = newTreeId;
				}
			}

			resultIndex++;
		}
	}

	// Create result tree
	IncidentMatrix* result = new IncidentMatrix(vertexNumber - 1, vertexNumber, resultBuffor);
	delete[] resultBuffor;
	delete heap;

	return result;
}

SDIZO::NeighborhoodList* SDIZO::Kruskal::generateMst(NeighborhoodList* neighborhoodList)
{
	// Get necessary stuff from the graph 
	size_t vertexNumber = neighborhoodList->getVertexNumber();
	size_t resultSize = (vertexNumber - 1) * 3;
	size_t* resultBuffor = new size_t[resultSize];
	size_t resultIndex = 0;
	Edge** edges = neighborhoodList->getEdges();
	EdgeHeap* heap = new EdgeHeap(false);

	// Assign unique ids to every tree
	size_t* treeIds = new size_t[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		treeIds[i] = i;
	}

	Edge* buffor = nullptr;
	// Iterate through all vertices and add them to the heap
	for (size_t vertex = 0; vertex < vertexNumber; vertex++)
	{
		buffor = edges[vertex];

		while (buffor != nullptr)
		{
			heap->push(buffor);
			buffor = buffor->next;
		}
	}

	while (!heap->isEmpty())
	{
		buffor = heap->pop();

		// Check if tree ids are different 
		if (treeIds[buffor->origin] != treeIds[buffor->destination])
		{
			// Add edge to the result
			resultBuffor[3 * resultIndex] = buffor->origin;
			resultBuffor[3 * resultIndex + 1] = buffor->destination;
			resultBuffor[3 * resultIndex + 2] = buffor->value;

			// Correct tree ids
			int oldTreeId = treeIds[buffor->origin];
			int newTreeId = treeIds[buffor->destination];
			for (size_t id = 0; id < vertexNumber; id++)
			{
				if (treeIds[id] == oldTreeId)
					treeIds[id] = newTreeId;
			}

			resultIndex++;
		}
	}

	// Create result tree
	NeighborhoodList* result = new NeighborhoodList(vertexNumber - 1, vertexNumber, resultBuffor);
	delete[] resultBuffor;
	delete heap;

	return result;
}

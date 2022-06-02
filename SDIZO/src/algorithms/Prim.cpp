#include "..\..\include\algorithms\Prim.hpp"

SDIZO::IncidentMatrix* SDIZO::Prim::generateMst(IncidentMatrix* incidentMatrix)
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

	// Create array to store information, whether vertex was visited
	bool* visitedVertices = new bool[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		visitedVertices[i] = false;
	}

	size_t currentVertexIndex;

	// Push edges that can be reached to the heap
	auto pushReachableEdges = [&]()
	{
		// Iterate through all edges to find begin
		for (size_t begin = 0; begin < edgeNumber; begin++)
		{
			if (matrix[currentVertexIndex][begin] == MatrixCell::None)
			{
				continue;
			}

			// Iterate through all vertices to find end
			for (size_t end = 0; end < vertexNumber; end++)
			{
				if (matrix[end][begin] == MatrixCell::None || end == currentVertexIndex)
				{
					continue;
				}

				if (visitedVertices[end])
				{
					continue;
				}

				// Push edge to the heap
				heap->push(new Edge(currentVertexIndex, end, values[begin]));
			}

		}
	};

	// Set initial states
	currentVertexIndex = 0;
	visitedVertices[currentVertexIndex] = true;
	pushReachableEdges();

	// Iterate through all vertices
	for (size_t i = 0; i < vertexNumber - 1;)
	{
		Edge* candidate = heap->pop();

		// Check if destination of edge from top of heap was visited
		if (!visitedVertices[candidate->destination])
		{
			// Save results
			currentVertexIndex = candidate->destination;
			resultBuffor[3 * resultIndex] = candidate->origin;
			resultBuffor[3 * resultIndex + 1] = candidate->destination;
			resultBuffor[3 * resultIndex + 2] = candidate->value;
			visitedVertices[currentVertexIndex] = true;
			pushReachableEdges();
			resultIndex++;
			i++;
		}

		delete candidate;
	}

	// Create result tree
	IncidentMatrix* result = new IncidentMatrix(vertexNumber - 1, vertexNumber, resultBuffor);
	delete[] resultBuffor;
	delete heap;

	return result;
}

SDIZO::NeighborhoodList* SDIZO::Prim::generateMst(NeighborhoodList* neighborhoodList)
{
	// Get necessary stuff from the graph 
	size_t vertexNumber = neighborhoodList->getVertexNumber();
	size_t resultSize = (vertexNumber - 1) * 3;
	size_t* resultBuffor = new size_t[resultSize];
	size_t resultIndex = 0;
	Edge** edges = neighborhoodList->getEdges();
	EdgeHeap* heap = new EdgeHeap(false);

	// Create array to store information, whether vertex was visited
	bool* visitedVertices = new bool[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		visitedVertices[i] = false;
	}

	size_t currentVertexIndex;

	// Push edges that can be reached to the heap
	auto pushReachableEdges = [&]()
	{
		// Iterate through all edges to find begin
		for (size_t i = 0; i < vertexNumber; i++)
		{
			Edge* edge = edges[i];

			if (edge == nullptr)
			{
				continue;
			}

			while (edge != nullptr)
			{
				// Check if origin of the edge was not visited
				if (edge->origin == currentVertexIndex && !visitedVertices[edge->destination])
				{
					heap->push(edge);
				}

				// Check if destination of the edge was not visited
				if (edge->destination == currentVertexIndex && !visitedVertices[edge->origin])
				{
					heap->push(edge);
				}

				edge = edge->next;
			}
		}
	};

	// Set initial states
	currentVertexIndex = 0;
	visitedVertices[currentVertexIndex] = true;
	pushReachableEdges();

	// Iterate through all vertices
	for (size_t i = 0; i < vertexNumber - 1;)
	{
		Edge* candidate = heap->pop();

		// Check if origin or destination of the edge is not visited
		if (!visitedVertices[candidate->destination] || !visitedVertices[candidate->origin])
		{
			// Select new current vertex
			currentVertexIndex = visitedVertices[candidate->destination] 
				? candidate->origin 
				: candidate->destination;

			// Save the result
			resultBuffor[3 * resultIndex] = candidate->origin;
			resultBuffor[3 * resultIndex + 1] = candidate->destination;
			resultBuffor[3 * resultIndex + 2] = candidate->value;
			visitedVertices[currentVertexIndex] = true;
			pushReachableEdges();
			resultIndex++;
			i++;
		}
	}

	// Create result tree
	NeighborhoodList* result = new NeighborhoodList(vertexNumber - 1, vertexNumber, resultBuffor);
	delete[] resultBuffor;
	delete heap;

	return result;
}

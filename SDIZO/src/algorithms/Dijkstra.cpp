#include "..\..\include\algorithms\Dijkstra.hpp"

SDIZO::Path SDIZO::Dijkstra::findShortestPath(IncidentMatrix* incidentMatrix, size_t from, size_t to)
{
	Path result;
	MatrixCell** matrix = incidentMatrix->getMatrix();
	size_t vertexNumber = incidentMatrix->getVertexNumber();
	size_t edgesNumer = incidentMatrix->getEdgeNumber();
	size_t* values = incidentMatrix->getValues();

	bool* visitedVertices = new bool[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		visitedVertices[i] = false;
	}

	size_t* travelCosts = new size_t[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		travelCosts[i] = SIZE_MAX;
	}

	size_t* reachableFrom = new size_t[vertexNumber];
	size_t* reachableFor = new size_t[vertexNumber];

	travelCosts[from] = 0;
	size_t currentVertex = from;

	auto assignNewCurrentVertex = [&]()
	{
		visitedVertices[currentVertex] = true;
		size_t sortestPath = SIZE_MAX;
		for (size_t vertex = 0; vertex < vertexNumber; vertex++)
		{
			if (visitedVertices[vertex] == false && travelCosts[vertex] < sortestPath)
			{
				sortestPath = travelCosts[vertex];
				currentVertex = vertex;
			}
		}
	};

	while (visitedVertices[to] == false)
	{

		for (size_t edge = 0; edge < edgesNumer; edge++)
		{
			if (matrix[currentVertex][edge] == MatrixCell::Origin)
			{
				for (size_t vertex = 0; vertex < vertexNumber; vertex++)
				{
					if (matrix[vertex][edge] == MatrixCell::Destination)
					{
						if (travelCosts[currentVertex] + values[edge] < travelCosts[vertex])
						{
							travelCosts[vertex] = travelCosts[currentVertex] + values[edge];
							reachableFrom[vertex] = currentVertex;
							reachableFor[vertex] = values[edge];
						}

						break;
					}
				}
			}
		}

		assignNewCurrentVertex();
	}

	currentVertex = to;

	while (currentVertex != from)
	{
		result.addEdge(PathEdge(reachableFor[currentVertex], reachableFrom[currentVertex], currentVertex));
		currentVertex = reachableFrom[currentVertex];
	}

	return result;
}

SDIZO::Path SDIZO::Dijkstra::findShortestPath(NeighborhoodList* neighborhoodList, size_t from, size_t to)
{
	Path result;
	Edge** edges = neighborhoodList->getEdges();
	size_t vertexNumber = neighborhoodList->getVertexNumber();

	bool* visitedVertices = new bool[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		visitedVertices[i] = false;
	}

	size_t* travelCosts = new size_t[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		travelCosts[i] = SIZE_MAX;
	}

	size_t* reachableFrom = new size_t[vertexNumber];
	size_t* reachableFor = new size_t[vertexNumber];

	travelCosts[from] = 0;
	size_t currentVertex = from;

	auto assignNewCurrentVertex = [&]()
	{
		visitedVertices[currentVertex] = true;
		size_t sortestPath = SIZE_MAX;
		for (size_t vertex = 0; vertex < vertexNumber; vertex++)
		{
			if (visitedVertices[vertex] == false && travelCosts[vertex] < sortestPath)
			{
				sortestPath = travelCosts[vertex];
				currentVertex = vertex;
			}
		}
	};

	while (visitedVertices[to] == false)
	{
		Edge* edge = edges[currentVertex];
		while (edge != nullptr)
		{
			if (travelCosts[currentVertex] + edge->value < travelCosts[edge->destination])
			{
				travelCosts[edge->destination] = travelCosts[currentVertex] + edge->value;
				reachableFrom[edge->destination] = currentVertex;
				reachableFor[edge->destination] = edge->value;
			}

			edge = edge->next;
		}

		assignNewCurrentVertex();
	}

	currentVertex = to;

	while (currentVertex != from)
	{
		result.addEdge(PathEdge(reachableFor[currentVertex], reachableFrom[currentVertex], currentVertex));
		currentVertex = reachableFrom[currentVertex];
	}

	return result;
}

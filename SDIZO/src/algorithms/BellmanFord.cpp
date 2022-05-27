#include "..\..\include\algorithms\BellmanFord.hpp"

SDIZO::Path SDIZO::BellmanFord::findShortestPath(IncidentMatrix* incidentMatrix, size_t from, size_t to)
{
	Path result;
	MatrixCell** matrix = incidentMatrix->getMatrix();
	size_t vertexNumber = incidentMatrix->getVertexNumber();
	size_t edgesNumer = incidentMatrix->getEdgeNumber();
	size_t* values = incidentMatrix->getValues();

	size_t* travelCosts = new size_t[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		travelCosts[i] = SIZE_MAX;
	}

	size_t* reachableFrom = new size_t[vertexNumber];
	size_t* reachableFor = new size_t[vertexNumber];

	travelCosts[from] = 0;

	for (size_t i = 0; i < vertexNumber - 1; i++)
	{
		for (size_t origin = 0; origin < vertexNumber; origin++)
		{
			if (travelCosts[origin] == SIZE_MAX)
			{
				continue;
			}

			for (size_t edge = 0; edge < edgesNumer; edge++)
			{
				if (matrix[origin][edge] != MatrixCell::Origin)
				{
					continue;
				}

				for (size_t destination = 0; destination < edgesNumer; destination++)
				{
					if (matrix[destination][edge] != MatrixCell::Destination)
					{
						continue;
					}

					if (travelCosts[origin] + values[edge] < travelCosts[destination])
					{
						travelCosts[destination] = travelCosts[origin] + values[edge];
						reachableFrom[destination] = origin;
						reachableFor[destination] = values[edge];
					}

					break;
				}
			}
		}
	}

	size_t currentVertex = to;

	while (currentVertex != from)
	{
		result.addEdge(PathEdge(reachableFor[currentVertex], reachableFrom[currentVertex], currentVertex));
		currentVertex = reachableFrom[currentVertex];
	}

	return result;
}

SDIZO::Path SDIZO::BellmanFord::findShortestPath(NeighborhoodList* neighborhoodList, size_t from, size_t to)
{
	Path result;
	Edge** edges = neighborhoodList->getEdges();
	size_t vertexNumber = neighborhoodList->getVertexNumber();

	size_t* travelCosts = new size_t[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		travelCosts[i] = SIZE_MAX;
	}

	size_t* reachableFrom = new size_t[vertexNumber];
	size_t* reachableFor = new size_t[vertexNumber];

	travelCosts[from] = 0;
	
	Edge* edge = nullptr;
	for (size_t i = 0; i < vertexNumber - 1; i++)
	{
		for (size_t j = 0; j < vertexNumber; j++)
		{
			if (travelCosts[j] == SIZE_MAX)
			{
				continue;
			}

			Edge* edge = edges[j];
			while (edge != nullptr)
			{
				if (travelCosts[j] + edge->value < travelCosts[edge->destination])
				{
					travelCosts[edge->destination] = travelCosts[j] + edge->value;
					reachableFrom[edge->destination] = j;
					reachableFor[edge->destination] = edge->value;
				}

				edge = edge->next;
			}
		}
	}

	size_t currentVertex = to;

	while (currentVertex != from)
	{
		result.addEdge(PathEdge(reachableFor[currentVertex], reachableFrom[currentVertex], currentVertex));
		currentVertex = reachableFrom[currentVertex];
	}

	return result;
}

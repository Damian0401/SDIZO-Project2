#include "..\..\include\algorithms\Dijkstra.hpp"

SDIZO::Path SDIZO::Dijkstra::findShortestPath(IncidentMatrix* incidentMatrix, size_t from, size_t to)
{
	// Get necessary stuff from the graph 
	Path result;
	MatrixCell** matrix = incidentMatrix->getMatrix();
	size_t vertexNumber = incidentMatrix->getVertexNumber();
	size_t edgesNumer = incidentMatrix->getEdgeNumber();
	size_t* values = incidentMatrix->getValues();

	// Create array to store information, whether vertex was visited
	bool* visitedVertices = new bool[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		visitedVertices[i] = false;
	}

	// Generate starting travel costs
	size_t* travelCosts = new size_t[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		travelCosts[i] = SIZE_MAX;
	}

	// Create array to store previous vertex
	size_t* reachableFrom = new size_t[vertexNumber];
	// Create array to store single cost
	size_t* reachableFor = new size_t[vertexNumber];

	travelCosts[from] = 0;
	size_t currentVertex = from;
	size_t unvisitedVerticesNumber = vertexNumber;

	// Find new current vertex
	auto assignNewCurrentVertex = [&]()
	{
		visitedVertices[currentVertex] = true;
		unvisitedVerticesNumber--;
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

	// While exists unvisited vertices
	while (unvisitedVerticesNumber > 0)
	{
		// Iterate through all edges
		for (size_t edge = 0; edge < edgesNumer; edge++)
		{
			if (matrix[currentVertex][edge] != MatrixCell::Origin)
			{
				continue;
			}

			// Iterate through all vertices
			for (size_t vertex = 0; vertex < vertexNumber; vertex++)
			{
				if (matrix[vertex][edge] != MatrixCell::Destination)
				{
					continue;
				}

				// Check if current travel cost is lower than old one
				if (travelCosts[currentVertex] + values[edge] < travelCosts[vertex])
				{
					travelCosts[vertex] = travelCosts[currentVertex] + values[edge];
					reachableFrom[vertex] = currentVertex;
					reachableFor[vertex] = values[edge];
				}

				break;
			}
		}

		// Assing new current vetrex
		assignNewCurrentVertex();
	}

	currentVertex = to;

	// Create the shortest path 
	while (currentVertex != from)
	{
		result.addEdge(PathEdge(reachableFor[currentVertex], reachableFrom[currentVertex], currentVertex));
		currentVertex = reachableFrom[currentVertex];
	}

	return result;
}

SDIZO::Path SDIZO::Dijkstra::findShortestPath(NeighborhoodList* neighborhoodList, size_t from, size_t to)
{
	// Get necessary stuff from the graph 
	Path result;
	Edge** edges = neighborhoodList->getEdges();
	size_t vertexNumber = neighborhoodList->getVertexNumber();

	// Create array to store information, whether vertex was visited
	bool* visitedVertices = new bool[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		visitedVertices[i] = false;
	}

	// Generate starting travel costs
	size_t* travelCosts = new size_t[vertexNumber];
	for (size_t i = 0; i < vertexNumber; i++)
	{
		travelCosts[i] = SIZE_MAX;
	}

	// Create array to store previous vertex
	size_t* reachableFrom = new size_t[vertexNumber];
	// Create array to store single cost
	size_t* reachableFor = new size_t[vertexNumber];

	travelCosts[from] = 0;
	size_t currentVertex = from;
	size_t unvisitedVerticesNumber = vertexNumber;

	// Find new current vertex
	auto assignNewCurrentVertex = [&]()
	{
		visitedVertices[currentVertex] = true;
		unvisitedVerticesNumber--;
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

	// While exists unvisited vertices
	while (unvisitedVerticesNumber > 0)
	{
		Edge* edge = edges[currentVertex];
		while (edge != nullptr)
		{
			// Check if current travel cost is lower than old one
			if (travelCosts[currentVertex] + edge->value < travelCosts[edge->destination])
			{
				travelCosts[edge->destination] = travelCosts[currentVertex] + edge->value;
				reachableFrom[edge->destination] = currentVertex;
				reachableFor[edge->destination] = edge->value;
			}

			edge = edge->next;
		}

		// Assing new current vetrex
		assignNewCurrentVertex();
	}

	currentVertex = to;

	// Create the shortest path 
	while (currentVertex != from)
	{
		result.addEdge(PathEdge(reachableFor[currentVertex], reachableFrom[currentVertex], currentVertex));
		currentVertex = reachableFrom[currentVertex];
	}

	return result;
}

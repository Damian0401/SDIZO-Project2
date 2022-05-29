#include "..\..\include\utils\GraphGenerator.hpp"

SDIZO::RawGraphData SDIZO::GraphGenerator::generate(float density, size_t vertexNumber, size_t maxValue)
{
	size_t minumumEdgeNumber = vertexNumber;
	size_t edgeNumber = (density * vertexNumber * (vertexNumber - 1)) / 2;
	edgeNumber = edgeNumber > minumumEdgeNumber ? edgeNumber : minumumEdgeNumber;
	size_t dataSize = 3 * edgeNumber;
	size_t* data = new size_t[dataSize];

	std::random_device seed;
	std::mt19937 gen(seed());
	std::uniform_int_distribution<size_t> values(1, maxValue);
	std::uniform_int_distribution<size_t> vertices(0, vertexNumber - 1);

	bool** existConnection = new bool*[edgeNumber];
	for (size_t i = 0; i < edgeNumber; i++)
	{
		existConnection[i] = new bool[edgeNumber];
		for (size_t j = 0; j < edgeNumber; j++)
		{
			existConnection[i][j] = false;
		}
	}

	for (size_t i = 0; i < minumumEdgeNumber - 1; i++)
	{
		data[3 * i] = i;
		data[3 * i + 1] = i + 1;
		data[3 * i + 2] = values(gen);
		existConnection[i][i + 1] = true;
		existConnection[i + 1][i] = true;
	}

	data[3 * (minumumEdgeNumber - 1)] = minumumEdgeNumber - 1;
	data[3 * (minumumEdgeNumber - 1) + 1] = 0;
	data[3 * (minumumEdgeNumber - 1) + 2] = values(gen);
	existConnection[minumumEdgeNumber - 1][0] = true;
	existConnection[0][minumumEdgeNumber - 1] = true;

	size_t origin;
	size_t destination;
	for (size_t i = minumumEdgeNumber; i < edgeNumber; i++)
	{
		origin = vertices(gen);
		destination = vertices(gen);

		while (origin == destination || existConnection[origin][destination])
		{
			origin = vertices(gen);
			destination = vertices(gen);
		}

		data[3 * i] = origin;
		data[3 * i + 1] = destination;
		data[3 * i + 2] = values(gen);

		existConnection[origin][destination] = true;
		existConnection[destination][origin] = true;
	}

	for (size_t i = 0; i < edgeNumber; i++)
	{
		delete[] existConnection[i];
	}
	delete[] existConnection;

	RawGraphData result;
	result.data = data;
	result.vertexNumber = vertexNumber;
	result.edgeNumber = edgeNumber;

	return result;
}

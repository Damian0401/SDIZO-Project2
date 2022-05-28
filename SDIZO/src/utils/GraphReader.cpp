#include "..\..\include\utils\GraphReader.hpp"

SDIZO::GraphReader::GraphReader(std::string basePath)
	: basePath(basePath) {}

SDIZO::IncidentMatrix* SDIZO::GraphReader::readMatrixGraph(std::string fileName)
{
	size_t edgeNumber, vertexNumber;
	size_t* data;

	std::tie(edgeNumber, vertexNumber, data) = this->readData(fileName);

	if (data == nullptr)
	{
		return nullptr;
	}

	IncidentMatrix* matrix = new IncidentMatrix(edgeNumber, vertexNumber, data);

	delete[] data;

	return matrix;
}

SDIZO::NeighborhoodList* SDIZO::GraphReader::readListGraph(std::string fileName)
{
	size_t edgeNumber, vertexNumber;
	size_t* data;

	std::tie(edgeNumber, vertexNumber, data) = this->readData(fileName);

	if (data == nullptr)
	{
		return nullptr;
	}

	NeighborhoodList* list = new NeighborhoodList(edgeNumber, vertexNumber, data);

	delete[] data;

	return list;
}

std::tuple<size_t, size_t, size_t*> SDIZO::GraphReader::readData(std::string fileName)
{
	std::ifstream file(this->basePath + fileName);

	if (file.fail())
	{
		return std::make_tuple(-1, -1, nullptr);
	}

	size_t edgeNumber, vertexNumber;

	file >> edgeNumber >> vertexNumber;

	size_t dataSize = edgeNumber * 3;
	size_t* data = new size_t[dataSize];

	for (size_t i = 0; i < dataSize; i++)
	{
		file >> data[i];
	}

	return std::make_tuple(edgeNumber, vertexNumber, data);
}

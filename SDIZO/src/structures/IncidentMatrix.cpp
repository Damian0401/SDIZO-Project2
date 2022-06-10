#include "../../include/structures/IncidentMatrix.hpp"

SDIZO::IncidentMatrix::IncidentMatrix(size_t edgeNumber, size_t vertexNumber, size_t* data)
{
	// Set constants
	this->vertexNumber = vertexNumber;
	this->edgeNumber = edgeNumber;
	this->edgeValues = new size_t[edgeNumber];
	this->matrixHandler = new MatrixCell* [vertexNumber];

	// Iterate through all vertices
	for (size_t i = 0; i < vertexNumber; i++)
	{
		// Create new 1D array
		this->matrixHandler[i] = new MatrixCell[edgeNumber];

		// Fill array with None cells
		for (size_t j = 0; j < edgeNumber; j++)
		{
			this->matrixHandler[i][j] = MatrixCell::None;
		}
	}

	int dataIndex = 0;
	int valueIndex = 0;
	for (size_t i = 0; i < edgeNumber; i++)
	{
		// Read data from imput
		auto value = data[dataIndex];
		this->matrixHandler[data[dataIndex]][i] = MatrixCell::Origin;
		dataIndex++;
		this->matrixHandler[data[dataIndex]][i] = MatrixCell::Destination;
		dataIndex++;
		this->edgeValues[valueIndex] = data[dataIndex];
		dataIndex++;
		valueIndex++;
	}
}

SDIZO::IncidentMatrix::~IncidentMatrix()
{
	// Chech if graph is not empty
	if (matrixHandler != nullptr)
	{
		for (size_t i = 0; i < this->vertexNumber; i++)
		{
			delete[] this->matrixHandler[i];
		}
		delete[] this->matrixHandler;
	}
}

void SDIZO::IncidentMatrix::print(std::ostream& out)
{
	out << "    ";

	// Iterate through all edges
	for (size_t i = 0; i < this->edgeNumber; i++)
	{
		out << std::setw(2) << i << "   ";
	}

	out << std::endl;

	// Iterate through all vertices
	for (size_t i = 0; i < this->vertexNumber; i++)
	{
		// Display row
		out << std::setw(2) << i << "  ";
		for (size_t j = 0; j < this->edgeNumber; j++)
		{
			out << std::setw(2) << int(this->matrixHandler[i][j]) << " | ";
		}
		out << std::endl;
	}

	out  << " v  ";

	// Iterate through all edges
	for (size_t i = 0; i < this->edgeNumber; i++)
	{

		// Display values
		out << std::setw(2) << this->edgeValues[i] << " | ";
	}

	out << std::endl;
}

size_t SDIZO::IncidentMatrix::getVertexNumber()
{
	return this->vertexNumber;
}

size_t SDIZO::IncidentMatrix::getEdgeNumber()
{
	return this->edgeNumber;
}

SDIZO::MatrixCell** SDIZO::IncidentMatrix::getMatrix()
{
	return this->matrixHandler;
}

size_t* SDIZO::IncidentMatrix::getValues()
{
	return this->edgeValues;
}

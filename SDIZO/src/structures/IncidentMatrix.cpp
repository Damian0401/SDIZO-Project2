#include "../../include/structures/IncidentMatrix.hpp"

SDIZO::IncidentMatrix::IncidentMatrix(int edgeNumber, int vertexNumber, int* data)
{
	this->vertexNumber = vertexNumber;
	this->edgeNumber = edgeNumber;
	this->edgeValues = new int[edgeNumber];
	this->matrixHandler = new MatrixCell* [vertexNumber];

	for (size_t i = 0; i < vertexNumber; i++)
	{
		this->matrixHandler[i] = new MatrixCell[edgeNumber];

		for (size_t j = 0; j < edgeNumber; j++)
		{
			this->matrixHandler[i][j] = MatrixCell::None;
		}
	}

	int dataIndex = 0;
	int valueIndex = 0;
	for (size_t i = 0; i < edgeNumber; i++)
	{
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

	for (size_t i = 0; i < this->edgeNumber; i++)
	{
		out << i << "    ";
	}

	out << std::endl << std::endl;

	for (size_t i = 0; i < this->vertexNumber; i++)
	{
		out << i << "  ";
		for (size_t j = 0; j < this->edgeNumber; j++)
		{
			out << std::setw(2) << int(this->matrixHandler[i][j]) << " | ";
		}
		out << std::endl;
	}

	out << std::endl << "v  ";

	for (size_t i = 0; i < this->edgeNumber; i++)
	{
		out << std::setw(2) << this->edgeValues[i] << " | ";
	}

	out << std::endl;
}

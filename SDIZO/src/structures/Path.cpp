#include "..\..\include\structures\Path.hpp"

SDIZO::Path::Path() : edges(), totalCost(0) {}

SDIZO::Path::Path(const Path& path) : edges(path.edges), totalCost(path.totalCost) { }

void SDIZO::Path::addEdge(PathEdge edge)
{
	this->totalCost += edge.value;
	this->edges.addFront(edge);
}

void SDIZO::Path::print(std::ostream& out)
{
	this->edges.print(out);
	out << "Total cost: " << this->totalCost << std::endl;
}

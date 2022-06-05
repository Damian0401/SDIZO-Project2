#include "..\..\include\utils\Tests.hpp"

SDIZO::Tests::Tests(const std::string& basePath, const TimerPrecision& precision, size_t repeats)
	: basePath(basePath), precision(precision), repeats(repeats) {}

void SDIZO::Tests::run(Array<size_t>& vertices)
{
	float densities[] = { 0.25, 0.50, 0.75, 0.99 };

	std::ofstream primMatrixResult(this->basePath + "prim-matrix-results.csv");
	std::ofstream primListResult(this->basePath + "prim-list-results.csv");
	std::ofstream kruskalMatrixResult(this->basePath + "kruskal-matrix-results.csv");
	std::ofstream kruskalListResult(this->basePath + "kruskal-list-results.csv");
	std::ofstream dijkstraMatrixResult(this->basePath + "dijkstra-matrix-results.csv");
	std::ofstream dijkstraListResult(this->basePath + "dijkstra-list-results.csv");
	std::ofstream bellmanFordMatrixResult(this->basePath + "bellman-ford-matrix-results.csv");
	std::ofstream bellmanFordListResult(this->basePath + "bellman-ford-list-results.csv");

	std::string format = "vertices;density;time";

	primMatrixResult << format << std::endl;
	primListResult << format << std::endl;
	kruskalMatrixResult << format << std::endl;
	kruskalListResult << format << std::endl;
	dijkstraMatrixResult << format << std::endl;
	dijkstraListResult << format << std::endl;
	bellmanFordMatrixResult << format << std::endl;
	bellmanFordListResult << format << std::endl;

	size_t vertexCount = vertices.getSize();
	for (auto& density : densities)
	{
		for (size_t i = 0; i < vertexCount; i++)
		{
			size_t vertexNumber = vertices.getAt(i);
			
			auto primMatrixTime = this->getAverargeTime(Algorithm::Prim, 
				GraphRepresentation::Matrix, density, vertexNumber);
			primMatrixResult << vertexNumber << ';' << 100 * density << ';' << primMatrixTime << std::endl;

			auto primListTime = this->getAverargeTime(Algorithm::Prim, 
				GraphRepresentation::List, density, vertexNumber);
			primListResult << vertexNumber << ';' << 100 * density << ';' << primListTime << std::endl;

			auto kruskalMatrixTime = this->getAverargeTime(Algorithm::Kruskal, 
				GraphRepresentation::Matrix, density, vertexNumber);
			kruskalMatrixResult << vertexNumber << ';' << 100 * density << ';' << kruskalMatrixTime << std::endl;

			auto kruskalListTime = this->getAverargeTime(Algorithm::Kruskal, 
				GraphRepresentation::List, density, vertexNumber);
			kruskalListResult << vertexNumber << ';' << 100 * density << ';' << kruskalListTime << std::endl;

			auto dijkstraMatrixTime = this->getAverargeTime(Algorithm::Dijkstra, 
				GraphRepresentation::Matrix, density, vertexNumber);
			dijkstraMatrixResult << vertexNumber << ';' << 100 * density << ';' << dijkstraMatrixTime << std::endl;

			auto dijkstraListTime = this->getAverargeTime(Algorithm::Dijkstra, 
				GraphRepresentation::List, density, vertexNumber);
			dijkstraListResult << vertexNumber << ';' << 100 * density << ';' << dijkstraListTime << std::endl;

			auto bellmanFordMatrixTime = this->getAverargeTime(Algorithm::BellmanFord, 
				GraphRepresentation::Matrix, density, vertexNumber);
			bellmanFordMatrixResult << vertexNumber << ';' << 100 * density << ';' << bellmanFordMatrixTime << std::endl;

			auto bellmanFordListTime = this->getAverargeTime(Algorithm::BellmanFord, 
				GraphRepresentation::List, density, vertexNumber);
			bellmanFordListResult << vertexNumber << ';' << 100 * density << ';' << bellmanFordListTime << std::endl;

			std::cout << "vertices: " << vertexNumber
				<< " density: " << density << " done." << std::endl;
		}
	}

	primMatrixResult.close();
	primListResult.close();
	kruskalMatrixResult.close();
	kruskalListResult.close();
	dijkstraMatrixResult.close();
	dijkstraListResult.close();
	bellmanFordMatrixResult.close();
	bellmanFordListResult.close();
}

long long SDIZO::Tests::getAverargeTime(Algorithm algorithm, GraphRepresentation graph, size_t density, size_t vertexNumber)
{
	long long time = 0;

	if (graph == GraphRepresentation::Matrix)
	{
		IncidentMatrix* result = nullptr;

		auto tryDeleteResult = [&]()
		{
			if (result == nullptr)
			{
				return;
			}

			delete result;
			result = nullptr;
		};

		for (size_t i = 0; i < this->repeats; i++)
		{
			RawGraphData rawData = this->generator.generate(density, vertexNumber);
			IncidentMatrix* matrix = new IncidentMatrix(rawData.edgeNumber, rawData.vertexNumber, rawData.data);

			this->timer.start();
			switch (algorithm)
			{
			case Algorithm::Prim:
				result = Prim::generateMst(matrix);
				break;
			case Algorithm::Kruskal:
				result = Kruskal::generateMst(matrix);
				break;
			case Algorithm::Dijkstra:
				Dijkstra::findShortestPath(matrix, 0, vertexNumber - 1);
				break;
			case Algorithm::BellmanFord:
				BellmanFord::findShortestPath(matrix, 0, vertexNumber - 1);
				break;
			}
			this->timer.stop();
			time = time + this->timer.getTime(this->precision);

			delete rawData.data;
			delete matrix;
			tryDeleteResult();
		}
	}

	if (graph == GraphRepresentation::List)
	{
		NeighborhoodList* result = nullptr;

		auto tryDeleteResult = [&]()
		{
			if (result == nullptr)
			{
				return;
			}

			delete result;
			result = nullptr;
		};

		for (size_t i = 0; i < this->repeats; i++)
		{
			RawGraphData rawData = this->generator.generate(density, vertexNumber);
			NeighborhoodList* list = new NeighborhoodList(rawData.edgeNumber, rawData.vertexNumber, rawData.data);

			this->timer.start();
			switch (algorithm)
			{
			case Algorithm::Prim:
				result = Prim::generateMst(list);
				break;
			case Algorithm::Kruskal:
				result = Kruskal::generateMst(list);
				break;
			case Algorithm::Dijkstra:
				Dijkstra::findShortestPath(list, 0, vertexNumber - 1);
				break;
			case Algorithm::BellmanFord:
				BellmanFord::findShortestPath(list, 0, vertexNumber - 1);
				break;
			}
			this->timer.stop();
			time = time + this->timer.getTime(this->precision);

			delete rawData.data;
			delete list;
			tryDeleteResult();
		}
	}

	return time / this->repeats;
}
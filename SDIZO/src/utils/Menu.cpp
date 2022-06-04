#include "..\..\include\utils\Menu.hpp"

SDIZO::Menu::Menu(const std::string& basePath)
	: reader(basePath + "data/"), tests(basePath + "results/", TimerPrecision::Nanoseconds, 20) { }

void SDIZO::Menu::run()
{
	bool isRunning = true;

	while (isRunning)
	{
		std::cout << "Select submenu:" << std::endl;
		std::cout << "1 <- Minimum spanning tree" << std::endl;
		std::cout << "2 <- The shortest path" << std::endl;
		std::cout << "3 <- Automatic tests" << std::endl;
		std::cout << "4 <- exit" << std::endl;

		size_t selectedOption;
		std::cin >> selectedOption;

		switch (selectedOption)
		{
		case 1:
			this->minimumSpanningTreeSubmenu();
			break;
		case 2:
			this->shortestPathSubmenu();
			break;
		case 3:
			this->runTests();
			break;
		default:
			isRunning = false;
			break;
		}
	}
}

void SDIZO::Menu::minimumSpanningTreeSubmenu()
{
	IncidentMatrix* matrix = nullptr;
	NeighborhoodList* list = nullptr;

	bool isRunning = true;

	while (isRunning)
	{
		size_t selectedOption = this->printSubmenuOptions("Prim's", "Kruskal's");

		switch (selectedOption)
		{
		case 1:
			this->readGraphFromFile(&matrix, &list);
			break;
		case 2:
			this->generateRandomGraph(&matrix, &list);
			break;
		case 3:
			this->tryPrintGraph(matrix, list);
			break;
		case 4:
			this->runPrimAlgorithm(matrix, list);
			break;
		case 5:
			this->runKruskalAlgorithm(matrix, list);
			break;
		case 6:
			tryDeleteGraph(matrix, list);
			isRunning = false;
			break;
		default:
			std::cout << "Invalid input" << std::endl;
			break;
		}
	}
}

void SDIZO::Menu::shortestPathSubmenu()
{
	IncidentMatrix* matrix = nullptr;
	NeighborhoodList* list = nullptr;

	bool isRunning = true;

	while (isRunning)
	{
		size_t selectedOption = this->printSubmenuOptions("Dijkstra's", "Bellman-Ford's");

		switch (selectedOption)
		{
		case 1:
			this->readGraphFromFile(&matrix, &list);
			break;
		case 2:
			this->generateRandomGraph(&matrix, &list);
			break;
		case 3:
			this->tryPrintGraph(matrix, list);
			break;
		case 4:
			this->runDijkstraAlgorithm(matrix, list);
			break;
		case 5:
			this->runBellmanFordAlgorithm(matrix, list);
			break;
		default:
			tryDeleteGraph(matrix, list);
			isRunning = false;
			break;
		}
	}
}

void SDIZO::Menu::readGraphFromFile(IncidentMatrix** matrix, NeighborhoodList** list)
{
	this->tryDeleteGraph(*matrix, *list);

	std::cout << "Enter filename: ";
	std::string fileName;
	std::cin >> fileName;

	(*matrix) = this->reader.readMatrixGraph(fileName);
	(*list) = this->reader.readListGraph(fileName);
}

void SDIZO::Menu::generateRandomGraph(IncidentMatrix** matrix, NeighborhoodList** list)
{
	this->tryDeleteGraph(*matrix, *list);

	std::cout << "Enter number of vertices: ";
	size_t vertexNumber;
	std::cin >> vertexNumber;

	std::cout << "Enter density: ";
	float density;
	std::cin >> density;

	if (density > 1)
	{
		density = 1;
	}

	std::cout << "Enter max value: ";
	size_t maxValue;
	std::cin >> maxValue;

	auto rawData = this->generator.generate(density, vertexNumber, maxValue);

	(*matrix) = new IncidentMatrix(rawData.edgeNumber, rawData.vertexNumber, rawData.data);
	(*list) = new NeighborhoodList(rawData.edgeNumber, rawData.vertexNumber, rawData.data);

	delete rawData.data;
}

size_t SDIZO::Menu::printSubmenuOptions(std::string firstAlgorithm, std::string secondAlgorithm)
{
	std::cout << std::string(50, '#') << std::endl;
	std::cout << "1 <- Read graph from file" << std::endl;
	std::cout << "2 <- Generate random graph" << std::endl;
	std::cout << "3 <- Print graph" << std::endl;
	std::cout << "4 <- " << firstAlgorithm << " algorithm" << std::endl;
	std::cout << "5 <- " << secondAlgorithm << " algorithm" << std::endl;
	std::cout << "6 <- exit" << std::endl;

	size_t selectedOption;
	std::cin >> selectedOption;
	return selectedOption;
}

void SDIZO::Menu::tryPrintGraph(IncidentMatrix* matrix, NeighborhoodList* list)
{
	if (matrix == nullptr || list == nullptr)
	{
		std::cout << "Graph is empty." << std::endl;
		return;
	}

	std::cout << "Matrix:" << std::endl;
	matrix->print(std::cout);

	std::cout << std::endl;

	std::cout << "List:" << std::endl;
	list->print(std::cout);
}

void SDIZO::Menu::runPrimAlgorithm(IncidentMatrix* matrix, NeighborhoodList* list)
{
	std::cout << "Matrix:" << std::endl;
	auto matrixMst = Prim::generateMst(matrix);
	matrixMst->print(std::cout);
	delete matrixMst;
	
	std::cout << "List:" << std::endl;
	auto listMst = Prim::generateMst(list);
	listMst->print(std::cout);
	delete listMst;
}

void SDIZO::Menu::runKruskalAlgorithm(IncidentMatrix* matrix, NeighborhoodList* list)
{
	std::cout << "Matrix:" << std::endl;
	auto matrixMst = Kruskal::generateMst(matrix);
	matrixMst->print(std::cout);
	delete matrixMst;

	std::cout << "List:" << std::endl;
	auto listMst = Kruskal::generateMst(list);
	listMst->print(std::cout);
	delete listMst;
}

void SDIZO::Menu::runDijkstraAlgorithm(IncidentMatrix* matrix, NeighborhoodList* list)
{
	std::cout << "Enter start vertex: ";
	size_t startVertex;
	std::cin >> startVertex;

	std::cout << "Enter end vertex: ";
	size_t endVertex;
	std::cin >> endVertex;

	std::cout << "Matrix:" << std::endl;
	auto matrixPath = Dijkstra::findShortestPath(matrix, startVertex, endVertex);
	matrixPath.print(std::cout);

	std::cout << "List:" << std::endl;
	auto listPath = Dijkstra::findShortestPath(list, startVertex, endVertex);
	listPath.print(std::cout);
}

void SDIZO::Menu::runBellmanFordAlgorithm(IncidentMatrix* matrix, NeighborhoodList* list)
{
	std::cout << "Enter start vertex: ";
	size_t startVertex;
	std::cin >> startVertex;

	std::cout << "Enter end vertex: ";
	size_t endVertex;
	std::cin >> endVertex;

	std::cout << "Matrix:" << std::endl;
	auto matrixPath = BellmanFord::findShortestPath(matrix, startVertex, endVertex);
	matrixPath.print(std::cout);

	std::cout << "List:" << std::endl;
	auto listPath = BellmanFord::findShortestPath(list, startVertex, endVertex);
	listPath.print(std::cout);
}

void SDIZO::Menu::tryDeleteGraph(IncidentMatrix* matrix, NeighborhoodList* list)
{
	if (matrix != nullptr)
	{
		delete matrix;
	}

	if (list != nullptr)
	{
		delete list;
	}
}

void SDIZO::Menu::runTests()
{
	Array<size_t> vertices;

	std::cout << "Enter 10 numbers" << std::endl;

	size_t number;
	for (size_t i = 0; i < 10; i++)
	{
		std::cin >> number;
		vertices.addBack(number);
	}

	this->tests.run(vertices);
}

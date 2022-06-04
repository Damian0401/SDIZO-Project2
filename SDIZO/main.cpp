#include <iostream>
#include <random>
#include "include/SDIZO.hpp"

int main()
{
	using namespace SDIZO;

	std::string basePath = "C:/Users/szkol/Desktop/SDIZO/projekt/SDIZO-Project2/SDIZO/";

	Menu menu(basePath);

	menu.run();
}

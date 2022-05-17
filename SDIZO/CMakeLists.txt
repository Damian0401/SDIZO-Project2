# CMakeList.txt : CMake project for SDIZO, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SDIZO")

# Add source to this project's executable.
add_executable (SDIZO "main.cpp"  "include/structures/IncidentMatrix.hpp" "include/utils/Enums.hpp"  "src/structures/IncidentMatrix.cpp" "src/structures/NeighborhoodList.cpp" "include/structures/NeighborhoodList.hpp" "include/structures/Edge.hpp" "include/SDIZO.hpp" "include/structures/EdgeHeap.hpp" "src/structures/EdgeHeap.cpp" "include/algorithms/Prim.hpp"   "src/algorithms/Prim.cpp"    "include/algorithms/Kruskal.hpp" "src/algorithms/Kruskal.cpp" )

# TODO: Add tests and install targets if needed.

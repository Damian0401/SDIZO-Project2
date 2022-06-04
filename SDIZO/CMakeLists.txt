# CMakeList.txt : CMake project for SDIZO, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SDIZO")

# Add source to this project's executable.
add_executable (SDIZO "main.cpp"  "include/structures/IncidentMatrix.hpp" "include/utils/Enums.hpp"  "src/structures/IncidentMatrix.cpp" "src/structures/NeighborhoodList.cpp" "include/structures/NeighborhoodList.hpp" "include/structures/Edge.hpp" "include/SDIZO.hpp" "include/structures/EdgeHeap.hpp" "src/structures/EdgeHeap.cpp" "include/algorithms/Prim.hpp"   "src/algorithms/Prim.cpp"    "include/algorithms/Kruskal.hpp" "src/algorithms/Kruskal.cpp"  "include/algorithms/Dijkstra.hpp" "src/algorithms/Dijkstra.cpp" "include/structures/Array.hpp" "src/structures/Array.cpp"  "include/structures/Path.hpp" "src/structures/Path.cpp" "include/structures/PathEdge.hpp" "include/algorithms/BellmanFord.hpp" "src/algorithms/BellmanFord.cpp"  "include/utils/GraphReader.hpp" "src/utils/GraphReader.cpp"  "include/utils/GraphGenerator.hpp" "src/utils/GraphGenerator.cpp" "include/structures/RawGraphData.hpp" "include/utils/Menu.hpp" "src/utils/Menu.cpp" "include/utils/Timer.hpp" "src/utils/Timer.cpp" "include/utils/Tests.hpp" "src/utils/Tests.cpp")

# TODO: Add tests and install targets if needed.

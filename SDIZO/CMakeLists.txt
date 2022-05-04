# CMakeList.txt : CMake project for SDIZO, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SDIZO")

# Add source to this project's executable.
add_executable (SDIZO "main.cpp"  "include/structures/IncidentMatrix.hpp" "include/utils/Enums.hpp"  "src/structures/IncidentMatrix.cpp")

# TODO: Add tests and install targets if needed.

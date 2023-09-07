cmake_minimum_required(VERSION 3.14)

project(architecture_utilities)

file(GLOB ARCHITECTURE_UTILITIES_SRC "*.c" "*.cpp")

add_library(ArchitectureUtilities ${ARCHITECTURE_UTILITIES_SRC})
target_link_libraries (ArchitectureUtilities Eigen3::Eigen)

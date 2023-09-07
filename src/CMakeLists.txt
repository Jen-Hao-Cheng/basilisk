cmake_minimum_required(VERSION 3.14)

project(basilisk)

# pthread
find_package(Threads REQUIRED)
# Dependency: Eigen 3
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(
    "./"
)

add_subdirectory("./architecture/")

add_subdirectory("./c_code_example/")
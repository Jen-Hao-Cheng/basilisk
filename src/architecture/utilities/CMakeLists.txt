cmake_minimum_required(VERSION 3.14)

project(architecture_utilities)

file(GLOB ARCHITECTURE_UTILITIES_SRC "*.c" "*.cpp")
file(GLOB MODULE_ID_GENERATOR_SRC "moduleIdGenerator/*.cpp")

add_library(ModuleIDGenerator SHARED ${MODULE_ID_GENERATOR_SRC})

add_library(ArchitectureUtilities ${ARCHITECTURE_UTILITIES_SRC})
target_link_libraries (ArchitectureUtilities 
    ModuleIDGenerator
    Eigen3::Eigen
)

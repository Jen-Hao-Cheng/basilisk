cmake_minimum_required(VERSION 3.14)

project(basilisk_architecture)

add_subdirectory("./utilities")

file(GLOB ARCHITECTURE_SRC
    "./_GeneralModuleFiles/*.cpp"
    "./alg_contain/*.cpp"
    "./system_model/*.cpp"
)

add_library(ARCHITECTURE
    ${ARCHITECTURE_SRC}
)
target_link_libraries(ARCHITECTURE 
    ArchitectureUtilities
    Threads::Threads
)
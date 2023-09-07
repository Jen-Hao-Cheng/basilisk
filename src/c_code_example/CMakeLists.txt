cmake_minimum_required(VERSION 3.14)

project(c_code_example)

include_directories(
    "./include/"
)

# bsk-1
add_executable(main_bsk_1 main_bsk_1.cpp
)
target_link_libraries(main_bsk_1 ARCHITECTURE)

# bsk-2
add_executable(main_bsk_2 main_bsk_2.cpp
    ./source/cppModuleTemplate.cpp
)
target_link_libraries(main_bsk_2 ARCHITECTURE)

# bsk-2a
add_executable(main_bsk_2a main_bsk_2a.cpp
    ./source/cppModuleTemplate.cpp
)
target_link_libraries(main_bsk_2a ARCHITECTURE)

# bsk-3
add_executable(main_bsk_3 main_bsk_3.cpp
    ./source/cppModuleTemplate.cpp
)
target_link_libraries(main_bsk_3 ARCHITECTURE)

# bsk-4
add_executable(main_bsk_4 main_bsk_4.cpp
    ./source/cppModuleTemplate.cpp
)
target_link_libraries(main_bsk_4 ARCHITECTURE)
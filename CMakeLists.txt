cmake_minimum_required(VERSION 3.8)
project(stud)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory(lib)

file(GLOB STUD_SRC 
    # src
    "src/*.cpp"
    "src/io/*.cpp"
    "src/bStream/*.cpp"
    
    # include
    "include/*.hpp"
    "include/*.h"
    "include/io/*.h"
    "include/bStream/*.h"
)

add_executable(stud ${STUD_SRC})
#find_package(ICU 61.0 COMPONENTS uc i18n REQUIRED)
target_include_directories(stud PUBLIC include)
#target_link_libraries( stud PUBLIC imgui glfw gctools libbti libflipper ICU::uc ICU::i18n)
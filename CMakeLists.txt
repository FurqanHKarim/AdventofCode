cmake_minimum_required(VERSION 3.5.0)
project(AOC_24)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/app/main.cpp)

set (CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)

foreach(file ${sources})

    cmake_path(GET file STEM target_name)
    add_executable(${PROJECT_NAME}_${target_name} ${file})

endforeach()


# include(CTest)
# enable_testing()


cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME "AngleBasedDataSetGenerator")

project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/Bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/Bin)

find_package(Gorgon REQUIRED)

add_compile_options(-std=c++14)

add_executable(${PROJECT_NAME}
    Source/Types.h
    Source/Main.cpp
    Source/Generator.h
    Source/Generator.cpp
)

linkgorgon(${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resource/Data.gor ${CMAKE_CURRENT_SOURCE_DIR}/Bin/Data.gor COPYONLY)

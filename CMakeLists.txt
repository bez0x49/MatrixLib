cmake_minimum_required(VERSION 3.17.0)

project(MatrixDoubleLib 
    VERSION 0.1.0
    LANGUAGES CXX
)

file(GLOB SOURCES "*.cpp")

set(SOURCES ${SOURCES})

add_library(${PROJECT_NAME} STATIC ${SOURCES})
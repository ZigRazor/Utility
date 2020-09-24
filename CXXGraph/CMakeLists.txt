cmake_minimum_required(VERSION 3.7)

# set the project name and version
project(CXXGraph VERSION 1.0)

configure_file(CXXGraphConfig.h.in CXXGraphConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the library
add_library(CXXGraph SHARED  BaseStructure/Graph/Graph.cpp BaseStructure/Node/Node.cpp BaseStructure/Link/Link.cpp)
add_library(CXXGraphStatic STATIC BaseStructure/Graph/Graph.cpp BaseStructure/Node/Node.cpp BaseStructure/Link/Link.cpp)
set_target_properties(CXXGraphStatic PROPERTIES OUTPUT_NAME CXXGraph)

target_include_directories(CXXGraph PUBLIC
                           "${PROJECT_SOURCE_DIR}"
                           )
target_include_directories(CXXGraphStatic PUBLIC
                           "${PROJECT_SOURCE_DIR}"
                           )



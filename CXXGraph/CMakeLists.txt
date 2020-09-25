cmake_minimum_required(VERSION 3.7)

# set the project name and version
project(CXXGraph VERSION 0.0.1)

configure_file(CXXGraphConfig.h.in CXXGraphConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if( (IS_DIRECTORY ${GOOGLETESTLIBPATH}) AND (IS_DIRECTORY ${GOOGLETESTINCPATH}))
    
    add_executable(test_exe Test/main.cpp)
    target_include_directories(test_exe PUBLIC
                           "${PROJECT_SOURCE_DIR}"
                           "${GOOGLETESTINCPATH}"
                           )
    target_link_libraries(test_exe 
                            CXXGraph 
                            ${GOOGLETESTLIBPATH}/libgtest.a 
                            ${GOOGLETESTLIBPATH}/libgtest_main.a 
                            pthread )
else ()
    message("If you want enable the test suite you have to specify the option -DGOOGLETESTLIBPATH=[path to the lib folder of google test]
and option -DGOOGLETESTINCPATH=[path to the include folder of google test]")
endif((IS_DIRECTORY ${GOOGLETESTLIBPATH}) AND (IS_DIRECTORY ${GOOGLETESTINCPATH}))

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


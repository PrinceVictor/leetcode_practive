cmake_minimum_required(VERSION 2.8)

project(data_structure)
set(CMAKE_BUILD_TYPE Relese)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
add_definitions("-Wall")

MESSAGE(STATUS "This is BINARY dir " ${data_structure_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${data_structure_SOURCE_DIR})


#FIND_PACKAGE(Boost REQUIRED COMPONENTS
#        chrono
#        filesystem
#        thread
#        system
#        serialization)
#INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

OPTION(USE_DEBUG off)
if(USE_DEBUG)
    message(STATUS "USE DEBUG")
    add_definitions("-DUSE_DEBUG")
else()
    message(STATUS "NO DEBUG")
endif(USE_DEBUG)

set(INC_PATH inc)
INCLUDE_DIRECTORIES(${INC_PATH})

AUX_SOURCE_DIRECTORY(src/ code_SRC)

#SET(code_LIBS ${Boost_LIBRARIES})

add_executable(run_code ${code_SRC})
#target_link_libraries(run_code ${code_LIBS})

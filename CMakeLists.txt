cmake_minimum_required(VERSION 3.8)

set(This Bauern)
set(Lib BauernLib)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
  Tree.hpp
  Node.hpp
  Utils.hpp
  Constants.hpp
)

set(Sources
  bauern.cpp
  Node.cpp
  Tree.cpp
  Utils.cpp
)
add_executable(${This} ${Sources} ${Headers})
add_library(${Lib} STATIC ${Sources} ${Headers})
add_subdirectory(test)


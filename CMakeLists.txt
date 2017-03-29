cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 11)


project(anpi-pol)
add_executable(anpi-pol main.cpp src/muller.h src/divide-pol.h src/formulaformat.h)


#Include Boost
find_package( Boost REQUIRED COMPONENTS )

include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(anpi-pol ${Boost_LIBRARIES})

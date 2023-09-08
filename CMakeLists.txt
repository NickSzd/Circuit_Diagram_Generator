cmake_minimum_required(VERSION 3.12)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

cmake_policy(SET CMP0048 NEW)

project(circuit_Diagram_Generator VERSION 1.0
	DESCRIPTION "Build a Circuit Diagram given a boolean expression"
	LANGUAGES C)


add_executable(circuit_Diagram_Generator src/main.c src/stack.c src/stack.h src/token.h src/token.c src/tree.c src/tree.h)
target_include_directories(circuit_Diagram_Generator PRIVATE include)
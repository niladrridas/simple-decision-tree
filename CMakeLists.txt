cmake_minimum_required(VERSION 3.10)

project(DecisionTreeCPP)

set(CMAKE_CXX_STANDARD 11)

add_executable(DecisionTreeCPP src/main.cpp src/decision_tree.cpp src/decision_tree.h)

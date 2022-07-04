cmake_minimum_required(VERSION 3.18)

set(PROJECT_NAME "project1")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")
set(JAVA_HOME "/usr/lib/jvm/java-17-openjdk-amd64/")

project(${PROJECT_NAME})
include_directories("include" ${JAVA_HOME}/include ${JAVA_HOME}/include/linux)
add_subdirectory(src)

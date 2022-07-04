cmake_minimum_required(VERSION 3.18)

set(PROJECT_NAME "test")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -O3")
project(${PROJECT_NAME})

file(GLOB SOURCE_FILE "*.h" "*.cpp")

add_library(native-lib SHARED ${SOURCE_FILE})
add_executable(${PROJECT_NAME} ${SOURCE_FILE})
install(TARGETS ${PROJECT_NAME} DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC "-static")

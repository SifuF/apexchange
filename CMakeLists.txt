cmake_minimum_required(VERSION 3.28)

project(apexchange VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADERS
    src/order_book.hpp
)

set(SOURCES
    src/main.cpp
    src/order_book.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${HEADERS} ${SOURCES} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
)

cmake_minimum_required(VERSION 3.0)
project(crypto_cpp)

set(CMAKE_CXX_STANDARD 17)

add_library(crypto_cpp library.cpp library.h)

enable_testing()
add_executable(tests tests.cpp)
target_link_libraries(tests crypto_cpp)

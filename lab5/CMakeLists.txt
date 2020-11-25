cmake_minimum_required(VERSION 3.6)

project(sorted_array)

set(SOURCE_FILES
  sorted_array.h
  catch.hpp
  sorted_array_test.cc
  test_main.cc
  )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(sorted_array ${SOURCE_FILES})

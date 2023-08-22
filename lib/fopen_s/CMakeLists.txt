cmake_minimum_required (VERSION 3.16)

project("fopen_s")

add_library("fopen_s" STATIC "fopen_s.cpp")

target_include_directories("fopen_s" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" 
                                     PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/fopen_s")
cmake_minimum_required (VERSION 3.16)

project("snprintf")

add_library("snprintf" STATIC "snprintf.cpp")

target_include_directories("snprintf" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" 
                                      PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/snprintf")
cmake_minimum_required (VERSION 3.16)

project("strlcpy")

add_library("strlcpy" STATIC "strlcpy.cpp")

target_include_directories("strlcpy" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" 
                                     PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/strlcpy")
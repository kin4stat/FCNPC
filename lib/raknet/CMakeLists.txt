cmake_minimum_required (VERSION 3.16)

project("raknet")

add_library("raknet" STATIC "BitStream.cpp")

target_include_directories("raknet" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" 
                                    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/raknet")
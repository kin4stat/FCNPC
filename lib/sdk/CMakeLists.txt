cmake_minimum_required (VERSION 3.16)

project("amx")

add_library("amx" STATIC "amxplugin.cpp")

target_include_directories("amx" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}/include/amx"
                                 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/sdk")

if (WIN32)
  target_compile_definitions("amx" PUBLIC -DWIN32 -D_WIN32 -D__STDC__)
else()
  target_compile_definitions("amx" PUBLIC -DLINUX)
endif()
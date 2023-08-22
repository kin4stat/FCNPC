cmake_minimum_required (VERSION 3.16)

add_subdirectory("strlcpy")
add_subdirectory("raknet")
add_subdirectory("sdk")

if (WIN32)
  add_subdirectory("snprintf")
else()
  add_subdirectory("fopen_s")
endif()

set (SUBHOOK_STATIC true)
set (SUBHOOK_TESTS false)
add_subdirectory("subhook")

set (BUILD_CPU_DEMOS OFF CACHE BOOL "Build original Bullet CPU examples")
set (BUILD_BULLET2_DEMOS OFF CACHE BOOL "Set when you want to build the Bullet 2 demos")
set (BUILD_EXTRAS OFF CACHE BOOL "Set when you want to build the extras")
set (BUILD_OPENGL3_DEMOS OFF CACHE BOOL "Set when you want to build the OpenGL3+ demos")
set (BUILD_UNIT_TESTS OFF CACHE BOOL "Build Unit Tests")

add_subdirectory("bullet3")

set (BULLET_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/bullet3")
find_path(BULLET_INCLUDE_DIRS NAMES btBulletCollisionCommon.h
  HINTS
    ${BULLET_ROOT}/include
    ${BULLET_ROOT}/src
  PATH_SUFFIXES bullet
)

set(BULLET_INCLUDE_DIRS "${BULLET_INCLUDE_DIRS}" PARENT_SCOPE)
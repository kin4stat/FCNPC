cmake_minimum_required (VERSION 3.16)

project(FCNPC)

option(BUILD_FOR_DL "Builds FCNPC for samp03dl version" OFF)

# Definintions
set(INCLUDE_VERSION 202)
set(PLUGIN_VERSION "2.0.5")
add_definitions(-DPLUGIN_VERSION="${PLUGIN_VERSION}" -DINCLUDE_VERSION=${INCLUDE_VERSION})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

set(TARGET_NAME "FCNPC$<$<BOOL:${BUILD_FOR_DL}>:-DL>")

set(EXPORTS_DEF_FILE "${CMAKE_CURRENT_BINARY_DIR}/Exports.def")

set(LIBRARY_GROUP "lib\\")

if (${BUILD_FOR_DL})
	set(TARGET_NAME "FCNPC-DL")
else()
	set(TARGET_NAME "FCNPC")
endif()

if (NOT WIN32)
	add_compile_options(-fPIC -fno-stack-protector -Wno-unused-but-set-variable)
	add_link_options(-fshort-wchar -shared -static-libgcc -static-libstdc++)
endif()


add_subdirectory("lib")

file (GLOB FCNPC_SRC
	${FCNPC_SRC}
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
)
source_group("" FILES ${FCNPC_SRC})

# MapAndreas
file (GLOB MAPANDREAS_SRC
	${CMAKE_CURRENT_SOURCE_DIR}/src/vendor/MapAndreas/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/vendor/MapAndreas/*.h
)
source_group("${VENDOR_GROUP}MapAndreas" FILES ${MAPANDREAS_SRC})

# ColAndreas
set (CA_VERSION "v1.4.0")
set (CA_DATABASE_VERSION 2)
add_definitions (-DCA_VERSION="${CA_VERSION}" -DCA_DATABASE_VERSION=${CA_DATABASE_VERSION})
file (GLOB COLANDREAS_SRC
	${CMAKE_CURRENT_SOURCE_DIR}/src/vendor/ColAndreas/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/vendor/ColAndreas/*.h
)
source_group("${VENDOR_GROUP}ColAndreas" FILES ${COLANDREAS_SRC})

# Include file
configure_file(src/FCNPC.inc.in ${CMAKE_CURRENT_SOURCE_DIR}/sampsvr_files/FCNPC.inc NEWLINE_STYLE CRLF)
configure_file(src/Exports.def.in ${EXPORTS_DEF_FILE} NEWLINE_STYLE CRLF)

# Library
add_library (${TARGET_NAME} SHARED ${FCNPC_SRC}
                                   ${MAPANDREAS_SRC}
                                   ${COLANDREAS_SRC}
                                   ${EXPORTS_DEF_FILE})

set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")

target_include_directories(${TARGET_NAME} PRIVATE ${BULLET_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(${TARGET_NAME} PRIVATE strlcpy raknet amx)
target_link_libraries (${TARGET_NAME} PRIVATE
	subhook
	BulletInverseDynamics
	BulletSoftBody
	BulletDynamics
	BulletCollision
	LinearMath
	Bullet3Common
)

if (WIN32)
	target_compile_definitions(${TARGET_NAME} PRIVATE -DWINDOWS_IGNORE_PACKING_MISMATCH -DWIN32 -D_WIN32 -D__STDC__ -DSYSTEM_NAME="Windows")
	target_compile_options(${TARGET_NAME} PRIVATE /Zp1 /W4)
	target_link_libraries(${TARGET_NAME} PRIVATE snprintf)
else()
	target_compile_definitions(${TARGET_NAME} PRIVATE -DLINUX -DSYSTEM_NAME="GNU/Linux")
	target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wno-attributes -Wno-strict-aliasing -Wno-sequence-point -Wnull-conversion)
	target_link_libraries(${TARGET_NAME} PRIVATE fopen_s)
endif()

if (${BUILD_FOR_DL})
	target_compile_definitions(${TARGET_NAME} PRIVATE -DSAMP_03DL)
endif()
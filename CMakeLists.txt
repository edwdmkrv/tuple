cmake_minimum_required (VERSION 3.6)

set (TRAVIS_BUILD_NUMBER "$ENV{TRAVIS_BUILD_NUMBER}")

if ("${TRAVIS_BUILD_NUMBER}" STREQUAL "")
	set (TRAVIS_BUILD_NUMBER "1")
endif ("${TRAVIS_BUILD_NUMBER}" STREQUAL "")

project ("tuple"
	VERSION "0.0.${TRAVIS_BUILD_NUMBER}"
	DESCRIPTION "Simple tuple implementation"
	HOMEPAGE_URL "https://github.com/edwdmkrv/tuple"
	LANGUAGES CXX
)

option (BUILD_TYPE_RELEASE "Is build type Release")

if (BUILD_TYPE_RELEASE)
	set (CMAKE_BUILD_TYPE "Release")
	set (INSTALL_SUBDIR ".")
else (BUILD_TYPE_RELEASE)
	set (CMAKE_BUILD_TYPE "Debug")
	set (INSTALL_SUBDIR "Debug")
endif (BUILD_TYPE_RELEASE)

find_package (GTest REQUIRED)
find_package (Threads REQUIRED)

configure_file (version.hpp.in version.hpp)

set (CMAKE_VERBOSE_MAKEFILE OFF)

# Working stuff
add_subdirectory (lib)
add_subdirectory (src)

# Testing stuff
add_subdirectory (tst)
include (CTest)

# Packaging stuff
add_subdirectory (pkg)

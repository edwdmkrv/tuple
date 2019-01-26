cmake_minimum_required (VERSION 3.6)

project ("tuple_tst"
	VERSION "0.0.${TRAVIS_BUILD_NUMBER}"
	DESCRIPTION "Simple tuple implementation test"
	HOMEPAGE_URL "https://github.com"
	LANGUAGES CXX
)

add_executable (tupletest1 tupletest1.cpp)
add_executable (tupletest2 tupletest2.cpp)
add_executable (tupletest3 tupletest3.cpp)

set_target_properties (tupletest1 tupletest2 tupletest3 PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS "-pedantic;-Wall;-Wextra"
	INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}"
	LINK_LIBRARIES "${GTEST_LIBRARY};${GTEST_MAIN_LIBRARY};${CMAKE_THREAD_LIBS_INIT};tuplelib"
)

add_test (NAME TestOfTupleVersion1
	COMMAND tupletest1
	WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)

add_test (NAME TestOfTupleVersion2
	COMMAND tupletest2
	WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)

add_test (NAME TestOfTupleVersion3
	COMMAND tupletest3
	WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)

include (CTest)

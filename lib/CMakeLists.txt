cmake_minimum_required (VERSION 3.6)

project ("tuple_lib"
	VERSION "0.0.${TRAVIS_BUILD_NUMBER}"
	DESCRIPTION "Simple tuple implementation library"
	HOMEPAGE_URL "https://github.com/edwdmkrv/tuple/tree/master/lib"
	LANGUAGES CXX
)

add_library (tuplelib INTERFACE)

target_include_directories (tuplelib INTERFACE
	"${CMAKE_SOURCE_DIR}/lib"
)

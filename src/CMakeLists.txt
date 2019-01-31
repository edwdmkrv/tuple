cmake_minimum_required (VERSION 3.6)

project ("tuple_src"
	VERSION "0.0.${TRAVIS_BUILD_NUMBER}"
	DESCRIPTION "Simple tuple implementation sources"
	HOMEPAGE_URL "https://github.com/edwdmkrv/tuple/tree/master/src"
	LANGUAGES CXX
)

add_executable (tupleprog tuple.cpp)

set_target_properties (tupleprog PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS "-pedantic;-Wall;-Wextra"
	LINK_LIBRARIES tuplelib
)

install (TARGETS tupleprog RUNTIME DESTINATION "${INSTALL_SUBDIR}/bin")

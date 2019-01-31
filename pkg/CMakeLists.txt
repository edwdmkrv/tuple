cmake_minimum_required (VERSION 3.6)

project ("tuple_pkg"
	VERSION "0.0.${TRAVIS_BUILD_NUMBER}"
	DESCRIPTION "Simple tuple implementation package"
	HOMEPAGE_URL "https://github.com/edwdmkrv/tuple/tree/master/pkg"
	LANGUAGES CXX
)

# Packaging stuff
set (CPACK_GENERATOR DEB)

set (CPACK_DEB_PACKAGE_DEBUG ON)

set (CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

set (CPACK_DEBIAN_PACKAGE_DESCRIPTION
"Simple tuple implementation
 This package contains a simple tuple implementation that is
 to be checked on by the OTUS C++ course instructor.")

set (CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set (CPACK_PACKAGE_ARCHITECTURE "amd64")
set (CPACK_PACKAGE_CONTACT myname@company.com)
set (CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

include (CPack)

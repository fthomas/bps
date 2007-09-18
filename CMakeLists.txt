PROJECT(BPS)

# Make the output of make more verbose.
SET(CMAKE_VERBOSE_MAKEFILE ON)

SUBDIRS(libbps)
SUBDIRS(mensor)

# Specify directories in which to search for includes and libraries.
INCLUDE_DIRECTORIES(BEFORE libbps)
LINK_DIRECTORIES(libbps)

ADD_EXECUTABLE(bpstest main.cpp)
TARGET_LINK_LIBRARIES(bpstest bps)

# We use CPack to generate the source tarball.
SET(CPACK_GENERATOR "TGZ")
#SET(CPACK_PACKAGE_NAME "bps")
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "bps")
INCLUDE(CPack)

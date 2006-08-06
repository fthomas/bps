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

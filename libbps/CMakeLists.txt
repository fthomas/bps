SET(libbps_SOURCES
    bps_3-vector.cpp
    bps_n-vector.cpp
    bps_quaternion.cpp
)

SET(libbps_HEADERS
    bps_3-vector.h
    bps_constants.h
    bps_n-vector.h
    bps_quaternion.h
)

ADD_LIBRARY(bps SHARED ${libbps_SOURCES} ${libbps_HEADERS})

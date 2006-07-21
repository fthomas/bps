SET(LIBBPS_SOURCES bps_n-vector.cpp)
SET(LIBBPS_HEADERS bps_constants.h bps_n-vector.h)

ADD_LIBRARY(bps SHARED ${LIBBPS_SOURCES} ${LIBBPS_HEADERS})

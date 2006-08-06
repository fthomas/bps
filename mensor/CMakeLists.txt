# Search for the FindQt4.cmake file and process it. The configure step fails
# with an FATAL_ERROR if Qt4 is not found.
FIND_PACKAGE(Qt4 REQUIRED)

# Include the UseQt4.cmake file. This file sets ${QT_LIBRARIES} or adds 
# ${QT_INCLUDE_DIR} to the INCLUDE_DIRECTORIES. It looks for variables like
# ${QT_USE_QTOPENGL} for adding e.g. OpenGL libraries to the linker invocation
# (or not).
INCLUDE(${QT_USE_FILE})

SET(mensor_SOURCES main.cpp)
SET(mensor_HEADERS )

SET(mensor_UIS mainwindow.ui)
SET(mensor_UIS_H mainwindow.h)

QT_WRAP_UI(mensor mensor_UIS_H mensor_SOURCES_CX  ${mensor_UIS})

ADD_EXECUTABLE(mensor ${mensor_SOURCES})
TARGET_LINK_LIBRARIES(mensor ${QT_LIBRARIES})

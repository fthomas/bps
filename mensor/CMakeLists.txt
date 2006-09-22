# Search for the FindQt4.cmake file and process it. The configure step fails
# with an FATAL_ERROR if Qt4 is not found.
FIND_PACKAGE(Qt4 REQUIRED)

SET(QT_USE_QTOPENGL true)

# Include the UseQt4.cmake file. This file sets ${QT_LIBRARIES} or adds
# ${QT_INCLUDE_DIR} to the INCLUDE_DIRECTORIES. It looks for variables like
# ${QT_USE_QTOPENGL} for adding e.g. OpenGL libraries to the linker invocation
# (or not).
INCLUDE(${QT_USE_FILE})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

SET(mensor_SOURCES
    glcanvas.cpp
    main.cpp
    main_window.cpp
)

SET(mensor_HEADERS
    glcanvas.h
    main_window.h
)

SET(mensor_UIS main_window.ui)

QT4_AUTOMOC(${mensor_SOURCES})
QT4_WRAP_UI(mensor_UIS_H ${mensor_UIS})
QT4_WRAP_CPP(mensor_MOC ${mensor_UIS_H})

ADD_EXECUTABLE(mensor ${mensor_SOURCES} ${mensor_MOC})
TARGET_LINK_LIBRARIES(mensor ${QT_LIBRARIES})

cmake_minimum_required(VERSION 3.16)

project(Assignment3_1 VERSION 0.1 LANGUAGES CXX)

# Enable Qt Auto Generation
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# GStreamer Configuration
find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GSTREAMER_VIDEO REQUIRED gstreamer-video-1.0)

# Include GStreamer Directories
include_directories(${GSTREAMER_INCLUDE_DIRS})
link_directories(${GSTREAMER_LIBRARY_DIRS})

# Source Files
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Add Executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Assignment3_1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Assignment3_1 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Assignment3_1
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link Libraries
target_link_libraries(Assignment3_1
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
    PUBLIC
        ${GSTREAMER_LIBRARIES}
        ${GSTREAMER_VIDEO_LIBRARIES}
)

# Set Properties for macOS/iOS/Windows
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Assignment3_1)
endif()

set_target_properties(Assignment3_1 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Installation Directories
include(GNUInstallDirs)
install(TARGETS Assignment3_1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize Executable for Qt6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Assignment3_1)
endif()

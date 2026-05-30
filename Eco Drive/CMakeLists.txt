cmake_minimum_required(VERSION 3.16)

project(EcoDrive VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets Network)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        InputValidator.cpp
        InputValidator.h
        route.cpp
        route.h
        savedroutes.cpp
        savedroutes.h
        trip.cpp
        trip.h
        vehicleprofile.cpp
        vehicleprofile.h
        apimanager.cpp
        apimanager.h
        distanceapi.cpp
        distanceapi.h
        fuelpriceapi.cpp
        fuelpriceapi.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(EcoDrive
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        config.h
    )
endif()

target_link_libraries(EcoDrive PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)

if(APPLE)
    find_package(OpenSSL QUIET)
    if(OpenSSL_FOUND)
        target_link_libraries(EcoDrive PRIVATE OpenSSL::SSL OpenSSL::Crypto)
    endif()
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_finalize_executable(EcoDrive)
endif()

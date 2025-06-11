cmake_minimum_required(VERSION 3.16)

project(Network LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Network main.cpp
    router.h
    network.h )

include(GNUInstallDirs)
install(TARGETS Network
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

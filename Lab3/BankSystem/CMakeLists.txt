cmake_minimum_required(VERSION 3.16)

project(BankSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BankSystem main.cpp
    methods.h)

include(GNUInstallDirs)
install(TARGETS BankSystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

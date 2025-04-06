cmake_minimum_required(VERSION 3.16)

project(ReturnCashCalculatorQT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ReturnCashCalculatorQT main.cpp
    return_cash_calculator.h



)

include(GNUInstallDirs)
install(TARGETS ReturnCashCalculatorQT
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

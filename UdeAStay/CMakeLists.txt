cmake_minimum_required(VERSION 3.16)

project(udeastay LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ($ENV{GOOGLETEST_DIR})
    get_filename_component(_GTEST_BASE $ENV{GOOGLETEST_DIR} REALPATH)
elseif (EXISTS "") # set by QC
    get_filename_component(_GTEST_BASE "" REALPATH) # set by QC
endif()

if (NOT GTEST_ROOT)
    if (_GTEST_BASE)
        message("Setting GTEST_ROOT to ${_GTEST_BASE}")
        set(GTEST_ROOT ${_GTEST_BASE})
    else()
        message("No GTEST_ROOT specified - using system defaults.")
    endif()
endif()

find_package(GTest REQUIRED)
if (NOT GTest_FOUND)
    message (FATAL_ERROR "No GTest Found")
endif()

add_executable(udeastay main.cpp tests/tst_udeastay.cpp
    huesped.h huesped.cpp
    usuario.h usuario.cpp
    anfitrion.h anfitrion.cpp
    alojamiento.h alojamiento.cpp)
add_test(NAME udeastay COMMAND udeastay)

target_link_libraries(udeastay PRIVATE GTest::GTest)
if (GMock_FOUND)
    target_link_libraries(udeastay INTERFACE GTest::GMock)
endif()

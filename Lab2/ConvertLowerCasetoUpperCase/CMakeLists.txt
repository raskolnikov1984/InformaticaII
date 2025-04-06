cmake_minimum_required(VERSION 3.16)

project(LoweCaseToUpperCase LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ($ENV{GOOGLETEST_DIR})
    get_filename_component(_GTEST_BASE $ENV{GOOGLETEST_DIR} REALPATH)
elseif (EXISTS "/home/rodia/Escritorio/03-UdeA/InformaticaII/Lab2") # set by QC
    get_filename_component(_GTEST_BASE "/home/rodia/Escritorio/03-UdeA/InformaticaII/Lab2" REALPATH) # set by QC
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

add_executable(LoweCaseToUpperCase main.cpp tst_lowecasetouppercase.cpp
    lowercase_to_uppercase.h)
add_test(NAME LoweCaseToUpperCase COMMAND LoweCaseToUpperCase)

target_link_libraries(LoweCaseToUpperCase PRIVATE GTest::GTest)
if (GMock_FOUND)
    target_link_libraries(LoweCaseToUpperCase INTERFACE GTest::GMock)
endif()

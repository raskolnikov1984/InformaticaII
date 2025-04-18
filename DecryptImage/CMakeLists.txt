cmake_minimum_required(VERSION 3.16)

project(DecryptImage LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Test)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
add_executable(DecryptImage
  main.cpp
  tools/provided_tools.h
  README.md
  decriptimage.h decriptimage.cpp
  bitwiseoperators.cpp bitwiseoperators.h
)

target_link_libraries(DecryptImage Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)

include(GNUInstallDirs)
install(TARGETS DecryptImage
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Pruebas con GoogleTest
enable_testing()

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

add_executable(tst_decryptimage
  tests/tst_decryptimage.cpp
  decriptimage.cpp
  decriptimage.h
  bitwiseoperators.cpp
  bitwiseoperators.h
)
add_executable(tst_bitwiseoperators
  tests/tst_bitwiseoperators.cpp)
add_executable(tst_case1
  bitwiseoperators.h
  bitwiseoperators.cpp
  tests/tst_case1.cpp
)

target_link_libraries(tst_decryptimage GTest::GTest GTest::Main Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(tst_bitwiseoperators GTest::GTest GTest::Main Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(tst_case1 GTest::GTest GTest::Main Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)

add_test(NAME DecryptImageTest COMMAND tst_decryptimage)
add_test(NAME BitWiseOperatorts1Test COMMAND tst_bitwiseoperators)
add_test(NAME Case1Test COMMAND tst_case1)


if (GMock_FOUND)
    target_link_libraries(DecryptImage INTERFACE GTest::GMock)
endif()

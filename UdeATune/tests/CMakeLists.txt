cmake_minimum_required(VERSION 3.16)

project(UdeATuneTests LANGUAGES CXX)

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

# Create the main library
add_library(UdeATune_lib
    ../login.cpp
    ../album.cpp
    ../storage.cpp
    ../usuario.cpp
    ../artista.cpp
    ../cancion.cpp
    ../app.cpp
    ../anuncio.cpp
    ../favorito.cpp
)

add_executable(UdeATuneTests main.cpp
    tst_login.cpp
    tst_album.cpp
    tst_storage.cpp
    tst_usuario.cpp
    tst_artista.cpp
    tst_dinamiclist.cpp
    tst_udeatune.cpp
    tst_anuncio.cpp
)
add_test(NAME UdeATuneTests COMMAND UdeATuneTests)

target_link_libraries(UdeATuneTests PRIVATE GTest::GTest UdeATune_lib)
if (GMock_FOUND)
    target_link_libraries(UdeATuneTests INTERFACE GTest::GMock)
endif()

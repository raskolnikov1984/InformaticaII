cmake_minimum_required(VERSION 3.16)

project(Projecto LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# Agregar Google Test
enable_testing()  # Habilitar pruebas

add_executable(Projecto
  main.cpp

)

# Vincular Google Test
target_link_libraries(Projecto Qt${QT_VERSION_MAJOR}::Core gtest gtest_main)

# Agregar un ejecutable para las pruebas
add_executable(tests tst_tests.cpp)

# Vincular Google Test y Qt a las pruebas
target_link_libraries(tests Qt${QT_VERSION_MAJOR}::Core gtest gtest_main)

# Hacer que las pruebas se ejecuten
add_test(NAME MyTests COMMAND tests)

include(GNUInstallDirs)
install(TARGETS Projecto
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


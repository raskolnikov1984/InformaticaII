cmake_minimum_required(VERSION 3.10)
project(GuiaLab1)

set(CMAKE_CXX_STANDARD 17)

# Fuente
add_library(guia1 src/guia1.cpp)
add_library(problems src/problems.cpp)


# Ejecutable principal
add_executable(main src/main.cpp)
target_link_libraries(main guia1 problems)

# Pruebas con GoogleTest
enable_testing()
find_package(GTest REQUIRED)

add_executable(test_guia1 tests/test_guia1.cpp)
target_link_libraries(test_guia1 guia1 GTest::GTest GTest::Main)
add_test(NAME Guia1Test COMMAND test_guia1)

add_executable(test_problems tests/test_problems.cpp)
target_link_libraries(test_problems PRIVATE problems GTest::GTest GTest::Main)
add_test(NAME ProblemsTest COMMAND test_problems)

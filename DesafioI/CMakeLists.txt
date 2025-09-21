cmake_minimum_required(VERSION 3.16)

project(DesafioI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DesafioI main.cpp
    dataset/Encriptado1.txt dataset/Encriptado2.txt dataset/Encriptado3.txt dataset/Encriptado4.txt dataset/pista1.txt dataset/pista2.txt dataset/pista3.txt dataset/pista4.txt dataset/README.txt
    tools.cpp
    tools.h
    rle.h
    rle.cpp)

include(GNUInstallDirs)
install(TARGETS DesafioI
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

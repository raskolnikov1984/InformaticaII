cmake_minimum_required(VERSION 3.16)

project(UdeATune LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
  UdeATune main.cpp
    login.h login.cpp
    storage.h storage.cpp
    album.cpp album.h
    usuario.cpp usuario.h
    cancion.cpp cancion.h
    estructuras.h
    data/login.csv
    data/test.csv
    estructuras_datos/lista_dinamica.h
    artista.cpp artista.h
)

include(GNUInstallDirs)
install(TARGETS UdeATune
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
add_subdirectory(tests)

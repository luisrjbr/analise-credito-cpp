cmake_minimum_required(VERSION 3.5)

project(analise-credito-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(analise-credito-cpp main.cpp
    pessoa.h pessoa.cpp
    credito.h credito.cpp
    fraude.h fraude.cpp

    analise.h
    score.h score.cpp
    arraypersonalizado.h
    arrayfuncoes.h
    arraypersonalizadoconstiterator.h
    arraypersonalizadoiterator.h
)

include(GNUInstallDirs)
install(TARGETS analise-credito-cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

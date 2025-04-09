cmake_minimum_required(VERSION 3.20)
project(analise-credito-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Listas de arquivos .h e .cpp para facilitar
set(HEADER_FILES
    pessoa.h
    credito.h
    fraude.h
    analise.h
    score.h
    arraypersonalizado.h
    containersfuncoes.h
    arraypersonalizadoconstiterator.h
    arraypersonalizadoiterator.h
    vectorpersonalizado.h
    vectorpersonalizadoconstiterator.h
)

set(SOURCE_FILES
    pessoa.cpp
    credito.cpp
    fraude.cpp
    score.cpp
)

# 1) Criar a biblioteca com as classes/implementações
add_library(analise_credito_lib STATIC
    ${SOURCE_FILES}
    ${HEADER_FILES}  # Adiciona também os headers p/ aparecerem no IDE
)

# Direório de includes para encontrar os .h
target_include_directories(analise_credito_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 2) Executável principal
add_executable(analise-credito-cpp
    main.cpp
    #${HEADER_FILES}  # Opcional: incluir aqui se quiser listá-los também no IDE
)

# Faz link da biblioteca com o executável
target_link_libraries(analise-credito-cpp
    analise_credito_lib
)

# Instalação (opcional, se for efetivamente instalar)
include(GNUInstallDirs)
install(TARGETS analise-credito-cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# 3) Encontrar GTest/GMock
find_package(GTest REQUIRED)

# 4) Executável de teste
add_executable(run_test
    score_test.cpp
    credito_test.cpp
    fraude_test.cpp
    pessoa_test.cpp
    # Se quiser ver .h no run_test também, adicione-os aqui:
    # ${HEADER_FILES}
)

# Linkando a biblioteca e GTest/GMock
target_link_libraries(run_test
    analise_credito_lib
    GTest::gtest_main   # <--- inclui a main() de teste
    GTest::gtest
    GTest::gmock
    pthread
)

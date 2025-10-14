cmake_minimum_required(VERSION 4.0)
project(Durelli_definitivo)

set(CMAKE_CXX_STANDARD 23)

add_executable(Durelli_definitivo src/main.cpp
        src/binario.cpp
        include/binario.h
        src/verificaEntrada.cpp
        include/verificaEntrada.h
        src/hexadecimal.cpp
        include/hexadecimal.h
        src/ipv4.cpp
        include/ipv4.h
        src/octal.cpp
        include/octal.h
        src/binarioFracional.cpp
        include/binarioFracional.h
        src/BaseNToBaseM.cpp
        include/BaseNToBaseM.h)

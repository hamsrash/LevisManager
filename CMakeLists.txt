cmake_minimum_required(VERSION 4.2)
project(LevisManager C)

set(CMAKE_C_STANDARD 11)

add_executable(LevisManager main.c
        empleados.h
        empleados.c
        archivos.c
        archivos.h
        productos.c
        productos.h
        menus.c
        menus.h
        ventas.c
        ventas.h
)

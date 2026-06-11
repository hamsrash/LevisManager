//
// Created by hamsrash on 04/06/26.
//
#include <stdio.h>
#include "archivos.h"
#include "empleados.h"

void guardarEmpleado(Empleado e){
    FILE *archivo;

    archivo = fopen("empleados.txt","a");
    if(archivo == NULL){
        return;
    }
    escribirEmpleado(archivo, e);
    fclose(archivo);
}

//
// Created by hamsrash on 09/06/26.
//

#include <stdio.h>

#include "menus.h"
#include "empleados.h"
#include "productos.h"

void menuPrincipal(){
    int opcion;
    do{
        printf("\n");
        printf("===== SISTEMA =====\n");
        printf("1. Empleados\n");
        printf("2. Productos\n");
        printf("0. Salir\n");

        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            menuEmpleados();
            break;
        case 2:
            menuProductos();
            break;
        case 0:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }
    } while(opcion != 0);
}
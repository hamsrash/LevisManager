//
// Created by hamsrash on 04/06/26.
//
#include <stdio.h>
#include "empleados.h"
#include "archivos.h"

Empleado capturarEmpleado(){
    Empleado e;

    printf("ID: ");
    scanf("%d", &e.id);

    printf("Nombre: ");
    scanf("%s", e.nombre);

    printf("Puesto: ");
    scanf("%s", e.puesto);

    printf("Salario: ");
    scanf("%f", &e.salario);

    return e;
}

int leerEmpleado(FILE *archivo, Empleado *e){
    return fscanf(archivo, "%d;%49[^;];%29[^;];%f\n", &e->id, e->nombre, e->puesto, &e->salario);
}

void imprimirEmpleado(Empleado e){
    printf("\n");
    printf("ID: %d\n", e.id);
    printf("Nombre: %s\n", e.nombre);
    printf("Puesto: %s\n", e.puesto);
    printf("Salario: %.2f\n", e.salario);
}

void mostrarEmpleados(){
    FILE *archivo;
    Empleado e;

    archivo = fopen("empleados.txt","r");
    if(archivo == NULL){
        printf("No existe archivo.\n");
        return;
    }
    while(leerEmpleado(archivo, &e) == 4){
        imprimirEmpleado(e);
    }
    fclose(archivo);
}

int buscarEmpleadoPorID(int idBuscado, Empleado *e){
    FILE *archivo;
    Empleado aux;

    archivo = fopen("empleados.txt", "r");
    if(archivo == NULL){
        return 0;
    }
    while(leerEmpleado(archivo, &aux) == 4){
        if(aux.id == idBuscado){
            *e = aux;
            fclose(archivo);
            return 1;
        }
    }
    fclose(archivo);

    return 0;
}

void escribirEmpleado(FILE *archivo, Empleado e){
    fprintf(archivo, "%d;%s;%s;%.2f\n", e.id, e.nombre, e.puesto, e.salario);
}

void modificarEmpleado(int idBuscado){
    FILE *archivo, *temp;
    Empleado e, nuevo;
    int encontrado = 0;

    archivo = fopen("empleados.txt", "r");
    temp = fopen("temp.txt", "w");

    if(archivo == NULL || temp == NULL){
        printf("Error al abrir archivos.\n");
        return;
    }
    while(leerEmpleado(archivo, &e) == 4){
        if(e.id == idBuscado){
            encontrado = 1;
            printf("\nEmpleado encontrado:\n");
            imprimirEmpleado(e);
            printf("\nIngrese los nuevos datos:\n");
            nuevo = capturarEmpleado();
            escribirEmpleado(temp, nuevo);
        }else{
            escribirEmpleado(temp, e);
        }
    }
    fclose(archivo);
    fclose(temp);

    if(encontrado){
        remove("empleados.txt");
        rename("temp.txt", "empleados.txt");
        printf("\nEmpleado modificado correctamente.\n");
    }else{
        remove("temp.txt");
        printf("\nEmpleado no encontrado.\n");
    }
}

void eliminarEmpleado(int idBuscado){
    FILE *archivo, *temp;
    Empleado e;
    int encontrado = 0;

    archivo = fopen("empleados.txt", "r");
    temp = fopen("temp.txt", "w");

    if(archivo == NULL || temp == NULL){
        printf("Error al abrir archivos.\n");
        return;
    }
    while(leerEmpleado(archivo,&e) == 4){
        if(e.id == idBuscado){
            encontrado = 1;
            printf("\nEmpleado eliminado:\n");
            imprimirEmpleado(e);
        }else{
            escribirEmpleado(temp, e);
        }
    }
    fclose(archivo);
    fclose(temp);
    if(encontrado){
        remove("empleados.txt");
        rename("temp.txt", "empleados.txt");
        printf("\nEliminacion exitosa.\n");
    }else{
        remove("temp.txt");
        printf("\nEmpleado no encontrado.\n");
    }
}

void menuEmpleados(){
    int opcion;
    Empleado e;
    int id;

    do{
        printf("\n");
        printf("===== EMPLEADOS =====\n");
        printf("1. Agregar\n");
        printf("2. Mostrar\n");
        printf("3. Buscar\n");
        printf("4. Modificar\n");
        printf("5. Eliminar\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                e = capturarEmpleado();
                guardarEmpleado(e);
                break;
            case 2:
                mostrarEmpleados();
                break;
            case 3:
                printf("ID a buscar: ");
                scanf("%d", &id);
                if(buscarEmpleadoPorID(id, &e)){
                    imprimirEmpleado(e);
                }else{
                    printf("Empleado no encontrado.\n");
                }
                break;
            case 4:
                printf("ID a modificar: ");
                scanf("%d", &id);
                modificarEmpleado(id);
                break;
            case 5:
                printf("ID a eliminar: ");
                scanf("%d", &id);
                eliminarEmpleado(id);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    }while(opcion != 0);
}
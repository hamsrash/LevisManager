//
// Created by hamsrash on 04/06/26.
//

#ifndef LEVISMANAGER_EMPLEADOS_H
#define LEVISMANAGER_EMPLEADOS_H

typedef struct{
    int id;
    char nombre[50];
    char puesto[30];
    float salario;
}Empleado;

Empleado capturarEmpleado();
int leerEmpleado(FILE *archivo, Empleado *e);
void imprimirEmpleado(Empleado e);
void mostrarEmpleados();
int buscarEmpleadoPorID(int idBuscado, Empleado *e);
void escribirEmpleado(FILE *archivo, Empleado e);
void modificarEmpleado(int idBuscado);
void eliminarEmpleado(int idBuscado);
void menuEmpleados();

#endif //LEVISMANAGER_EMPLEADOS_H

//
// Created by hamsrash on 09/06/26.
//

#ifndef LEVISMANAGER_VENTAS_H
#define LEVISMANAGER_VENTAS_H
#include <stdio.h>
typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct{
    int idVenta;
    int idEmpleado;
    int idProducto;
    int cantidad;
    float total;
    Fecha fecha;
}Venta;

Fecha capturarFecha();
Venta capturarVenta();
void imprimirFecha(Fecha f);
void imprimirVenta(Venta v);
void escribirVenta(FILE *archivo, Venta v);
void guardarVenta(Venta v);
int leerVenta(FILE *archivo, Venta *v);
void mostrarVentas();

#endif //LEVISMANAGER_VENTAS_H

//
// Created by hamsrash on 09/06/26.
//
#include <stdio.h>
#include "ventas.h"

Fecha capturarFecha(){
    Fecha f;

    printf("Dia: ");
    scanf("%d", &f.dia);

    printf("Mes: ");
    scanf("%d", &f.mes);

    printf("Anio: ");
    scanf("%d", &f.anio);

    return f;
}

Venta capturarVenta(){
    Venta v;

    printf("ID Venta: ");
    scanf("%d", &v.idVenta);

    printf("ID Empleado: ");
    scanf("%d", &v.idEmpleado);

    printf("ID Producto: ");
    scanf("%d", &v.idProducto);

    printf("Cantidad: ");
    scanf("%d", &v.cantidad);

    printf("\nFecha de venta\n");
    v.fecha = capturarFecha();
    v.total = 0;

    return v;
}

void imprimirFecha(Fecha f){
    printf("%02d/%02d/%04d", f.dia, f.mes, f.anio);
}

void imprimirVenta(Venta v){
    printf("\n");
    printf("ID Venta: %d\n", v.idVenta);
    printf("ID Empleado: %d\n", v.idEmpleado);
    printf("ID Producto: %d\n", v.idProducto);
    printf("Cantidad: %d\n", v.cantidad);
    printf("Total: %.2f\n", v.total);
    printf("Fecha: ");
    imprimirFecha(v.fecha);
    printf("\n");
}

void escribirVenta(FILE *archivo, Venta v){
    fprintf(
        archivo,
        "%d;%d;%d;%d;%.2f;%d;%d;%d\n",
        v.idVenta,
        v.idEmpleado,
        v.idProducto,
        v.cantidad,
        v.total,
        v.fecha.dia,
        v.fecha.mes,
        v.fecha.anio
    );
}

void guardarVenta(Venta v){
    FILE *archivo;
    archivo = fopen("ventas.txt", "a");

    if(archivo == NULL){
        return;
    }
    escribirVenta(archivo, v);
    fclose(archivo);
}

int leerVenta(FILE *archivo, Venta *v){
    return fscanf(
        archivo,
        "%d;%d;%d;%d;%f;%d;%d;%d\n",
        &v->idVenta,
        &v->idEmpleado,
        &v->idProducto,
        &v->cantidad,
        &v->total,
        &v->fecha.dia,
        &v->fecha.mes,
        &v->fecha.anio
    );
}

void mostrarVentas(){
    FILE *archivo;
    Venta v;
    archivo = fopen("ventas.txt", "r");

    if(archivo == NULL){
        printf("No existe archivo.\n");
        return;
    }
    while(leerVenta(archivo, &v) == 8){
        imprimirVenta(v);
    }
    fclose(archivo);
}
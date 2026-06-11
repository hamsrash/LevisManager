//
// Created by hamsrash on 09/06/26.
//

#ifndef LEVISMANAGER_PRODUCTOS_H
#define LEVISMANAGER_PRODUCTOS_H

typedef struct{
    int id;
    char nombre[50];
    float precio;
    int stock;
}Producto;

Producto capturarProducto();
void imprimirProducto(Producto p);
void escribirProducto(FILE *archivo, Producto p);
void guardarProducto(Producto p);
int leerProducto(FILE *archivo, Producto *p);
void mostrarProductos();
int buscarProductoPorID(int idBuscado, Producto *p);
void modificarEmpleado(int idBuscado);
void eliminarEmpleado(int idBuscado);
void menuProductos();

#endif //LEVISMANAGER_PRODUCTOS_H

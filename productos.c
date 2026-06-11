//
// Created by hamsrash on 09/06/26.
//
#include <stdio.h>
#include "productos.h"

Producto capturarProducto(){
    Producto p;

    printf("ID: ");
    scanf("%d", &p.id);

    printf("Nombre: ");
    scanf(" %49[^\n]", p.nombre);

    printf("Precio: ");
    scanf("%f", &p.precio);

    printf("Stock: ");
    scanf("%d", &p.stock);

    return p;
}

void imprimirProducto(Producto p){
    printf("\n");
    printf("ID: %d\n", p.id);
    printf("Nombre: %s\n", p.nombre);
    printf("Precio: %.2f\n", p.precio);
    printf("Stock: %d\n", p.stock);
}

void escribirProducto(FILE *archivo, Producto p){
    fprintf(
        archivo,
        "%d;%s;%.2f;%d\n",
        p.id,
        p.nombre,
        p.precio,
        p.stock
    );
}

void guardarProducto(Producto p){
    FILE *archivo;
    archivo = fopen("productos.txt", "a");

    if(archivo == NULL){
        return;
    }
    escribirProducto(archivo, p);
    fclose(archivo);
}

int leerProducto(FILE *archivo, Producto *p){
    return fscanf(
        archivo,
        "%d;%49[^;];%f;%d\n",
        &p->id,
        p->nombre,
        &p->precio,
        &p->stock
    );
}

void mostrarProductos(){
    FILE *archivo;
    Producto p;
    archivo = fopen("productos.txt", "r");

    if(archivo == NULL){
        printf("No existe archivo.\n");
        return;
    }
    while(leerProducto(archivo, &p) == 4){
        imprimirProducto(p);
    }
    fclose(archivo);
}

int buscarProductoPorID(int idBuscado, Producto *p){
    FILE *archivo;
    Producto aux;
    archivo = fopen("productos.txt", "r");

    if(archivo == NULL){
        return 0;
    }
    while(leerProducto(archivo, &aux) == 4){
        if(aux.id == idBuscado){
            *p = aux;
            fclose(archivo);
            return 1;
        }
    }
    fclose(archivo);
    return 0;
}

void modificarProducto(int idBuscado){
    FILE *archivo, *temp;
    Producto e, nuevo;
    int encontrado = 0;

    archivo = fopen("productos.txt", "r");
    temp = fopen("temp.txt", "w");

    if(archivo == NULL || temp == NULL){
        printf("Error al abrir archivos.\n");
        return;
    }
    while(leerProducto(archivo, &e) == 4){
        if(e.id == idBuscado){
            encontrado = 1;
            printf("\nProducto encontrado:\n");
            imprimirProducto(e);
            printf("\nIngrese los nuevos datos:\n");
            nuevo = capturarProducto();
            escribirProducto(temp, nuevo);
        }else{
            escribirProducto(temp, e);
        }
    }
    fclose(archivo);
    fclose(temp);

    if(encontrado){
        remove("productos.txt");
        rename("temp.txt", "productos.txt");
        printf("\nProducto modificado correctamente.\n");
    }else{
        remove("temp.txt");
        printf("\nProducto no encontrado.\n");
    }
}

void eliminarProducto(int idBuscado){
    FILE *archivo, *temp;
    Producto e;
    int encontrado = 0;

    archivo = fopen("productos.txt", "r");
    temp = fopen("temp.txt", "w");

    if(archivo == NULL || temp == NULL){
        printf("Error al abrir archivos.\n");
        return;
    }
    while(leerProducto(archivo,&e) == 4){
        if(e.id == idBuscado){
            encontrado = 1;
            printf("\nProducto eliminado:\n");
            imprimirProducto(e);
        }else{
            escribirProducto(temp, e);
        }
    }
    fclose(archivo);
    fclose(temp);
    if(encontrado){
        remove("productos.txt");
        rename("temp.txt", "productos.txt");
        printf("\nEliminacion exitosa.\n");
    }else{
        remove("temp.txt");
        printf("\nProducto no encontrado.\n");
    }
}

void menuProductos(){
    int opcion, id;
    Producto p;

    do{
        printf("\n");
        printf("===== PRODUCTOS =====\n");
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
                p = capturarProducto();
                guardarProducto(p);
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                printf("ID a buscar: ");
                scanf("%d", &id);
                if(buscarProductoPorID(id, &p)){
                    imprimirProducto(p);
                }else{
                    printf("Producto no encontrado.\n");
                }
                break;
            case 4:
                printf("ID a modificar: ");
                scanf("%d", &id);
                modificarProducto(id);
                break;
            case 5:
                printf("ID a eliminar: ");
                scanf("%d", &id);
                eliminarProducto(id);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while(opcion != 0);
}
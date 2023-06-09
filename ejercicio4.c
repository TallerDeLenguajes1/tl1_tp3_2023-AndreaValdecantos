#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
typedef struct ProductoApedir {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Clientes {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
}Cliente;

void cargarClientes(Cliente* clientes, int cantidadDeClientes);
void mostrarClientes(Cliente* clientes, int cantidadDeClientes);
float costoTotalDeProducto(Producto producto);

int main(){
    srand(time(NULL));
    int cantidadDeClientes;

    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d", &cantidadDeClientes);
    getchar();

    //carga de clientes
    Cliente *clientes = (Cliente*)malloc(sizeof(Cliente)*cantidadDeClientes);
    cargarClientes(clientes, cantidadDeClientes);

    //mostrar clientes
    mostrarClientes(clientes, cantidadDeClientes);

    return 0;
}

void cargarClientes(Cliente* clientes, int cantidadDeClientes){
    printf("Ingrese los datos de los clientes: \n");
    char *buffNombreCliente = (char*)malloc(100*sizeof(char));
    for (int i = 0; i < cantidadDeClientes; i++){
        clientes[i].ClienteID = i + 1;
        
        puts("Nombre del cliente");
        gets(buffNombreCliente);
      puts("\n");
        clientes[i].NombreCliente = (char*)malloc((strlen(buffNombreCliente)+1)*sizeof(char));
        strcpy(clientes[i].NombreCliente,buffNombreCliente);

        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].Productos = (Producto*)malloc((clientes[i].CantidadProductosAPedir)*sizeof(Producto));

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++){
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].TipoProducto = *(TiposProductos + j);
            clientes[i].Productos[j].PrecioUnitario = ((float)rand())/((float)RAND_MAX) * (100 - 10) + 10;
        }
    }

    free(buffNombreCliente);
}
void mostrarClientes(Cliente* clientes, int cantidadDeClientes){
    for (int i = 0; i < cantidadDeClientes; i++){
        float totalQuePagaElCliente = 0;
        printf("_____________ ID cliente: %d ______________\n", clientes[i].ClienteID);
        printf("_____________ NOMBRE DEL CLIENTE: %s ______________\n", clientes[i].NombreCliente);
        printf("_____________ Cantidad de productos: %d ______________\n", clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++){
            printf("N° producto: %d\n", clientes[i].Productos[j].ProductoID);
            printf("Tipo: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("Precio unitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Costo total por el producto: %.2f\n", costoTotalDeProducto(clientes[i].Productos[j]));
            totalQuePagaElCliente += costoTotalDeProducto(clientes[i].Productos[j]);
        }
        printf("TOTAL A PAGAR POR EL CLIENTE: %.2f\n------------------------\n", totalQuePagaElCliente);
      printf("\n\n");
    }
}
float costoTotalDeProducto(Producto producto){
    return producto.Cantidad * producto.PrecioUnitario;
}
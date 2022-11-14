#include <stdlib.h>
#include <stdio.h>
#include "Menu.h"
#include <time.h>

int main()
{
    elBug();
    arbolClientes *arbol = inicArbol();
    //generarFacturaRandom("Clientes.bin", "Facturas.bin");
    //generarArchivoRandom("Clientes.bin");
    arbol = archivoTOADL(arbol, "Clientes.bin");
    DespersistenciaDeFacturas("Facturas.bin", arbol);
    //AbrirArchiFacturasYleer("Facturas.bin");
    system("cls");
    arbol = Menu(arbol);
    //mostrarArbol(arbol);

    return 0;
}


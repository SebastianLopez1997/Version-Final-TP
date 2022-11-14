#ifndef _FACTURAS_H_
#define _FACTURAS_H_
#pragma once
#include <string.h>
#include "Clientes.h"
#include "Random.h"

/// === Estructuras.
typedef struct
{
    int id;
    char Nombre[30];
    char apellido[30];
    int mes;
    int anio;
    int Total;
    int Paga; /// 1 para paga --- 0 para impaga boolean
} STFactura;

typedef struct
{
    int id;
    STFactura Factura;
    struct nodoFactura *sig;
    struct nodoFactura *ante;
} nodoFactura;

/// === Prototipados.
STFactura crearFactura(int id, int anio, int mes,  char nombre[], char apellido[], int internet, int cable, int abonar);
nodoFactura *inicLista();
nodoFactura *CrearFacturaNodo(STFactura factura);
nodoFactura * agregarAlPrincipio(nodoFactura *lista, nodoFactura *nuevoNodo);
int FacturasTotales(nodoFactura *Factura);
int FacturasTotalesInpagas(nodoFactura *Factura);
void generarFacturaRandom(char archivo[], char archivoFacturas[]);


/// MUESTRA FACTURAS
void MuestraUnicaFactura(STFactura Factura);
void MostrarTodasLasFacturasDeUnCliente(nodoFactura *Lista);
void AbrirArchiFacturasYleer(char ArchiFacturas[]);


#endif

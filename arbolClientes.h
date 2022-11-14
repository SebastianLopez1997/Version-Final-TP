#ifndef _ARBOLCLIENTES_H_
#define _ARBOLCLIENTES_H_
#pragma once
#include "Facturas.h"

/// Estructuras.
typedef struct arbolClientes
{
    STCliente Cliente;
    struct nodoFactura *Factura;
    struct arbolClientes *izq;
    struct arbolClientes *der;
} arbolClientes;

/// Prototipados.
/// === GESTION ARBOL.
arbolClientes *inicArbol();
arbolClientes *crearNodoArbol(STCliente cliente);
arbolClientes *agregarNodoArbol(arbolClientes *arbol, arbolClientes *nuevoNodo);

// Mostrar
void mostrarArbol(arbolClientes *arbol);
void mostrarNodoArbol(arbolClientes *nodo);

// Borrar
arbolClientes *borrarCliente(arbolClientes *arbol, int idCliente);
arbolClientes *nodoMasDerecha(arbolClientes *arbol);
arbolClientes *nodoMasIzquierda(arbolClientes *arbol);

/// === GESTION CLIENTE EN ARBOL.
arbolClientes *buscarNodoCliente(arbolClientes *arbol, int idCliente);
arbolClientes *modificarDatosPersonalesCliente(arbolClientes *arbol);
void mostrarDatosdeClienteXID(int idCliente, arbolClientes *arbol);
arbolClientes *buscarNodoClientePorDNI(arbolClientes *arbol, char DNI[], int id);

/// PERSISTENCIA ARBOL Y CLIENTE.
void persistirRegistroModificado(char archivo[], STRegistroCliente nuevo);
void PersistirCliente(arbolClientes *cliente, FILE *fp);
STRegistroCliente crearRegistroCliente(arbolClientes *cliente);
void persistirArbol(char archivo[], arbolClientes *arbol);
void recorrerYGuardar(arbolClientes *arbol, FILE *fp);
arbolClientes *archivoTOADL(arbolClientes *arbol, char archivo[]);
void persistirNuevoNodo(arbolClientes *nodo, char archivo[]);
void modificarArchivoServicios(char archivo[], int idCliente);

/// GESTION ARBOL Y FACTURAS.
void PersistenciaDeFactura(char ArchiFacturas[], arbolClientes *Arbol);
void mostrarFactura(arbolClientes *arbol);
int SacarTotal(arbolClientes *Arbol);
void DespersistenciaDeFacturas(char archivoFacturas[], arbolClientes *arbol);
void agregarFacturaAlNodo(arbolClientes * arbol, nodoFactura * nuevoNodo);
void DespersistirFacturasClienteEspecifico(char archivoFacturas[], arbolClientes *cliente);
//void crearFacturaSemiAutomatica(arbolClientes * arbolPrincipal);

#endif // ARBOLCLIENTES_H_INCLUDED

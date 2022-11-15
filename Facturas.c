#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "Facturas.h" ///Posiblie bug
#include <time.h>
/// === Desarrollo funciones.
STFactura crearFactura(int id, int anio, int mes,  char nombre[], char apellido[], int internet, int cable, int abonar)
{
    STFactura nueva;

    nueva.id = id;
    nueva.anio=anio;
    nueva.mes=mes;
    strcpy(nueva.Nombre, nombre);
    strcpy(nueva.apellido, apellido);
    nueva.Total = 0;
    if (internet == 1)
    {
        nueva.Total += PrecioInternet();
    }
    if (cable == 1)
    {
        nueva.Total += PrecioCable();
    }
    nueva.Paga = abonar;


    return nueva;
}

nodoFactura *inicLista()
{
    return NULL;
}

nodoFactura *CrearFacturaNodo(STFactura factura)
{
    nodoFactura *nueva = malloc(sizeof(nodoFactura));
    nueva->Factura = factura;
    nueva->sig = NULL;
    nueva->ante = NULL;
    return nueva;
}

nodoFactura * agregarAlPrincipio(nodoFactura *lista, nodoFactura *nuevoNodo)
{
    if (lista)
    {
        nuevoNodo->sig=lista;
        lista->ante=nuevoNodo;
    }
    lista = nuevoNodo;
    return lista;
}

void MuestraUnicaFactura(STFactura Factura)
{
    printf("\n\t\t\t\t\t|////////////////////////////\n");
    printf("\t\t\t\t\t| ID: %i\n", Factura.id);
    printf("\t\t\t\t\t| NOMBRE: %s\n", Factura.Nombre);
    printf("\t\t\t\t\t| APELLIDO: %s\n", Factura.apellido);
    printf("\t\t\t\t\t| FECHA: %i - %i\n", Factura.mes, Factura.anio);
    printf("\t\t\t\t\t|= = = = = = = = = = = = = = = \n");
    printf("\t\t\t\t\t| TOTAL: %i\n", Factura.Total);
    printf("\t\t\t\t\t|////////////////////////////\n");
}

void MostrarTodasLasFacturasDeUnCliente(nodoFactura *Lista)
{
    nodoFactura * seg=Lista;
    if (seg)
    {


        while (seg)
        {
            MuestraUnicaFactura(seg->Factura);
            seg=seg->sig;
        }
    }
    else
    {
        printf("\n\t\t\t\t\tNo hay facturas para mostrar\n");
    }

}

void AbrirArchiFacturasYleer(char ArchiFacturas[])
{
    FILE *BUFFER = fopen(ArchiFacturas, "rb");
    STFactura Aux;
    while (fread(&Aux, sizeof(STFactura), 1, BUFFER) > 0)
    {
        MuestraUnicaFactura(Aux);
    }
    fclose(BUFFER);
}
int PrecioCable()
{
    return 600;
}

int PrecioInternet()
{
    return 1000;
}

int FacturasTotales(nodoFactura *Factura)
{
    nodoFactura *NewFac = NULL;
    NewFac = Factura;
    int Cantidad = 0;
    while (NewFac)
    {
        Cantidad++;
        NewFac->sig;
    }
    return Cantidad;
}

int FacturasTotalesInpagas(nodoFactura *Factura)
{
    nodoFactura *NewFac = NULL;
    NewFac = Factura;
    int Cantidad = 0;

    while (NewFac)
    {
        if (NewFac->Factura.Paga == 0)
        {
            Cantidad++;
            NewFac->sig;
        }
    }
    return Cantidad;
}

void generarFacturaRandom(char archivo[], char archivoFacturas[])
{
    STRegistroCliente aux;
    STFactura facturita;
    int anio, mes;
    FILE *fp = fopen(archivo, "rb");
    if (fp)
    {
        FILE * bufferFacturas=fopen(archivoFacturas, "wb");
        if(bufferFacturas)
        {
            while (fread(&aux, sizeof(STRegistroCliente), 1, fp) > 0)
            {
                anio=anioRandom();
                mes=mesRandom();
                while (anio <= 2022)
                {
                    while (mes<= 11)
                    {
                        facturita=crearFactura(aux.id, anio, mes, aux.Nombre, aux.Apellido, aux.Internet, aux.Cable, 1);
                        fwrite(&facturita, sizeof(STFactura), 1, bufferFacturas);
                        mes++;
                    }
                    mes=1;
                    anio++;
                }
            }
            fclose(bufferFacturas);
        }

        fclose(fp);
    }
}

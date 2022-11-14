#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbolClientes.h"

/// === GESTION ARBOL.

arbolClientes *inicArbol()
{
    return NULL;
}

arbolClientes *crearNodoArbol(STCliente cliente)
{
    arbolClientes *nuevo = (arbolClientes *)malloc(sizeof(arbolClientes));
    nuevo->Cliente = cliente;
    nuevo->Factura = inicLista();
    nuevo->der = NULL;
    nuevo->izq = NULL;
    return nuevo;
}

arbolClientes *agregarNodoArbol(arbolClientes *arbol, arbolClientes *nuevoNodo)
{
    if (arbol == NULL)
    {
        arbol = nuevoNodo;
    }
    else
    {
        if (arbol->Cliente.Login.id > nuevoNodo->Cliente.Login.id)
        {
            arbol->izq = agregarNodoArbol(arbol->izq, nuevoNodo);
        }
        else
        {
            arbol->der = agregarNodoArbol(arbol->der, nuevoNodo);
        }
    }
    return arbol;
}

void mostrarArbol(arbolClientes *arbol)
{
    if (arbol)
    {
        mostrarArbol(arbol->izq);
        mostrarNodoArbol(arbol);
        mostrarArbol(arbol->der);
    }
}

void mostrarNodoArbol(arbolClientes *nodo)
{
    if (nodo)
    {
        MostrarUncliente(nodo->Cliente);
    }
}

arbolClientes *borrarCliente(arbolClientes *arbol, int idCliente)
{
    arbolClientes *masDerecha;
    arbolClientes *masIzquierda;
    if (arbol)
    {
        if (idCliente == arbol->Cliente.Dato.id)
        {
            if (arbol->izq)
            {
                masDerecha = nodoMasDerecha(arbol->izq);
                arbol=masDerecha;
                arbol->izq = borrarCliente(arbol->izq, masDerecha->Cliente.Dato.id);
            }
            else if (arbol->der)
            {
                masIzquierda = nodoMasIzquierda(arbol->der);
                arbol=masIzquierda;
                arbol->der = borrarCliente(arbol->der, masIzquierda->Cliente.Dato.id);
            }
            else
            { // En caso de que sea hoja.
                free(arbol);
                arbol = NULL;
            }
        }
        else if (idCliente > arbol->Cliente.Dato.id)
        {
            arbol->der = borrarCliente(arbol->der, idCliente);
        }
        else
        {
            arbol->izq = borrarCliente(arbol->izq, idCliente);
        }
    }
    return arbol;
}

arbolClientes *nodoMasDerecha(arbolClientes *arbol)
{
    if (arbol->der)
    {
        arbol = nodoMasDerecha(arbol->der);
    }
    return arbol;
}

arbolClientes *nodoMasIzquierda(arbolClientes *arbol)
{
    if (arbol->izq)
    {
        arbol = nodoMasIzquierda(arbol->izq);
    }
    return arbol;
}

/// === GESTION CLIENTE EN ARBOL.
arbolClientes *buscarNodoCliente(arbolClientes *arbol, int idCliente)
{
    arbolClientes *aux = inicArbol();
    if (arbol)
    {
        if (arbol->Cliente.Login.id== idCliente)
        {
            aux = arbol;
        }
        else
        {
            if (idCliente < arbol->Cliente.Login.id)
            {
                aux = buscarNodoCliente(arbol->izq, idCliente);
            }
            else
            {
                aux = buscarNodoCliente(arbol->der, idCliente);
            }
        }
    }
    return aux;
}

arbolClientes *buscarNodoClientePorDNI(arbolClientes *arbol, char DNI[], int id)
{
    arbolClientes * IdEncontrado = inicArbol();
    if (arbol)
    {
        if (strcmpi(arbol->Cliente.Dato.DNI, DNI) == 0)
        {
            IdEncontrado = arbol;
        }
        else
        {
            if (arbol->Cliente.Login.id>id)
            {
                arbol = buscarNodoClientePorDNI(arbol->izq, DNI, id);
            }
            else
            {
                arbol = buscarNodoClientePorDNI(arbol->der, DNI, id);
            }
        }
    }
    return IdEncontrado;
}

void mostrarDatosdeClienteXID(int idCliente, arbolClientes *arbol)
{
    arbolClientes *aux = inicArbol();
    aux = buscarNodoCliente(arbol, idCliente);
    MostrarUncliente(aux->Cliente);
}

arbolClientes *modificarDatosPersonalesCliente(arbolClientes *arbol)
{
    char seguir = 's';
    int opcion, flag = 1, idBuscado;
    arbolClientes *modificado = inicArbol();
    STCliente nuevo;
    STRegistroCliente mod;

    while (seguir != 'n')
    {
        printf("\n\t\t\t\t\tIngrese el ID del cliente.\n");
        scanf("%i", &idBuscado);
        modificado = buscarNodoCliente(arbol, idBuscado);
        if (modificado != NULL)
        {
            nuevo = modificado->Cliente;
            seguir = 'n';
        }
        else
        {
            printf("El DNI ingresado no ha sido encontrado.\n");
            seguir = confirmacionBucle();
        }
    }

    seguir = 's';

    while (seguir != 'n')
    {

        printf("\n\t\t\t\tQue valor desea modificar?\n");
        printf("\n\t\t\t\t1. Nombre.\n");
        printf("\n\t\t\t\t2. Apellido.\n");
        printf("\n\t\t\t\t3. Telefono.\n");
        printf("\n\t\t\t\t4. Barrio.\n");
        printf("\n\t\t\t\t5. Calle.\n");
        printf("\n\t\t\t\t6. Password.\n");
        printf("nombre: %s", nuevo.Dato.Nombre);
        scanf("%i", &opcion);
        switch (opcion)
        {
        case 1:
            printf("\n\t\t\t\tHa seleccionado la opcion 1.\n");
            seguir = confirmacionBucle();
            if (seguir != 'n')
            {
                modificarNombre(nuevo.Dato.Nombre);
                flag = 0;
                system("cls");
            }
            break;
        case 2:
            printf("\n\t\t\t\tHa seleccionado la opcion 2.\n");
            seguir = confirmacionBucle();
            if (seguir != 'n')
            {
                modificarApellido(nuevo.Dato.Apellido);
                flag = 0;
                system("cls");
            }
            break;
        case 3:
            printf("\n\t\t\t\tHa seleccionado la opcion 3.\n");
            seguir = confirmacionBucle();
            if (seguir != 'n')
            {
                modificarTelefono(nuevo.Dato.NumeroCel);
                flag = 0;
                system("cls");
            }
            break;
        case 4:
            printf("\n\t\t\t\tHa seleccionado la opcion 4.\n");
            seguir = confirmacionBucle();
            if (seguir != 'n')
            {
                modificarBarrio(nuevo.Dato.direccion.Barrio);
                flag = 0;
                system("cls");
            }
            break;
        case 5:
            printf("\n\t\t\t\tHa seleccionado la opcion 5.\n");
            seguir = confirmacionBucle();
            if (seguir != 'n')
            {
                modificarDireccion(nuevo.Dato.direccion.Direccion);
                flag = 0;
                system("cls");
            }
            break;
        case 6:
            printf("\n\t\t\t\tHa seleccionado la opcion 6.\n");
            seguir = confirmacionBucle();
            if (seguir != 'n')
            {
                cambiarPassword(arbol->Cliente.Login.pass);
                flag = 0;
                system("cls");
            }
            break;
        default:
            printf("\n\t\t\t\tHa ingresado una opcion invalida.\n");
            seguir = confirmacionBucle();
            break;
        }
        seguir = confirmacionBucle();
        system("cls");
    }

    if (flag == 0)
    { /*Hubo modifiación, entonces procede a la sustitución de la estructura.*/
        modificado->Cliente = nuevo;
        mod=crearRegistroCliente(modificado);
        persistirRegistroModificado("Clientes.bin", mod);
    }

    return arbol;
}

/// PERSISTENCIA ARBOL Y CLIENTE.
void persistirRegistroModificado(char archivo[], STRegistroCliente nuevo){
    FILE * fp=fopen(archivo, "r+b");
    STRegistroCliente aux;
    if(fp){
        fseek(fp, sizeof(STRegistroCliente)*(nuevo.id-1), SEEK_SET);
        fwrite(&nuevo, sizeof(STRegistroCliente), 1, fp);
        fclose(fp);
    }
}


void persistirNuevoNodo(arbolClientes *nodo, char archivo[])
{
    STRegistroCliente aux;
    FILE *fp = fopen(archivo, "ab");
    if (fp)
    {
        fseek(fp, 0, SEEK_END);
        aux = crearRegistroCliente(nodo);
        fwrite(&aux, sizeof(STRegistroCliente), 1, fp);
        fclose(fp);
    }
}

void PersistirCliente(arbolClientes *cliente, FILE *fp)
{
    if (fp)
    {
        STRegistroCliente aux;
        aux = crearRegistroCliente(cliente);
        fwrite(&aux, sizeof(STRegistroCliente), 1, fp);
    }
}

void persistirArbol(char archivo[], arbolClientes *arbol)
{
    FILE *fp = fopen(archivo, "wb");
    if (fp)
    {
        recorrerYGuardar(arbol, &*fp);
        fclose(fp);
    }
}
void recorrerYGuardar(arbolClientes *arbol, FILE *fp)
{
    if (arbol)
    {
        recorrerYGuardar(arbol->izq, &*fp);
        PersistirCliente(arbol, &*fp);
        recorrerYGuardar(arbol->der, &*fp);
    }
}

STRegistroCliente crearRegistroCliente(arbolClientes *cliente)
{
    STRegistroCliente aux;
    strcpy(aux.Nombre, cliente->Cliente.Dato.Nombre);
    strcpy(aux.Apellido, cliente->Cliente.Dato.Apellido);
    strcpy(aux.DNI, cliente->Cliente.Dato.DNI);
    strcpy(aux.Direccion, cliente->Cliente.Dato.direccion.Direccion);
    strcpy(aux.Barrio, cliente->Cliente.Dato.direccion.Barrio);
    strcpy(aux.NumeroCel, cliente->Cliente.Dato.NumeroCel);
    aux.id = cliente->Cliente.Login.id;
    strcpy(aux.pass, cliente->Cliente.Login.pass);
    aux.Cable = cliente->Cliente.Servicio.Cable;
    aux.Internet = cliente->Cliente.Servicio.Internet;
    return aux;
}

arbolClientes *archivoTOADL(arbolClientes *arbol, char archivo[])
{
    STRegistroCliente a;
    STCliente nuevoCliente;
    arbolClientes *nuevoNodo = inicArbol();
    FILE *fp = fopen(archivo, "rb");
    if (fp)
    {
        while (fread(&a, sizeof(STRegistroCliente), 1, fp) > 0)
        {
            if (a.Internet == 1 || a.Cable == 1)
            {
                nuevoCliente = registroToSTCLiente(a);
                nuevoNodo = crearNodoArbol(nuevoCliente);
                arbol = agregarNodoArbol(arbol, nuevoNodo);
            }
        }
        fclose(fp);
    }
    return arbol;
}

void modificarArchivoServicios(char archivo[], int idCliente){
    FILE * fp=fopen(archivo, "r+b");
    STRegistroCliente a;
    if(fp){
        while(fread(&a, sizeof(STRegistroCliente), 1, fp)>0){
            if(a.id==idCliente){
                a.Internet=0;
                a.Cable=0;
                fseek(fp, sizeof(STRegistroCliente)*(-1), SEEK_SET);
                fwrite(&a, sizeof(STRegistroCliente), 1, fp);
            }
        }
        fclose(fp);
    }
}

/// GESTION ARBOL Y FACTURAS.
void PersistenciaDeFactura(char ArchiFacturas[], arbolClientes *Arbol)
{
    arbolClientes *aux = NULL;
    aux = Arbol;
    nodoFactura *listaAux = NULL;
    listaAux = Arbol->Factura;

    FILE *BUFFER = fopen(ArchiFacturas, "ab");

    while (listaAux != NULL)
    {
        fwrite(&listaAux, sizeof(STFactura), 1, BUFFER);
        listaAux = listaAux->sig;
    }
    fclose(BUFFER);
}
void mostrarFactura(arbolClientes *arbol)
{
    if (arbol)
    {
        mostrarArbol(arbol->izq);
        MostrarTodasLasFacturasDeUnCliente(arbol->Factura);
        mostrarArbol(arbol->der);
    }
}
int SacarTotal(arbolClientes *Arbol)
{
    int total = 0;
    int flag = 0;
    int cable = 1200;
    int internet = 1800;
    int descuento = 600;
    if (Arbol->Cliente.Servicio.Cable == 1)
    {
        total = total + cable;
        flag++;
    }
    if (Arbol->Cliente.Servicio.Internet == 1)
    {
        total += internet;
        flag++;
    }
    if (flag == 2)
    {
        total -= descuento;
    }
    return total;
}

void DespersistenciaDeFacturas(char archivoFacturas[], arbolClientes *arbol)
{
    STFactura aux;
    nodoFactura *nuevaFactura;
    FILE *fp = fopen(archivoFacturas, "rb");
    if (fp)
    {
        while(fread(&aux, sizeof(STFactura), 1, fp) > 0)
        {
            nuevaFactura = CrearFacturaNodo(aux);
            agregarFacturaAlNodo(arbol, nuevaFactura);
        }
        fclose(fp);
    }
}

void agregarFacturaAlNodo(arbolClientes * arbol, nodoFactura * nuevoNodo){
    if(arbol){
        if(arbol->Cliente.Dato.id == nuevoNodo->Factura.id){
            arbol->Factura=agregarAlPrincipio(arbol->Factura, nuevoNodo);
            }else{
            if(nuevoNodo->Factura.id < arbol->Cliente.Dato.id ){
                agregarFacturaAlNodo(arbol->izq, nuevoNodo);
            }else{
                agregarFacturaAlNodo(arbol->der, nuevoNodo);
            }
        }
    }
}

void DespersistirFacturasClienteEspecifico(char archivoFacturas[], arbolClientes *cliente)
{
    STFactura aux;
    FILE *fp = fopen(archivoFacturas, "rb");
    if (fp)
    {
        while (fread(&aux, sizeof(STFactura), 1, fp) > 0)
        {
            if (aux.id == cliente->Cliente.Login.id)
            {
                nodoFactura *nuevo = CrearFacturaNodo(aux);
                //cliente->Factura = agregarAlPrincipio(cliente->Factura, nuevo);
            }
        }
        fclose(fp);
    }
}

/*void crearFacturaSemiAutomatica(arbolClientes * arbolPrincipal){
    if(arbolPrincipal){
        int anio=arbolPrincipal->Factura.Factura.anio;
        int mes=arbolPrincipal->Factura.Factura.mes;
            if(mes==12){
                mes=1;
                anio++;
            }else{
                mes++;
            }

        STFactura nuevaFactura=crearFactura(arbolPrincipal->Cliente.Dato.id, anio, mes, arbolPrincipal->Cliente.Dato.Nombre, arbolPrincipal->Cliente.Dato.Apellido, arbolPrincipal->Cliente.Servicio.Internet, arbolPrincipal->Cliente.Servicio.Cable, 0);
        nodoFactura nuevoNodo= CrearFacturaNodo(nuevaFactura);
        arbolPrincipal->Factura=agregarAlPrincipio(arbolPrincipal->Factura, nuevoNodo);

        crearFacturaSemiAutomatica(arbolPrincipal->izq);
        crearFacturaSemiAutomatica(arbolPrincipal->der);
    }
}*/



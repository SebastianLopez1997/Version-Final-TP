#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "Clientes.h"


char confirmacionBucle()
{
    char seguir;
    printf("\n\t\t\t\tPresione 'n' para salir o cualquier tecla para continuar.   \n");
    fflush(stdin);
    scanf("%c", &seguir);
    system("cls");
    return seguir;
}

int solicitarIdCliente()
{
    int idCliente; /// SOLICITAR ID CLIENTE
    printf("\n\t\t\t\t\tIngrese ID de cliente a buscar: ");
    scanf("%d", &idCliente);
    return idCliente;
}
void elBug()
{
    printf("\t\t\t\t ________________________________________________________\n");
    printf("\t\t\t\t|\t ______ _        ____  _    _  _____  \t\t|\n");
    printf("\t\t\t\t|\t |  ____| |      |  _ \ | |  | |/ ____|\t\t|\n");
    printf("\t\t\t\t|\t | |__  | |      | |_) | |  | | |  __\t\t|\n");
    printf("\t\t\t\t|\t |  __| | |      |  _ <| |  | | | |_ |\t\t|\n");
    printf("\t\t\t\t|\t | |____| |____  | |_) | |__| | |__| |\t\t|\n");
    printf("\t\t\t\t|\t |______|______| |____/ \_____/ ______|\t\t|\n");
    printf("\t\t\t\t|_______________________________________________________|\n");
    printf("\n\t\t\t\t =======================================================\n");
}

/// ESTO ES PARA VER EL ARCHIVO SIN NECESIDAD DE PASARLO AL ARBOL (SOLO DESCOMENTAR PARA TESTEAR) debugger
/*STRegistroCliente a;
FILE * fp=fopen("Clientes.bin", "rb");
if(fp){
    while(fread(&a, sizeof(STRegistroCliente), 1, fp)>0){
        printf("Barrio: %s \n", a.Barrio);
    }
}*/
void CrearFechaActual()
{
    // Tiempo actual
    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    // El lugar en donde se pondrá la fecha y hora formateadas
    char fechaHora[70];
    // El formato.
    char *formato = "%Y-%m-01";
    // Intentar formatear
    int bytesEscritos =
        strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
    if (bytesEscritos != 0)
    {
        // Si no hay error, los bytesEscritos no son 0
        printf("Fecha y hora: %s", fechaHora);
    }
    else
    {
        printf("Error formateando fecha");
    }
}
int validarNumero(char numero[])
{
    int flag=1;
    int i=0;
    int n;
    int menor=9;
    if (strlen(numero)<=menor)
    {
        while(i<strlen(numero)&&flag==1)
        {
            n=isdigit(numero[i]);
            if(n==0)
            {
                flag=-1;
            }
            i++;
        }
        if(flag==-1)
        {
            printf("\n\t\t\t\tSolo se aceptan digitos.\n");
        }
    }
    else
    {
        printf("\n\t\t\t\tDNI INVALIDO\n");
        flag=-1;
    }
    return flag;
}

int validartel(char numero[])
{
    int flag=1;
    int i=0;
    int n;
    int menor=13;
    if (strlen(numero)<=menor)
    {
        while(i<strlen(numero)&&flag==1)
        {
            n=isdigit(numero[i]);
            if(n==0)
            {
                flag=-1;
            }
            i++;
        }
        if(flag==-1)
        {
            printf("\n\t\t\t\tSolo se aceptan digitos.\n");
        }
    }
    else
    {
        printf("\n\t\t\t\tTelefono invalido\n");
        flag=-1;
    }
    return flag;
}

int validarPalabra(char palabra[])
{
    int flag=1;
    int i=0;
    int n;

    while(i<strlen(palabra)&&flag==1)
    {
        n=isalpha(palabra[i]);
        if(n==0)
        {
            flag=-1;
        }
        i++;
    }
    if(flag==-1)
    {
        printf("\n\t\t\t\tSolo se aceptan caracteres.\n");
    }
    return flag;
}


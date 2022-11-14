#include <stdio.h>
#include <string.h>
#include "Admin.h"

int ComprobarAdmin(char usuario[20], char contrasena[20])
{
    int flag = 0;
    if ((strcmpi(usuario, "admin") == 0) && (strcmpi(contrasena, "admin") == 0))
    {
        flag = 1;
    }
    return flag;
}

int ComprobarUsuario(arbolClientes *arbol, char usuario[20], char contrasena[20])
{
    int flag = 0;
    if ((strcmpi(usuario, arbol->Cliente.Login.id) == 0) && (strcmpi(contrasena, arbol->Cliente.Login.pass) == 0))
    {
        flag = 1;
    }
    else
    {
        printf("\nDatos ingresador incorrectos\n");
    }
    return flag;
}

int LoginDeUsuario(arbolClientes *Arbol)
{
    char DNI[8];
    char Contrasena[10];
    int id=-1;
    arbolClientes *buscado=inicArbol();
    elBug();
    printf("\n\t\t\t\t\tIngrese su DNI:    ");
    fflush(stdin);
    scanf("%s", &DNI);
    printf("\t\t\t\t\tIngrese su password:    ");
    fflush(stdin);
    scanf("%s", &Contrasena);
    id=buscarIdArchivo("Clientes.bin", DNI);
    if(id!=-1)
    {
        buscado=buscarNodoClientePorDNI(Arbol, DNI, id);
        mostrarNodoArbol(buscado);
        system("pause");
        if (buscado)
        {
            if((strcmpi(Contrasena, buscado->Cliente.Login.pass)== 0) && (strcmpi(DNI, buscado->Cliente.Dato.DNI) == 0))
            {
                id=1;
            }
        }
    }
    return id;
}

void menuAdministrador(arbolClientes *arbol)
{
    char user[20];
    char password[20];
    char seguir = 0;

    while (seguir != 27)
    {
        elBug();
        printf("\n\t\t\t\t\tUn gusto verlo nuevamente Sr. Wayne\n");
        printf("\t\t\t\t\tBienvenido al bug.\n");
        printf("\t\t\t\t\tIngrese el nombre de usuario: ");
        fflush(stdin);
        gets(user);
        printf("\t\t\t\t\tIngrese la password: ");
        fflush(stdin);
        gets(password);
        if (ComprobarAdmin(user, password) == 1)
        {
            system("cls");
            funcionesAdministrador(arbol);
            seguir = 27;
        }
        else
        {
            printf("\n\t\t\t\tLos datos ingresados son invalidos. ");
            seguir = confirmacionBucle();
        }
        system("cls");
    }
}

void funcionesAdministrador(arbolClientes *arbol)
{
    int flag = 0;
    int opcion;
    int cable;
    int internet;
    int idCliente;
    arbolClientes *buscado;
    do
    {
        elBug();
        printf("\t\t\t\t\tIngrese la opcion que desea realizar.\n");
        printf("\t\t\t\t\t1. Mostrar clientes.\n");
        printf("\t\t\t\t\t2. Buscar cliente: \n");
        printf("\t\t\t\t\t3. Finalizar sesion.\n");
        printf("\t\t\t\t\tIngrese su opcion aqui: ");
        scanf("%i", &opcion);
        switch (opcion)
        {
        case 1:
            mostrarArbol(arbol);
            system("pause");
            system("cls");
            break;
        case 2:
            idCliente = solicitarIdCliente();
            buscado = buscarNodoCliente(arbol, idCliente);
            {
                if (buscado)
                {
                    system("cls");
                    elBug();
                    mostrarNodoArbol(buscado);
                    MostrarTodasLasFacturasDeUnCliente(buscado->Factura);
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("\nCliente no encontrado.\n");
                }
            }
            break;
        default:
            printf("\nHasta luego\n");
            break;
        }
    }
    while (opcion != 3);
}

int buscarIdArchivo(char archivo[], char DNI[])
{
    FILE *fp=fopen(archivo,"rb");
    STRegistroCliente aux;
    int id=-1;
    if(fp)
    {
        while(fread(&aux, sizeof(STRegistroCliente), 1, fp)>0)
        {
            if(strcmpi(aux.DNI, DNI)==0)
            {
                id=aux.id;
            }
        }
        fclose(fp);
    }

    return id;
}

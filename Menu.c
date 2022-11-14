#include <string.h>
#include "Menu.h"
arbolClientes *Menu(arbolClientes *arbolPrincipal)
{
    int numerillo = 1;
    int opcion = 1;
    char seguir='s';
    int flag=0;
    int ID;
    int opcionCliente;
    STRegistroCliente aux;
    arbolClientes *Cliente = inicArbol();
    do
    {
        elBug();
        printf("\n\t\t\t\t\t\t     Bienvenido.\n\n\t\t\t\t Ingrese alguna de las siguientes opciones para operar.\n");
        printf("\t\t\t\t 1. Ingresar al panel de Usuario.\n");
        printf("\t\t\t\t 2. Ingresar como administrador (PERSONAL AUTORIZADO).\n");
        printf("\t\t\t\t 3. Crear un nuevo usuario y contratar el servicio.\n");
        printf("\n\t\t\t\t Ingrese su opcion: ");
        scanf("%i", &opcion);
        system("cls");
        seguir='s';
        ID = -1;
        switch (opcion)
        {
        case 1:
            ID = LoginDeUsuario(arbolPrincipal);
            if (ID != -1)
            {
                Cliente = buscarNodoCliente(arbolPrincipal, ID);
                do
                {
                    system("cls");
                    elBug();
                    printf("\n\t\t\t\t\t 1. Para ver sus datos.\n");
                    printf("\n\t\t\t\t\t 2. Para ver las facturas.\n");
                    printf("\n\t\t\t\t\t 3. Para modificar datos personales.\n");
                    printf("\n\t\t\t\t\t 4. Para dar la baja de los servicios.\n");
                    printf("\n\t\t\t\t\t 5. Salir.\n");
                    scanf("%i", &opcionCliente);

                    switch (opcionCliente)
                    {
                    case 1:
                        system("cls");
                        elBug();
                        mostrarDatosdeClienteXID(ID, arbolPrincipal);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        elBug();
                        MostrarTodasLasFacturasDeUnCliente(Cliente->Factura);
                        printf("\n\n");
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        elBug();
                        Cliente = modificarDatosPersonalesCliente(Cliente);
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        elBug();
                        DarmeLaBaja(Cliente->Cliente);
                        aux=crearRegistroCliente(Cliente);
                        persistirRegistroModificado("Clientes.bin", aux);
                        arbolPrincipal = borrarCliente(arbolPrincipal, Cliente->Cliente.Dato.id);
                        system("pause");
                        break;
                    }


                }
                while(opcionCliente>0 && opcionCliente<5);
            }
            else
            {
                printf("\n\t\t\t\tLos datos ingresados son invalidos. ");
                seguir=confirmacionBucle();
            }
            break;
        case 2:
            menuAdministrador(arbolPrincipal);
            break;
        case 3:
            elBug();
            printf("\t\t\t\tBienvenido, te deseamos que tengas la mejor \n\t\t\t\texperiencia con nuestro servicios.\n\n");
            printf("\t\t\t\tA continuacion se te ofreceran nuestros servicios y planes para\n\t\t\t\tque puedas solicitar el que desees. Al finalizar requeriremos de sus datos\n\t\t\t\tpersonales para poder realizar la instalacion pertinente.\n\n\n");
            system("pause");
            system("cls");
            elBug();
            STCliente nuevoCliente = CargarUnCliente();
            arbolClientes *Nuevo = crearNodoArbol(nuevoCliente);
            persistirNuevoNodo(Nuevo, "Clientes.bin");
            arbolPrincipal = agregarNodoArbol(arbolPrincipal, Nuevo);
            break;
        default:
            printf("\nOpcion invalida\n");
            seguir = confirmacionBucle();
            numerillo = 1;
            break;
        }
        system("cls");
        elBug();
        printf("\n\t\t\t\t\tIngrese 0 para salir del programa. \n\t\t\t\t\tIngrese 1 para volver al menu de inicio\n");
        scanf("%i", &numerillo);
        system("cls");
    }
    while (numerillo = 1);
    return arbolPrincipal;
}

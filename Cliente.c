#include <string.h>
#include "Clientes.h"

/// MODIFICAR CLIENTES
void modificarNombre(char nombre[])
{
    char nom[30];
    do{
        printf("HOLA!\n");
        printf("\n\t\t\t\tIngrese nombre: ");
        fflush(stdin);
        scanf("%s", nom);
    }while(validarPalabra(nom)==-1);
    strcpy(nombre, nom);

}

void modificarApellido(char apellido[])
{
    char ape[30];
    do{
        printf("\n\t\t\t\tIngrese el apellido: ");
        fflush(stdin);
        scanf("%s", ape);
    }while(validarPalabra(ape)==-1);

    strcpy(apellido, ape);
}

void modificarTelefono(char telefono[])
{
    char tel[20];
    do{
        printf("\n\t\t\t\tIngrese el telefono: ");
        fflush(stdin);
        scanf("%s", tel);
    }while(validarNumero(tel)==-1);

    strcpy(telefono, tel);
}

void modificarBarrio(char barrio[])
{
    char ba[20];
    do{
        printf("\n\t\t\t\tIngrese el barrio: ");
        fflush(stdin);
        scanf("%s", ba);
    }while(validarPalabra(ba)==-1);

    strcpy(barrio, ba);
}
void modificarDireccion(char direccion[])
{
    char dir[20];
    printf("\n\t\t\t\tIngrese su direccion. Calle y altura: ");
    fflush(stdin);
    scanf("%s", dir);
    strcpy(direccion, dir);
}

void cambiarPassword(char password[])
{
    char pass[8];
    printf("\n\t\t\t\tIngrese la nueva password: ");
    fflush(stdin);
    scanf("%s", pass);
    strcpy(password, pass);
}

/// === CARGA CLIENTE MANUAL
STCliente CargarUnCliente()
{
    STCliente ClienteNuevo;
    if (retornaUltimoId != -1)
    {
        ClienteNuevo.Dato = cargaDatosPersonales();
        ClienteNuevo.Login = cargaLogin(ClienteNuevo.Dato);
        ClienteNuevo.Servicio = CargaServicio();
        MostrarUncliente(ClienteNuevo);
        system("pause");
    }
    else
    {
        printf("\n\t\t\t\tEl cliente no se pudo crear.");
    }

    return ClienteNuevo;
}

STPersonal cargaDatosPersonales()
{
    STPersonal dato;
    int flag;
    do{
        printf("\n\t\t\t\tIngrese el DNI:  ");
        fflush(stdin);
        scanf("%s", dato.DNI);
        flag=validarNumero(dato.DNI);
    }while(flag==-1);

    modificarNombre(dato.Nombre);
    modificarApellido(dato.Apellido);
    modificarTelefono(dato.NumeroCel);
    dato.id = retornaUltimoId("Clientes.bin");
    modificarBarrio(dato.direccion.Barrio);
    modificarDireccion(dato.direccion.Direccion);
    return dato;
}

STLogin cargaLogin(STPersonal cliente)
{
    char password[10];
    STLogin login;
    login.id = cliente.id;
    printf("\t\t\t\tIngrese la contrasena (MAX 10 Caracteres); \n");
    printf("\t\t\t\t");
    fflush(stdin);
    scanf("%s", password);
    strcpy(login.pass, password);
    return login;
}



STServicio CargaServicio()
{
    STServicio Servicio;
    int flagInternet = 0, flagCable = 0, flagCombo = 0, flagNuevo = 0, Seleccion = -1, FlagInternet2 = 0, FlagflagCable2 = 0, FlagCombo2 = 0, flagMenu = 0;

        printf("\n\t\t\t\tSelecione el servicio que desea contratar: \n");
        printf("\n\t\t\t\t1. Internet           - $1000.\n");
        printf("\n\t\t\t\t2. Cable              - $600.\n");
        printf("\n\t\t\t\t3. Internet + Cable   - $1300.\n");
        Seleccion = -1;
        scanf("%i", &Seleccion);
        switch (Seleccion)
        {
        case 1:
            if (flagInternet == 0)
            {
                printf("\n\t\t\t\tEl servicio de Internet ha sido dado de alta.\n\t\t\t\tEn breve nos comunicaremos coordinar la instalacion");
                Servicio.Internet = 1;
                flagInternet = 1;
            }
            else
            {
                printf("Usted tiene activo el servicio de Internet, desea darlo de bajo?\n Seleccione 1 para dalo de baja\n Seleccione 2 para salir\n");
                scanf("%i", &FlagInternet2);
                if (FlagInternet2 == 1)
                {
                    Servicio.Internet = 0;
                }
            }
            break;
        case 2:
            if (flagCable == 0)
            {
                printf("\n\t\t\t\tEl servicio de Cable ha sido dado de alta.\n\t\t\t\tEn breve nos comunicaremos coordinar la instalacion");
                Servicio.Cable = 1;
                flagCable = 1;
            }
            else
            {
                printf("\n\t\t\t\tUsted tiene activo el servicio de cable, desea darlo de bajo?\n\t\t\t\tSeleccione 1 para dalo de baja\n\t\t\t\tSeleccione 2 para salir\n");
                scanf("%i", &FlagflagCable2);
                if (FlagflagCable2 == 1)
                {
                    Servicio.Cable = 0;
                }
            }
            break;
        case 3:
            if (flagCombo == 0)
            {
                printf("\n\t\t\t\tEl servicios de Internet y Cable ha sido dado de alta.\n\t\t\t\tEn breve nos comunicaremos coordinar la instalacion");
                Servicio.Cable = 1;
                Servicio.Internet = 1;
                flagCombo = 1;
            }
            else
            {
                printf("\n\t\t\t\tUsted tiene activo el servicio de internet mas cable, desea darlo de bajo?\n\t\t\t\tSeleccione 1 para dalo de baja\n\t\t\t\tSeleccione 2 para salir\n");
                scanf("%i", &FlagCombo2);
                if (FlagCombo2 == 1)
                {
                    Servicio.Internet = 0;
                    Servicio.Cable = 0;
                }
            }
            break;
        case 4:

            printf("\n\t\t\t\tSu usuario quedo registrado, cuando guste podra ingresar nuevamente a nuestra pagina y contratar el servicio deseado \n");
            system("pause");
            flagNuevo = 1;
            break;
        default:
            printf("\nSeleccion invalida\n");
            break;
        }

    return Servicio;
}

int PedidoBin(char corte)
{
    int servicio = 0;
    if (strcmpi(corte, "s") == 0)
    {
        servicio = 1;
    }
    return servicio;
}

STCliente registroToSTCLiente(STRegistroCliente p)
{
    STCliente nuevo;
    nuevo.Login.id = p.id;
    nuevo.Dato.id = p.id;
    strcpy(nuevo.Login.pass, p.pass);
    strcpy(nuevo.Dato.DNI, p.DNI);
    strcpy(nuevo.Dato.Nombre, p.Nombre);
    strcpy(nuevo.Dato.Apellido, p.Apellido);
    strcpy(nuevo.Dato.NumeroCel, p.NumeroCel);
    strcpy(nuevo.Dato.direccion.Direccion, p.Direccion);
    strcpy(nuevo.Dato.direccion.Barrio, p.Barrio);
    nuevo.Servicio.Cable = p.Cable;
    nuevo.Servicio.Internet = p.Internet;

    return nuevo;
}

int retornaUltimoId(char archivo[])
{
    int ultimoId = -1;
    STRegistroCliente a;
    FILE *fp = fopen(archivo, "rb");
    if (fp)
    {
        fseek(fp, (-1) * sizeof(STRegistroCliente), SEEK_END);
        fread(&a, sizeof(STRegistroCliente), 1, fp);
        ultimoId = a.id + 1;
    }
    return ultimoId;
}

/// ESTABA EN RANDOM.C
STRegistroCliente crearRegistroRand(int id, char archivo[])
{
    STRegistroCliente a;
    a.id = id;
    nombreRandom(a.Nombre);
    apellidoRandom(a.Apellido);
    movilRandom(a.NumeroCel);
    domicilioRandom(a.Direccion);
    barrioRandom(a.Barrio);
    strcpy(a.pass, "password");
    a.Cable = cableRandom();
    a.Internet = internetRandom();
    while (a.Cable == 0 && a.Internet == 0) // Evita tener clientes inactivos.
    {
        a.Cable = cableRandom();
        a.Internet = internetRandom(); // Hay que modificar para que tome el servicio en conjunto y no por separado(cable e internet));
    }
    dniRandom(a.DNI);
    while (funcionComprobarDNI(a.DNI, archivo) == 1)
    {
        dniRandom(a.DNI);
    }
    return a;
}




void generarArchivoRandom(char archivo[])
{
    FILE *fp = fopen(archivo, "wb");
    int i = 1;
    STRegistroCliente a;
    if (fp)
    {
        while (i < 5001)
        {
            a = crearRegistroRand(i, archivo);
            fwrite(&a, sizeof(STRegistroCliente), 1, fp);
            i++;
        }
        fclose(fp);
    }
}

/// Mostrar CLiente
void MostrarUncliente(STCliente aux)
{
    printf("\t\t\t\t\tID: %i\n", aux.Dato.id);
    printf("\t\t\t\t\tNombre: %s\n", aux.Dato.Nombre);
    printf("\t\t\t\t\tApellido: %s\n", aux.Dato.Apellido);
    printf("\t\t\t\t\tDireccion: %s\n", aux.Dato.direccion.Direccion);
    printf("\t\t\t\t\tBarrio: %s\n", aux.Dato.direccion.Barrio);
    printf("\t\t\t\t\tDNI: %s\n", aux.Dato.DNI);

    printf("\t\t\t\t\tDNI: %i\n", aux.Servicio.Cable);
    printf("\t\t\t\t\tDNI: %i\n", aux.Servicio.Internet);

    printf("\t\t\t\t\tNumero de contacto: %s\n", aux.Dato.NumeroCel);
    printf("\t\t\t\t\t=============================\n");
}

/// Comprobar estado del cliente
STCliente DarmeLaBaja(STCliente aux)
{
    aux.Servicio.Cable = 0;
    aux.Servicio.Internet = 0;
    printf("\n Usted fue dado de baja \n");
    return aux;
}

int EstadoClienteServicios(STCliente Aux)
{
    int flag = 0;
    if (Aux.Servicio.Cable == 1 || Aux.Servicio.Internet == 1)
    {
        flag = 1;
    }
    return flag;
}
int funcionComprobarDNI(char dni[], char archivo[])
{
    FILE *fp = fopen(archivo, "rb");
    int flag = 0;
    STRegistroCliente a;
    if (fp)
    {
        while (fread(&a, sizeof(STRegistroCliente), 1, fp) > 0 && flag == 0)
        {
            if (strcmpi(a.DNI, dni) == 0)
            {
                flag = 1; /// El dni ya está en uso.
            }
        }
        fclose(fp);
    }
    return flag;
}

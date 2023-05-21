#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define AÑO_ACTUAL
#define MAX_MOVIMIENTOS 100

struct movimientoBanco {
    char fecha[50];
    float monto;
};

struct movimientoCliente {
    char fecha[50];
    float monto;
};

struct movimientoBanco movimientosBanco[MAX_MOVIMIENTOS];
int totalMovimientosBanco = 0;

struct movimientoCliente movimientosCliente[MAX_MOVIMIENTOS];
int totalMovimientosCliente = 0;

struct cuentasBancarias
{
    /* Base */

    char nombre[50];
    char genero[50];
    int fechaNacimiento;
    int cedula;

    /* expediente */
    char direccion[50];
    char correo[50];
    char estatusCivil[50];
    char telefono[50];
    float patrimonio;
};
struct cuentasBancarias cuenta;

void CuentaCliente();
void ExpedienteDelCliente();
void productosRequisitos();
void CuentaCliente();
void ExpedienteDelCliente();
void menuPagos();
void pagos(float monto);

int main()
{
    cuenta.fechaNacimiento = 9999;
    /*
    Menu de nuestro programa, esta compuesto por un ciclo do-while que permitira
    poder usar todo el programa sin la necesidad de volver a iniciarlo y una seleccion
    de tipo switch para poder ejecutar las proximas funciones de nuestro programa que
    por ahora solo tiene un printf que sera proximamente remplazado por nuestras funcionesLMEM
    */

    int opcionMenu = 0;
    do
    {
        if (cuenta.fechaNacimiento > 2005)
        {
            printf("\nBienvenido al sistema de BanLMEM:]\n");
            printf("\n--MENU--");
            printf("\n1. Cuenta Cliente.");
            printf("\n2. Salir del Sistema.\n");
            printf("\nIngrese una opcion: ");
            scanf("%i", &opcionMenu);
            system("cls");

            switch (opcionMenu)
            {
            case 1:
                CuentaCliente();
                break;
            case 2:
                printf("\nMuchas gracias por usar nuestros servicios\n");
                break;
            default:
                printf("\nOpcion invalida\n");
            }
        }
        else
        {
            printf("\nBienvenido al sistema de BanLMEM:]\n");
            printf("\n--MENU--");
            printf("\n1. Cuenta Cliente.");
            printf("\n2. Expediente Cliente."); /*  */
            printf("\n3. Productos y Requisitos.");
            printf("\n4. Resumen de Actividad.");
            printf("\n5. Cobros por Servicios.");
            printf("\n6. Pagos.");
            printf("\n7. Retiros.");
            printf("\n8. Movimientos.");
            printf("\n9. Salir del Sistema.\n");
            printf("\nIngrese una opcion: ");
            scanf("%i", &opcionMenu);
            system("cls");

            switch (opcionMenu)
            {
            case 1:
                CuentaCliente();
                break;
            case 2:
                ExpedienteDelCliente();
                break;

            case 3:
                productosRequisitos();
                break;

            case 4:
                resumenActividad();
                break;

            case 5:
                printf("\n5ta Opcion");
                break;

            case 6:
                menuPagos();
                break;

            case 7:
                printf("\n7ma Opcion");
                break;

            case 8:
               consultarImprimirMovimientos();
                break;
            case 9:
                printf("\nMuchas gracias por usar nuestros servicios...");
                break;
            default:
                printf("\nLa opcion que introduzco no es valida, intentelo de nuevo.");
                break;
            }
        }
    } while (opcionMenu < 9);

    return 0;
}

void CuentaCliente()
{
    int opcionMenuCuentaCliente = 0;

    do
    {
        printf("\n--Menu Cliente--\n");
        printf("\n1.1 Crearla");
        printf("\n1.2 Consultarla e imprimirla");
        printf("\n1.3 Salir\n");
        printf("\nPor favor ingrese una opcion: ");
        scanf("%i", &opcionMenuCuentaCliente);
        system("cls");
        switch (opcionMenuCuentaCliente)
        {
        case 1:
            printf("\n--Creacion de usuario--\n");
            printf("\nPor favor ingrese su cedula: ");
            scanf("%i", &cuenta.cedula);
            printf("\nPor favor ingrese su nombre: ");
            scanf("%s", &cuenta.nombre);
            printf("\nPor favor ingrese su fecha de nacimiento: ");
            scanf("%i", &cuenta.fechaNacimiento);
            if (cuenta.fechaNacimiento > 2004)
            {
                printf("\nFallo en la creacion de la cuenta, usted deber ser mayor de edad\n");
                cuenta.fechaNacimiento = 9999;
                limpiarPausarConsola();
                break;
            }
            printf("\nCuenta creada exitosamente!\n");
            limpiarPausarConsola();
            break;
        case 2:
            if (cuenta.fechaNacimiento < 2005)
            {
                printf("\n--Consulta--\n");
                printf("Cedula: %i\n", cuenta.cedula);
                printf("Nombre: %s\n", cuenta.nombre);
                printf("Año de nacimiento: %i\n", cuenta.fechaNacimiento);
                limpiarPausarConsola();
                break;
            }
            else
            {
                printf("\nNo hay cliente registrado\n");
                limpiarPausarConsola();
            }
        case 3:
            system("cls");
            break;
        default:
            printf("Opcion Invalida");
            break;
        }
    } while (opcionMenuCuentaCliente != 3);
}

void ExpedienteDelCliente()
{
    int opcionMenuCuentaCliente = 0;
    do
    {
        printf("\n--Menu Cliente (Expediente)--\n");
        printf("\n1.1 Crear expediente");
        printf("\n1.2 Consultarla e imprimir expediente");
        printf("\n1.3 salir\n");
        printf("\nPor favor ingrese una opcion: ");
        scanf("%i", &opcionMenuCuentaCliente);
        system("cls");

        switch (opcionMenuCuentaCliente)
        {
        case 1:
            printf("\n--Creacion de expediente del usuario--\n");
            printf("\nPor favor, ingrese su direccion: ");
            scanf("%s", &cuenta.direccion);
            printf("\nPor favor, ingrese su correo electronico: ");
            scanf("%s", &cuenta.correo);
            printf("\nPor favor, ingrese su numero telefonico: ");
            scanf("%s", &cuenta.telefono);
            printf("\nPor favor, ingrese su estatus civil: ");
            scanf("%s", &cuenta.estatusCivil);
            printf("\nPor favor, la cantidad inicial de dinero a agendar a su cuenta: ");
            scanf("%f", &cuenta.patrimonio);
            printf("\nExpediente creado con exito!");
            limpiarPausarConsola();
            break;
        case 2:
            printf("\n--Consulta del expediente--\n");
            printf("Direccion: %s\n", cuenta.direccion);
            printf("Correo electronico: %s\n", cuenta.correo);
            printf("Numero telefonico: %s\n", cuenta.telefono);
            printf("Estatus civil: %s\n", cuenta.estatusCivil);
            printf("Fondo inicial agregado:%.2fBs\n", cuenta.patrimonio);
            limpiarPausarConsola();
            break;
        case 3:
            printf("\nSaliendo...");
            limpiarPausarConsola();
            break;
        default:
            printf("\nOpcion Invalida");
            limpiarPausarConsola();
            break;
        }
    } while (opcionMenuCuentaCliente != 3);
}

void productosRequisitos()
{
    printf("\nProductos que ofrecemos en BanLMEM:].\n");

    printf("\nPERSONA NATURAL");
    printf("\nProductos:");
    printf("\n -Cuenta Corriente no remunerada.");
    printf("\n -Tarjeta de Debito.");
    printf("\n -Sistema en linea.\n");
    printf("\nRequisitos:");
    printf("\n -Mayoria de edad.");
    printf("\n -Documento de identidad.");
    printf("\n -Datos personales.");
    printf("\n -Patrimonio minimo de x.\n");

    printf("\nPERSONA JURIDICA");
    printf("\nProductos:");
    printf("\n -Cuenta juridica corriente y Cuenta de moneda extranjera.");
    printf("\n -Tarjeta de Debito y Credito.");
    printf("\n -Tazas de interes minimas.");
    printf("\n -Credito Comercial.");
    printf("\n -Pago a proveedores.");
    printf("\n -Pago de nominas.\n");
    printf("\nRequisitos:");
    printf("\n -Apertura de cuenta en oficinas fisicas.");
    printf("\n -Copia de documentos de identidad de los representantes de la empresa.");
    printf("\n -Registro de informacion fiscal (RIF).");
    printf("\n -Balance del ultimo cierre economico de la empresa.");
    printf("\n -Copia del documento constitutivo de la empresa.\n");
    limpiarPausarConsola();
}

void resumenActividad()
{
    int resumenDeActividad = 0;

    do
    {
        printf("\n__RESUMEN DE ACTIVIDAD BANCARIA__\n");
        printf("\n1.1 Resumen Semanal.");
        printf("\n1.2 Resumen Mensual.");
        printf("\n1.3 Volver al menu principal.\n");
        printf("\nPor favor ingrese una opcion: ");
        scanf("%i", &resumenDeActividad);
        system("cls");

        switch (resumenDeActividad)
        {

        case 1:
            printf("\n__RESUMEN SEMANAL__\n");
            printf("\n_[22/05/2023] al [28/05/2023]\n");

            printf("\n[25/05/2003] Creacion de Expediente Cliente: C.I: %i.", cuenta.cedula);
            printf("\n[25/05/2003] Creacion de Cuenta Cliente: C.I: %i.\n", cuenta.cedula);
            printf("\n[23/05/2003] Creacion de Expediente Cliente: C.I: 6359458.\n");
            printf("\n[22/05/2003] Creacion de Cuenta Cliente: C.I: 6359458.");
            printf("\n[22/05/2003] Solicitud de Tarjeta de Debito: C.I: 12698364.");
            limpiarPausarConsola();
            break;

        case 2:
            printf("\n__RESUMEN MENSUAL__");
            printf("\n_[01/05/2023] al [31/05/2023]\n");

            printf("\n_SEMANA [22/05/2023] a [28/05/2023]");
            printf("\n[25/05/2003] Creacion de Expediente Cliente: C.I: %i.", cuenta.cedula);
            printf("\n[25/05/2003] Creacion de Cuenta Cliente: C.I: %i.", cuenta.cedula);
            printf("\n[23/05/2003] Creacion de Expediente Cliente: C.I: 6359458.");
            printf("\n[22/05/2003] Creacion de Cuenta Cliente: C.I: 6359458.");
            printf("\n[22/05/2003] Solicitud de Tarjeta de Debito: C.I: 12698364.\n");

            printf("\n_SEMANA [15/05/2023] a 21/05/2023]");
            printf("\n[19/05/2003] Creacion de Cuenta Juridica: R.I.F: 0036841287.");
            printf("\n[19/05/2003] Cierre de Cuenta Cliente: C.I: 18659354.");
            printf("\n[18/05/2003] Creacion de Expediente Cliente: C.I: 17458514.");
            printf("\n[16/05/2003] Creacion de Cuenta Cliente: C.I: 20178348.");
            printf("\n[15/05/2003] Creacion de Cuenta Cliente: C.I: 17458514.");
            printf("\n[15/05/2003] Creacion de Cuenta Cliente: C.I: 18659354.\n");

            printf("\n_SEMANA [08/05/2023] a [14/05/2023]");
            printf("\n[13/05/2003] Creacion de Expediente Cliente: R.I.F: 11697364.");
            printf("\n[13/05/2003] Cierre de Cuenta Cliente: C.I: 28458731.");
            printf("\n[12/05/2003] Creacion de Expediente Cliente: C.I: 22489123.");

            printf("\n_SEMANA [01/05/2023] a [07/05/2023]");
            printf("\n[07/05/2003] Creacion de Expediente Juridico: R.I.F: 0254003964.");
            printf("\n[05/05/2003] Creacion de Cuenta Cliente: C.I: 22489123.");
            printf("\n[04/05/2003] Creacion de Cuenta Juridica: R.I.F: 0254003964.");
            printf("\n[04/05/2003] Creacion de Cuenta Cliente: C.I: 11697364.");
            limpiarPausarConsola();
            break;

        case 3:
            system("cls");
            break;

        default:
            printf("\nOpcion Invalida");
            limpiarPausarConsola();
            break;
        }

    } while (resumenDeActividad != 3);
}

void menuPagos()
{
    int opcionMenuPagos;
    float monto;
    do
    {

        printf("\n--Menu de Pagos--\n");
        printf("\n1. Pago Movil");
        printf("\n2. Transferencia");
        printf("\n3. Pago en Efectivo");
        printf("\n4. Salir\n");
        printf("\nDinero: %.2f\nBsf", cuenta.patrimonio);
        printf("\nIngrese una opcion: ");
        scanf("%i", &opcionMenuPagos);
        system("cls");

        switch (opcionMenuPagos)
        {
        case 1:
            printf("\nIngrese el monto del pago en bolivares: ");
            scanf("%f", &monto);
            pagos(monto);
            limpiarPausarConsola();
            break;
        case 2:
            printf("\nIngrese el monto de la transferencia en bolivares: ");
            scanf("%f", &monto);
            pagos(monto);
            limpiarPausarConsola();
            break;
        case 3:
            printf("\nIngrese el monto del pago en efectivo en bolivares: ");
            scanf("%f", &monto);
            cuenta.patrimonio += monto;
            printf("\nEfectivo ingresado correctamente!\n");
            limpiarPausarConsola();
            break;
        case 4:
            system("cls");
            break;
        default:
            printf("\nOpcion Invalida");
            limpiarPausarConsola();
            break;
        }
    } while (opcionMenuPagos != 4);
}

void pagos(float monto)
{
    if (monto > cuenta.patrimonio)
    {
        printf("\nMonto insuficiente para realizar dicho pago\n");
    }
    else
    {
        cuenta.patrimonio -= monto;
        printf("\nPago realizado con exito!\n");
          sprintf(movimientosBanco[totalMovimientosBanco].fecha, "Fecha actual"); // Reemplazar "Fecha actual" con la fecha actual en el formato deseado
        movimientosBanco[totalMovimientosBanco].monto = monto;
        totalMovimientosBanco++;

        // Agregar movimiento a la cuenta del cliente
        sprintf(movimientosCliente[totalMovimientosCliente].fecha, "Fecha actual"); // Reemplazar "Fecha actual" con la fecha actual en el formato deseado
        movimientosCliente[totalMovimientosCliente].monto = monto;
        totalMovimientosCliente++;
    }
}

void consultarImprimirMovimientos() {
    int opcion;

    printf("\n---- Menu de Consulta de Movimientos ----\n");
    printf("1. Movimientos del banco\n");
    printf("2. Movimientos de la cuenta del cliente\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("\n--Consulta e impresion de movimientos del banco--\n");
            for (int i = 0; i < totalMovimientosBanco; i++) {
                printf("Fecha: %s, Monto: %.2f\n", movimientosBanco[i].fecha, movimientosBanco[i].monto);
            }
            break;
        case 2:
            printf("\n--Consulta e impresion de movimientos de la cuenta del cliente--\n");
            for (int i = 0; i < totalMovimientosCliente; i++) {
                printf("Fecha: %s, Monto: %.2f\n", movimientosCliente[i].fecha, movimientosCliente[i].monto);
            }
            break;
        default:
            printf("Opcion invalida\n");
    }
}


void limpiarPausarConsola()
{
    system("pause");
    system("cls");
}

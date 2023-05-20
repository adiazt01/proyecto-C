#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

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
void CuentaCliente(void);
void menuPagos(struct cuentasBancarias* cuenta);
void pagos(struct cuentasBancarias* cuenta, float monto, bool esDolar);

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
                printf("\n4ta Opcion");
                break;

            case 5:
                printf("\n5ta Opcion");
                break;

            case 6:
                printf("\n6ta Opcion");
                break;

            case 7:
                printf("\n7ma Opcion");
                break;

            case 8:
                printf("\n8va Opcion");
                break;

            case 9:
                printf("\nSalir");
                break;

            default:
                printf("\nLa opcion que introduzco no es valida, intentelo de nuevo.");
                break;
            }
        }
    } while (opcionMenu < 9);

    return 0;
}

void CuentaCliente(void)
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
                break;
            }
            break;
        case 2:
        if (cuenta.fechaNacimiento < 2005)
        {
            printf("\n--Consulta--\n");
            printf("Cedula: %i\n", cuenta.cedula);
            printf("Nombre: %s\n", cuenta.nombre);
            printf("Año de nacimiento: %i\n", cuenta.fechaNacimiento);
            break;
        }
        else{
            printf("\nNo hay cliente registrado\n");
        }
        case 3:
            printf("\nSaliendo...");
            break;
        default:
            printf("Opcion Invalida");
            break;
        }
    } while (opcionMenuCuentaCliente != 3);
}


void ExpedienteDelCliente()
{
    /* Variables temporales */
    int opcionMenuCuentaCliente = 0;
    struct cuentasBancarias cuenta;

    do
    {
        printf("\n--Menu Cliente (Expediente)--\n");
        printf("\n1.1 Crear expediente");
        printf("\n1.2 Consultarla e imprimir expediente");
        printf("\n1.3 salir\n");
        printf("\nPor favor ingrese una opcion: ");
        scanf("%i", &opcionMenuCuentaCliente);

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
            break;
        case 2:
            printf("\n--Consulta del expediente--\n");
            printf("Direccion: %s\n", cuenta.direccion);
            printf("Correo electronico: %s\n", cuenta.correo);
            printf("Numero telefonico: %s\n", cuenta.telefono);
            printf("Estatus civil: %s\n", cuenta.estatusCivil);
            printf("Fondo inicial agregado:%.2fBs\n", cuenta.patrimonio);
            break;
        case 3:
            printf("\nSaliendo...");
            break;
        default:
            printf("\nOpcion Invalida");
            break;
        }
    } while (opcionMenuCuentaCliente !=3);
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

            break;
        
        case 3:
            printf("\nSaliendo...");
            break;
        
        default:
            printf("\nOpcion Invalida");
            break;
        }
    
    }   while (resumenDeActividad !=3);
}

void menuPagos(struct cuentasBancarias* cuenta)
{
    int opcionMenuPagos = 0;
    float monto = 0.0;

    printf("\n--Menu de Pagos--\n");
    printf("\n1. Pago Movil (Bolivares)");
    printf("\n2. Pago Movil (Dolares)");
    printf("\n3. Transferencia (Bolivares)");
    printf("\n4. Transferencia (Dolares)");
    printf("\n5. Pago en Efectivo (Bolivares)");
    printf("\n6. Pago en Efectivo (Dolares)");
    printf("\nIngrese una opcion: ");
    scanf("%i", &opcionMenuPagos);

    switch (opcionMenuPagos)
    {
        case 1:
            printf("\nIngrese el monto del pago en bolivares: ");
            scanf("%f", &monto);
            pagos(cuenta, monto, false);
            break;
        case 2:
            printf("\nIngrese el monto del pago en dolares: ");
            scanf("%f", &monto);
            pagos(cuenta, monto, true);
            break;
        case 3:
            printf("\nIngrese el monto de la transferencia en bolivares: ");
            scanf("%f", &monto);
            pagos(cuenta, monto, false);
            break;
        case 4:
            printf("\nIngrese el monto de la transferencia en dolares: ");
            scanf("%f", &monto);
            pagos(cuenta, monto, true);
            break;
        case 5:
            printf("\nIngrese el monto del pago en efectivo en bolivares: ");
            scanf("%f", &monto);
            pagos(cuenta, monto, false);
            break;
        case 6:
            printf("\nIngrese el monto del pago en efectivo en dolares: ");
            scanf("%f", &monto);
            pagos(cuenta, monto, true);
            break;
        default:
            printf("\nOpcion Invalida");
            break;
    }
}

void pagos(struct cuentasBancarias* cuenta, float monto, bool esDolar)
{
    // Verificar si el saldo es suficiente para el pago
    if (esDolar)
    {
        if (monto > cuenta->patrimonio[0])
        {
            printf("\nSaldo insuficiente para el pago en dolares.");
            return;
        }
    }
    else
    {
        if (monto > cuenta->patrimonio[0])
        {
            printf("\nSaldo insuficiente para el pago en bolivares.");
            return;
        }
    }

    // Realizar el descuento del dinero
    if (esDolar)
    {
        cuenta->patrimonio[0] -= monto;
        printf("\nPago realizado en dolares: -$%.2f", monto);
    }
    else
    {
        cuenta->patrimonio[0] -= monto;
        printf("\nPago realizado en bolivares: -Bs%.2f", monto);
    }

    printf("\nTransferencia realizada correctamente.");
}

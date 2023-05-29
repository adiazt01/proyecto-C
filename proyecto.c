#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_MOVIMIENTOS 100

struct cuentasBancarias
{
    /* Base */

    char nombre[50];
    char apellido[50];
    char genero[50];
    int diaNacimiento;
    int mesNacimiento;
    int fechaNacimiento;
    int cedula;

    /* expediente */
    char correo[50];
    char estatusCivil[50];
    char telefono[50];
    float patrimonio;

    /* Movimientos */
    float movimientos[50];
    int nMovimientos;
};

struct banco
{
    float patrimonio;
};

struct banco banco;



struct cuentasBancarias cuenta;

void cuentaCliente();
void expedienteDelCliente();
void productosRequisitos();
void resumenActividad();
void servicios();
void menuPagos();
void pagos(float monto);
void retiros();
void consultarImprimirMovimientos();

int main()
{
    cuenta.nMovimientos = 0;
    cuenta.fechaNacimiento = 9999;

    int opcionMenu = 0;
    do
    {
        if (cuenta.fechaNacimiento > 2005)
        {
            printf("\nBienvenido al sistema de BanLMEM:]\n");
            printf("\n___MENU PRINCIPAL___");
            printf("\n1. Cuenta Cliente.");
            printf("\n2. Salir del Sistema.\n");
            printf("\nPor favor, ingrese una opcion: ");
            scanf("%i", &opcionMenu);
            switch (opcionMenu)
            {
            case 1:
                cuentaCliente();
                break;
            case 2:
                printf("\nMuchas gracias por usar los servicios de de BanLMEM:].");
                printf("\nSaliendo del sistema...\n");
                break;
            default:
                printf("\nOpcion invalida\n");
            }
        }
        else
        {
            printf("\nBienvenido al sistema de BanLMEM:]\n");
            printf("\n___MENU PRINCIPAL___");
            printf("\n1.- Cuenta Cliente.");
            printf("\n2.- Expediente Cliente.");
            printf("\n3.- Productos y Requisitos.");
            printf("\n4.- Resumen de Actividad.");
            printf("\n5.- Servicios.");
            printf("\n6.- Pagos.");
            printf("\n7.- Retiros.");
            printf("\n8.- Movimientos.");
            printf("\n9.- Salir del Sistema.\n");
            printf("\nPor favor, ingrese una opcion: ");
            scanf("%i", &opcionMenu);

            switch (opcionMenu)
            {
            case 1:
                cuentaCliente();
                break;
            case 2:
                expedienteDelCliente();
                break;

            case 3:
                productosRequisitos();
                break;

            case 4:
                resumenActividad();
                break;

            case 5:
                servicios();
                break;

            case 6:
                menuPagos();
                break;

            case 7:
                retiros();
                break;

            case 8:
                consultarImprimirMovimientos();
                break;

            case 9:
                printf("\nMuchas gracias por usar los servicios de de BanLMEM:].");
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("\nLa opcion que introducida no es valida, intentelo de nuevo.");
                break;
            }
        }
    } while (opcionMenu < 9);

    return 0;
}

void cuentaCliente()
{
    int opcionMenuCuentaCliente = 0;

    do
    {
        printf("\n__CUENTA CLIENTE__\n");
        printf("\n1. Crear cuenta.");
        printf("\n2. Consultar e imprimir cuenta.");
        printf("\n3. Volver al menu principal.\n");
        printf("\nPor favor, ingrese una opcion: ");
        scanf("%i", &opcionMenuCuentaCliente);

        switch (opcionMenuCuentaCliente)
        {
        case 1:
            printf("\n_CREAR CUENTA_");
            printf("\nIngrese su cedula: ");
            scanf("%i", &cuenta.cedula);
            printf("\nIngrese su primer nombre: ");
            scanf("%s", &cuenta.nombre);
            printf("\nIngrese su primer apellido: ");
            scanf("%s", &cuenta.apellido);
            printf("\nIngrese su dia de nacimiento (##): ");
            scanf("%i", &cuenta.diaNacimiento);
            printf("\nIngrese su mes de nacimiento (##): ");
            scanf("%i", &cuenta.diaNacimiento);
            printf("\nIngrese su año de nacimiento (####): ");
            scanf("%i", &cuenta.fechaNacimiento);
            if (cuenta.fechaNacimiento > 2004)
            {
                printf("\nFallo en la creacion de la cuenta, usted deber ser mayor de edad.\n");
                cuenta.fechaNacimiento = 9999;
                break;
            }
            break;

        case 2:
            if (cuenta.fechaNacimiento < 2005)
            {
                printf("\n_CONSULTA CUENTA_\n");
                printf("\nCedula: %i.", cuenta.cedula);
                printf("\nNombre Completo: %s %s.", cuenta.nombre, cuenta.apellido);
                printf("\nFecha de nacimiento: %i/%i/%i.\n", cuenta.diaNacimiento, cuenta.mesNacimiento, cuenta.fechaNacimiento);
                break;
            }
            else
            {
                printf("\nAun no ha registrado un cliente en nuestros sistemas.\n");
            }

        case 3:
            printf("\nVolviendo al menu principal...\n");
            break;

        default:
            printf("\nLa opcion introducida no es valida, intentelo de nuevo.");
            break;
        }
    } while (opcionMenuCuentaCliente != 3);
}

void expedienteDelCliente()
{
    int opcionMenuCuentaCliente = 0;

    do
    {
        printf("\n__EXPEDIENTE CLIENTE__\n");
        printf("\n1. Crear expediente.");
        printf("\n2. Consultarla e imprimir expediente.");
        printf("\n3. Volver al menu principal.\n");
        printf("\nPor favor, ingrese una opcion: ");
        scanf("%i", &opcionMenuCuentaCliente);

        switch (opcionMenuCuentaCliente)
        {
        case 1:
            printf("\n_CREAR EXPEDIENTE_");
            printf("\nIngrese su correo electronico: ");
            scanf("%s", &cuenta.correo);
            printf("\nIngrese su numero telefonico: ");
            scanf("%s", &cuenta.telefono);
            printf("\nIngrese su estatus civil: ");
            scanf("%s", &cuenta.estatusCivil);
            printf("\nIngrese la cantidad inicial de dinero a agendar a su cuenta: ");
            scanf("%f", &cuenta.patrimonio);
            break;

        case 2:
            printf("\n_CONSULTA EXPEDIENTE_");
            printf("\nNumero telefonico: %s.", cuenta.telefono);
            printf("\nEstatus civil: %s.", cuenta.estatusCivil);
            printf("\nFondo inicial agregado:%.2fBs.", cuenta.patrimonio);
            break;

        case 3:
            printf("\nVolviendo al menu principal...\n");
            break;

        default:
            printf("\nLa opcion introducida no es valida, intentelo de nuevo.");
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
}

void resumenActividad()
{
    int resumenDeActividad = 0;

    do
    {
        printf("\n__RESUMEN DE ACTIVIDAD BANCARIA__\n");
        printf("\n1. Resumen Semanal.");
        printf("\n2. Resumen Mensual.");
        printf("\n3. Volver al menu principal.\n");
        printf("\nPor favor, ingrese una opcion: ");
        scanf("%i", &resumenDeActividad);

        switch (resumenDeActividad)
        {
        case 1:
            printf("\n_RESUMEN SEMANAL_");
            printf("\n_[22/05/2023] al [28/05/2023]\n");

            printf("\n[25/05/2003] Creacion de Expediente Cliente: C.I: %i.", cuenta.cedula);
            printf("\n[25/05/2003] Creacion de Cuenta Cliente: C.I: %i.\n", cuenta.cedula);
            printf("\n[23/05/2003] Creacion de Expediente Cliente: C.I: 6359458.\n");
            printf("\n[22/05/2003] Creacion de Cuenta Cliente: C.I: 6359458.");
            printf("\n[22/05/2003] Solicitud de Tarjeta de Debito: C.I: 12698364.\n");
            break;

        case 2:
            printf("\n_RESUMEN MENSUAL_");
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
            printf("\n[12/05/2003] Creacion de Expediente Cliente: C.I: 22489123.\n");

            printf("\n_SEMANA [01/05/2023] a [07/05/2023]");
            printf("\n[07/05/2003] Creacion de Expediente Juridico: R.I.F: 0254003964.");
            printf("\n[05/05/2003] Creacion de Cuenta Cliente: C.I: 22489123.");
            printf("\n[04/05/2003] Creacion de Cuenta Juridica: R.I.F: 0254003964.");
            printf("\n[04/05/2003] Creacion de Cuenta Cliente: C.I: 11697364.\n");
            break;

        case 3:
            printf("\nVolviendo al menu principal...\n");
            break;

        default:
            printf("\nLa opcion introducida no es valida, intentelo de nuevo.");
            break;
        }

    } while (resumenDeActividad != 3);
}

void menuPagos()
{
    int opcionMenuPagos = 0;
    int cedulaPropia;
    int cedulaTercero;
    char telefonoPropio[50];
    char telefonoTercero[50];
    float monto;
    int salida;

    int opcionMenuEfectivo = 0;
    float montoDolares;

    do
    {

        printf("\n__PAGOS__\n");
        printf("\n1. Pago Movil.");
        printf("\n2. Transferencia.");
        printf("\n3. Pago en Efectivo.");
        printf("\n4. Volver al menu principal.\n");
        printf("\nPor favor, ingrese una opcion: ");
        scanf("%i", &opcionMenuPagos);

        switch (opcionMenuPagos)
        {
        case 1:
            printf("\n_PAGO MOVIL_");
            printf("\nIngrese ingrese el telefono asociado a su cuenta: ");
            scanf("%s", &telefonoPropio);
            printf("\nIngrese ingrese el telefono asociado a la cuenta que desea hacer el Pago Movil: ");
            scanf("%s", &telefonoTercero);
            printf("\nIngrese el monto a pagar: ");
            scanf("%f", &monto);
            printf("\nPAGO MOVIL DE: %.2fbs", monto);
            printf("\nTELEFONO EMISOR: %s.", telefonoPropio);
            printf("\nTELEFONO RECEPTOR: %s.", telefonoTercero);
            pagos(monto);
            break;

        case 2:
            printf("\n_TRANSFERENCIA_");
            printf("\nIngrese ingrese la cedula asociada a su cuenta: ");
            scanf("%i", &cedulaPropia);
            printf("\nIngrese ingrese la cedula asociada a la cuenta que desea hacer la Transferencia: ");
            scanf("%i", &cedulaTercero);
            printf("\nIngrese el monto a pagar: ");
            scanf("%f", &monto);
            printf("\nTRANSFERENCIA DE: %.2fbs", monto);
            printf("\nCEDULA EMISOR: %i", cedulaPropia);
            printf("\nCEDULA RECEPTOR: %i", cedulaTercero);
            pagos(monto);
            break;

        case 3:

            printf("\n_PAGO EN EFECTIVO_");
            printf("\n1. Bolivares.");
            printf("\n2. Dolares.");
            printf("\nPor favor, ingrese una opcion: ");
            scanf("%i", &opcionMenuEfectivo);

            switch (opcionMenuEfectivo)
            {
            case 1:
                printf("\nPAGO EN EFECTIVO (BOLIVARES)");
                printf("\nIngrese ingrese la cedula asociada a su cuenta: ");
                scanf("%i", &cedulaPropia);
                printf("\nIngrese ingrese la cedula asociada a la cuenta que desea hacer el pago en Efectivo: ");
                scanf("%i", &cedulaTercero);
                printf("\nIngrese el monto a pagar en bolivares: ");
                scanf("%f", &monto);

                printf("\nIntroduzca el efectivo en la maquina y confirme para continuar: ");
                printf("\nCONTINUAR INTRODUCIENDO CUALQUIER NUMERO.");
                scanf("%i", &salida);

                pagos(monto);

                printf("\nPAGO EN EFECTIVO DE: %.2fbs.", monto);
                printf("\nCEDULA EMISOR: %i.", cedulaPropia);
                printf("\nCEDULA RECEPTOR: %i.", cedulaTercero);
                printf("\nSu pago en efectivo fue realizado con EXITO!");
                break;

            case 2:
                printf("\nPAGO EN EFECTIVO (DOLARES).");
                printf("\nIngrese ingrese la cedula asociada a su cuenta: ");
                scanf("%i", &cedulaPropia);
                printf("\nIngrese ingrese la cedula asociada a la cuenta que desea hacer el pago en Efectivo: ");
                scanf("%i", &cedulaTercero);
                printf("\nIngrese el monto a pagar en dolares: ");
                scanf("%f", &montoDolares);

                printf("\nIntroduzca el efectivo en la maquina y confirme para continuar: ");
                printf("\nCONTINUAR INTRODUCIENDO CUALQUIER NUMERO.");
                scanf("%i", &salida);

                printf("\nPAGO EN EFECTIVO DE: %.2f$.", montoDolares);
                printf("\nCEDULA EMISOR: %i.", cedulaPropia);
                printf("\nCEDULA RECEPTOR: %i.", cedulaTercero);
                printf("\nSu pago en efectivo fue realizado con EXITO!");
                break;

            default:
                printf("\nOpcion Invalida");
                break;
            }
            break;

        case 4:
            printf("\nVolviendo al menu principal...\n");
            break;

        default:
            printf("\nLa opcion introducida no es valida, intentelo de nuevo.");
            break;
        }
    } while (opcionMenuPagos != 4);
}

void pagos(float monto)
{
    if (monto > cuenta.patrimonio)
    {
        printf("\nMonto insuficiente para realizar la operacion.\n");
    }
    else
    {
        printf("\nSu pago fue realizada con EXITO!");
        cuenta.patrimonio -= monto;
        cuenta.movimientos[cuenta.nMovimientos] = monto;
        cuenta.nMovimientos++;
    }
}

void servicios()
{
    int serviciosCobros = 0;
    char telefono[50];
    float monto;
    int cedula;

    do
    {
        printf("\n__SERVICIOS__\n");
        printf("\n1. Renta Telefonica.");
        printf("\n2. Servicio de Agua.");
        printf("\n3. Servicio de Luz.");
        printf("\n4. Volver al menu principal.\n");
        printf("\nPor favor, ingrese una opcion: ");
        scanf("%i", &serviciosCobros);

        switch (serviciosCobros)
        {
        case 1:
            printf("\n_RENTA TELEFONICA_");

            printf("\nIngrese el numero de telefono que desea recargar: ");
            scanf("%s", &telefono);
            printf("\nMontos disponibles!");
            printf("\n-20bs.");
            printf("\n-30bs.");
            printf("\n-50bs.");
            printf("\n-100bs.");

            printf("\nIngrese uno de los montos disponibles: ");
            scanf("%f", &monto);

            if (monto > cuenta.patrimonio)
            {
                printf("\nMonto insuficiente para realizar la recarga.\n");
            }
            else
            {
                cuenta.patrimonio -= monto;
                cuenta.movimientos[cuenta.nMovimientos] = monto;
                cuenta.nMovimientos++;
                printf("\nRECARGA DE: %.2fbs.", monto);
                printf("\nNUMERO TELEFONICO: %s.", telefono);
                printf("\nSu recarga fue realizada con EXITO!");
            }
            break;

        case 2:
            printf("\n_SERVICIO DE AGUA_");

            printf("\nIngrese el numero de cedula asociado a su contrato: ");
            scanf("%i", &cedula);

            printf("\nMontos disponibles!");
            printf("\n-100bs.");
            printf("\n-150bs.");
            printf("\n-300bs.");
            printf("\n-500bs.");

            printf("\nIngrese uno de los montos disponibles: ");
            scanf("%f", &monto);

            if (monto > cuenta.patrimonio)
            {
                printf("\nMonto insuficiente para realizar el pago.\n");
            }
            else
            {
                cuenta.patrimonio -= monto;
                cuenta.movimientos[cuenta.nMovimientos] = monto;
                cuenta.nMovimientos++;
                printf("\nPAGO DE AGUA DE: %.2fbs.", monto);
                printf("\nNUMERO DE CEDULA ASOCIADO: %i.", cedula);
                printf("\nSu pago de servicio fue realizado con EXITO!");
            }
            break;

        case 3:
            printf("\n_SERVICIO DE LUZ_");

            printf("\nIngrese el numero de cedula asociado a su contrato: ");
            scanf("%i", &cedula);

            printf("\nMontos disponibles!");
            printf("\n-100bs.");
            printf("\n-150bs.");
            printf("\n-300bs.");
            printf("\n-500bs.");

            printf("\nIngrese uno de los montos disponibles: ");
            scanf("%f", &monto);

            if (monto > cuenta.patrimonio)
            {
                printf("\nMonto insuficiente para realizar el pago.\n");
            }
            else
            {
                cuenta.patrimonio -= monto;
                cuenta.movimientos[cuenta.nMovimientos] = monto;
                cuenta.nMovimientos++;
                printf("\nPAGO DE LUZ DE: %.2fbs.", monto);
                printf("\nNUMERO DE CEDULA ASOCIADO: %i.", cedula);
                printf("\nSu pago de servicio fue realizado con EXITO!");
            }
            break;

        case 4:
            printf("\nVolviendo al menu principal...\n");
            break;

        default:
            printf("\nLa opcion introducida no es valida, intentelo de nuevo.");
            break;
        }

    } while (serviciosCobros != 4);
}

void retiros()
{
    int retirosCuenta = 0;
    float monto;
    float montoBanco;
    int cedula;
    char claveBanco;

    banco.patrimonio = 10000000;
    claveBanco = " BanlmEM10 ";

    do
    {
        printf("\n__RETIROS__\n");
        printf("\n1. Retiro Cliente.");
        printf("\n2. Retiro Bancario.");
        printf("\n3. Volver al menu principal.\n");
        printf("\nPor favor, ingrese una opcion: ");
        scanf("%i", &retirosCuenta);

        switch (retirosCuenta)
        {

        case 1:
            printf("\n_RETIRO CLIENTE_");
            printf("\nIngrese ingrese la cedula asociada a su cuenta: ");
            scanf("%i", &cedula);
            printf("\nIngrese el monto que desea retirar de su cuenta: ");
            scanf("%f", &monto);

            if (monto > cuenta.patrimonio)
            {
                printf("\nSaldo insuficiente para realizar el retiro.\n");
            }
            else
            {
                cuenta.patrimonio -= monto;
                cuenta.movimientos[cuenta.nMovimientos] = monto;
                cuenta.nMovimientos++;
                printf("\nMONTO A RETIRAR: %.2fbs.", monto);
                printf("\nNUMERO DE CEDULA ASOCIADO: %i.", cedula);
                printf("\nSu retiro de fondos fue realizado con EXITO!");
            }

            break;

        case 2:
            printf("\n_RETIRO BANCARIO_");
            printf("\nIngrese la clave especial asociada a los fondos bancarios: ");
            scanf("%s", &claveBanco);
            printf("\nIngrese el monto que desea retirar de los fondos bancarios: ");
            scanf("%f", &monto);

            if (monto > banco.patrimonio)
            {
                printf("\nSaldo insuficiente para realizar el retiro.\n");
            }
            else
            {
                banco.patrimonio -= monto;
                printf("\nMONTO A RETIRAR: %.2fbs.", monto);
                printf("\nSu retiro de fondos bancarios fue realizado con EXITO!");
            }

            break;

        case 3:
            printf("\nVolviendo al menu principal...\n");

            break;

        default:
            printf("\nLa opcion introducida no es valida, intentelo de nuevo.");
            break;
        }

    } while (retirosCuenta != 3);
}

void consultarImprimirMovimientos()
{
    int opcion;
    do
    {

        printf("\n---- Menú de Consulta de Movimientos ----\n");
        printf("1. Movimientos del banco\n");
        printf("2. Movimientos de la cuenta del cliente\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("\n--Consulta e impresión de movimientos del banco--\n");
            printf("-%.2f\n", banco.patrimonio);
            break;
        case 2:
            printf("\n--Consulta e impresión de movimientos de la cuenta del cliente--\n");

            for (int i = 0; i < cuenta.nMovimientos; i++)
            {
                printf("-%.2f\n", cuenta.movimientos[i]);
            }
            break;

        default:
            printf("\nLa opcion introducida no es valida, intentelo de nuevo.");
        }
    } while (opcion != 3);
}

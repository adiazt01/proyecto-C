#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_MOVIMIENTOS 100

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

struct movimientoBanco 
{
    char fecha[50];
    float monto;
};

struct movimientoCliente 
{
    char fecha[50];
    float monto;
};


struct cuentasBancarias cuenta;

struct movimientoBanco movimientosBanco[MAX_MOVIMIENTOS];
int totalMovimientosBanco = 0;

struct movimientoCliente movimientosCliente[MAX_MOVIMIENTOS];
int totalMovimientosCliente = 0;

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
    cuenta.fechaNacimiento = 9999;

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
                cuentaCliente();
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
            printf("\n5. Servicios.");
            printf("\n6. Pagos.");
            printf("\n7. Retiros.");
            printf("\n8. Movimientos.");
            printf("\n9. Salir del Sistema.\n");
            printf("\nIngrese una opcion: ");
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


void cuentaCliente()
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
            else
            {
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


void expedienteDelCliente()
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
            printf("\n[22/05/2003] Solicitud de Tarjeta de Debito: C.I: 12698364.\n");
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
            printf("\n[12/05/2003] Creacion de Expediente Cliente: C.I: 22489123.\n");
            
            printf("\n_SEMANA [01/05/2023] a [07/05/2023]");
            printf("\n[07/05/2003] Creacion de Expediente Juridico: R.I.F: 0254003964.");
            printf("\n[05/05/2003] Creacion de Cuenta Cliente: C.I: 22489123.");
            printf("\n[04/05/2003] Creacion de Cuenta Juridica: R.I.F: 0254003964.");
            printf("\n[04/05/2003] Creacion de Cuenta Cliente: C.I: 11697364.\n");
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


void menuPagos()
{
    int opcionMenuPagos = 0;
    float monto;

    printf("\n--Menu de Pagos--\n");
    printf("\n1. Pago Movil (Bolivares)");
    printf("\n2. Transferencia (Bolivares)");
    printf("\n3. Pago en Efectivo (Bolivares)");
    printf("\nIngrese una opcion: ");
    scanf("%i", &opcionMenuPagos);

    switch (opcionMenuPagos)
    {
        case 1:
            printf("\nIngrese el monto del pago en bolivares: ");
            scanf("%f", &monto);
            pagos(monto);
            break;
        
        case 2:
            printf("\nIngrese el monto de la transferencia en bolivares: ");
            scanf("%f", &monto);
            pagos(monto);
            break;
        
        case 3:
            printf("\nIngrese el monto del pago en efectivo en bolivares: ");
            scanf("%f", &monto);
            pagos(monto);
            break;
        
        default:
            printf("\nOpcion Invalida");
            break;
    }
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
        printf("\nPago realizado con exito!");
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
        printf("\n1.1 Renta Telefonica.");
        printf("\n1.2 Servicio de Agua.");
        printf("\n1.3 Servicio de Luz.");
        printf("\n1.4 Volver al menu principal.\n");
        printf("\nPor favor ingrese una opcion: ");
        scanf("%i", &serviciosCobros);

        switch (serviciosCobros)
        {       
        case 1:
            printf("\n__RENTA TELEFONICA__\n");

            printf("\nIngrese el numero de telefono que desea recargar: ");
            scanf("%s", &telefono);
            printf("\nMontos disponibles!");
            printf("\n-20bs.");
            printf("\n-30bs.");
            printf("\n-50bs.");
            printf("\n-100bs.");
            
            printf("\nIngrese uno de los montos disponibles: ");
            scanf("%f", &monto);
            
                if(monto > cuenta.patrimonio)
                {
                printf("\nMonto insuficiente para realizar la recarga.\n");
                }
                else
                {
                cuenta.patrimonio -= monto;
                printf("\nRECARGA DE: %.2f", monto);
                printf("\nNUMERO TELEFONICO: %s", telefono);
                printf("\nSu recarga fue realizada con EXITO!");
                }
            break;
        
        case 2:
            printf("\n__SERVICIO DE AGUA__\n");

            printf("\nIngrese el numero de cedula asociado a su contrato: ");
            scanf("%i", &cedula);

            printf("\nMontos disponibles!");
            printf("\n-100bs.");
            printf("\n-150bs.");
            printf("\n-300bs.");
            printf("\n-500bs.");
            
            printf("\nIngrese uno de los montos disponibles: ");
            scanf("%f", &monto);

                if(monto > cuenta.patrimonio)
                {
                printf("\nMonto insuficiente para realizar el pago.\n");
                }
                else
                {
                cuenta.patrimonio -= monto;
                printf("\nPAGO DE AGUA DE: %.2f", monto);
                printf("\nNUMERO DE CEDULA ASOCIADO: %i", cedula);
                printf("\nSu pago de servicio fue realizado con EXITO!");
                }
            break;
        
        case 3:
            printf("\n__SERVICIO DE LUZ__\n");

            printf("\nIngrese el numero de cedula asociado a su contrato: ");
            scanf("%i", &cedula);

            printf("\nMontos disponibles!");
            printf("\n-100bs.");
            printf("\n-150bs.");
            printf("\n-300bs.");
            printf("\n-500bs.");
            
            printf("\nIngrese uno de los montos disponibles: ");
            scanf("%f", &monto);

                if(monto > cuenta.patrimonio)
                {
                printf("\nMonto insuficiente para realizar el pago.\n");
                }
                else{
                cuenta.patrimonio -= monto;
                printf("\nPAGO DE LUZ DE: %.2f", monto);
                printf("\nNUMERO DE CEDULA ASOCIADO: %i", cedula);
                printf("\nSu pago de servicio fue realizado con EXITO!");
                }
            break;

        case 4:
            printf("\nSaliendo...\n");
            break;
        
        default:
            printf("\nOpcion Invalida\n");
            break;
        }
    
    }   while (serviciosCobros !=4);
}

void retiros()
{
    int retirosCuenta = 0;
        float monto;
        float montoBanco;
        int cedula;
        char claveBanco;

        montoBanco = 10000000;
        claveBanco = " BanlmEM10 ";

    do
    {
        printf("\n__RETIROS__\n");
        printf("\n1.1 Retiro Cliente.");
        printf("\n1.2 Retiro Bancario.");
        printf("\n1.3 Volver al menu principal.\n");
        printf("\nPor favor ingrese una opcion: ");
        scanf("%i", &retirosCuenta);

        switch (retirosCuenta)
        {
        
        case 1:
            printf("\n__RETIRO CLIENTE_\n");
            printf("\nIngrese ingrese la cedula asociada a su cuenta: ");
            scanf("%i", &cedula);
            printf("\nIngrese el monto que desea retirar de su cuenta: ");
            scanf("%f", &monto);

            if(monto > cuenta.patrimonio)
                {
                printf("\nSaldo insuficiente para realizar el retiro.\n");
                }
                else{
                cuenta.patrimonio -= monto;
                printf("\nMONTO A RETIRAR: %.2f", monto);
                printf("\nNUMERO DE CEDULA ASOCIADO: %i", cedula);
                printf("\nSu retiro de fondos fue realizado con EXITO!");
                }

            break;
        
        case 2:
            printf("\n__RETIRO BANCARIO__\n");
            printf("\nIngrese la clave especial asociada a los fondos bancarios: ");
            scanf("%s", &claveBanco);
            printf("\nIngrese el monto que desea retirar de los fondos bancarios: ");
            scanf("%f", &monto);


            if(monto > montoBanco)
                {
                printf("\nSaldo insuficiente para realizar el retiro.\n");
                }
                else{
                montoBanco -= monto;
                printf("\nMONTO A RETIRAR: %.2f", monto);
                printf("\nSu retiro de fondos bancarios fue realizado con EXITO!");
                }

            break;
        
        case 3:
            printf("\nSaliendo...\n");

            break;

        default:
            printf("\nOpcion Invalida\n");
            break;
        }
    
    }   while (retirosCuenta !=3);
}

void consultarImprimirMovimientos() 
{
    int opcion;

    printf("\n---- Menú de Consulta de Movimientos ----\n");
    printf("1. Movimientos del banco\n");
    printf("2. Movimientos de la cuenta del cliente\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("\n--Consulta e impresión de movimientos del banco--\n");
            
            for (int i = 0; i < totalMovimientosBanco; i++) 
            {
                printf("Fecha: %s, Monto: %.2f\n", movimientosBanco[i].fecha, movimientosBanco[i].monto);
            }
            break;
        
        case 2:
            printf("\n--Consulta e impresión de movimientos de la cuenta del cliente--\n");
            
            for (int i = 0; i < totalMovimientosCliente; i++) 
            {
                printf("Fecha: %s, Monto: %.2f\n", movimientosCliente[i].fecha, movimientosCliente[i].monto);
            }
            break;
        
        default:
            printf("Opción inválida\n");
    }
}

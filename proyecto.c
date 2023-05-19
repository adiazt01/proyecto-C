#include <stdio.h>
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
    int telefono[50];
    float patrimonio[50];
};

void productosRequisitos();
void CuentaCliente(void);
void menuPagos(struct cuentasBancarias* cuenta);
void pagos(struct cuentasBancarias* cuenta, float monto, bool esDolar);

int main()
{
    int opcionMenu = 0;
    do
    {
        printf("\nBienvenido al sistema de BanLMEM:]\n");
        printf("\n--MENU--");
        printf("\n1. Cuenta Cliente.");
        printf("\n2. Expediente Cliente.");
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
                printf("\n2da opcion");
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
               menuPagos(&CuentaCliente);
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
    } while (opcionMenu < 9);

    return 0;
}

void CuentaCliente(void)
{
    int opcionMenuCuentaCliente = 0;
    struct cuentasBancarias cuenta;

    do
    {
        printf("\n--Menu Cliente--\n");
        printf("\n1.1 Crearla");
        printf("\n1.2 Consultarla e imprimirla\n");
        printf("\nPor favor ingrese una opcion: ");
        scanf("%i", &opcionMenuCuentaCliente);

        switch (opcionMenuCuentaCliente)
        {
            case 1:
                printf("\n--Creacion de usuario--\n");
                printf("\nPor favor ingrese su cedula: ");
                scanf("%i", &cuenta.cedula);
                printf("\nPor favor ingrese su nombre: ");
                scanf("%s", cuenta.nombre);
                printf("\nPor favor ingrese su fecha de nacimiento: ");
                scanf("%i", &cuenta.fechaNacimiento);
                printf("%i", cuenta.cedula);
                break;
            case 2:
                break;
            default:
                printf("Opcion Invalida");
                break;
        }
    } while (opcionMenuCuentaCliente < 2);
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

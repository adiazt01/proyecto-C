#include <stdio.h>

// Estructura para el registro de la cuenta del cliente
struct Cuenta {
    int numeroCuenta;
    char nombreCliente[50];
    float saldo;
};

// Estructura para el expediente del cliente
struct Expediente {
    int numeroExpediente;
    char nombreCliente[50];
    char direccion[100];
};

// Función para crear una cuenta de cliente
void crearCuenta(struct Cuenta *cuenta) {
    printf("Ingrese el número de cuenta: ");
    scanf("%d", &(cuenta->numeroCuenta));
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", cuenta->nombreCliente);
    printf("Ingrese el saldo inicial: ");
    scanf("%f", &(cuenta->saldo));
}

// Función para consultar e imprimir el registro de la cuenta de un cliente
void consultarCuenta(struct Cuenta cuenta) {
    printf("Número de cuenta: %d\n", cuenta.numeroCuenta);
    printf("Nombre del cliente: %s\n", cuenta.nombreCliente);
    printf("Saldo: %.2f\n", cuenta.saldo);
}

// Función para crear un expediente de cliente
void crearExpediente(struct Expediente *expediente) {
    printf("Ingrese el número de expediente: ");
    scanf("%d", &(expediente->numeroExpediente));
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", expediente->nombreCliente);
    printf("Ingrese la dirección: ");
    scanf("%s", expediente->direccion);
}

// Función para consultar e imprimir un expediente de cliente
void consultarExpediente(struct Expediente expediente) {
    printf("Número de expediente: %d\n", expediente.numeroExpediente);
    printf("Nombre del cliente: %s\n", expediente.nombreCliente);
    printf("Dirección: %s\n", expediente.direccion);
}

// Función para mostrar los productos y requisitos del banco
void mostrarProductos() {
    printf("\nProductos del Banco de Venezuela:\n");
    printf("1. Persona Natural\n");
    printf("   Requisitos: Cédula de identidad, constancia de residencia, referencias personales.\n");
    printf("2. Persona Jurídica\n");
    printf("   Requisitos: RIF de la empresa, registro mercantil, estados financieros.\n");
}

// Función para generar cobros por servicio de la cuenta al cliente
void generarCobro(struct Cuenta *cuenta) {
    float monto;
    printf("Ingrese el monto del cobro: ");
    scanf("%f", &monto);
    cuenta->saldo -= monto;
    printf("Cobro generado correctamente.\n");
}

// Función para generar pagos en la cuenta del cliente
void generarPago(struct Cuenta *cuenta) {
    float monto;
    int opcion;
    printf("Seleccione el método de pago:\n");
    printf("1. Transferencia\n");
    printf("2. Pago móvil\n");
    printf("3. Efectivo en bolívares\n");
    printf("4. Efectivo en dólares\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Ingrese el monto de la transferencia: ");
            scanf("%f", &monto);
            cuenta->saldo += monto;
            
         printf("Transferencia realizada correctamente.\n");
            break;
        case 2:
            printf("Ingrese el monto del pago móvil: ");
            scanf("%f", &monto);
            cuenta->saldo += monto;
            printf("Pago móvil realizado correctamente.\n");
            break;
        case 3:
            printf("Ingrese el monto en bolívares: ");
            scanf("%f", &monto);
            cuenta->saldo += monto;
            printf("Pago en efectivo en bolívares realizado correctamente.\n");
            break;
        case 4:
            printf("Ingrese el monto en dólares: ");
            scanf("%f", &monto);
            cuenta->saldo += monto;
            printf("Pago en efectivo en dólares realizado correctamente.\n");
            break;
        default:
            printf("Opción inválida. Por favor, intente nuevamente.\n");
            break;
    }
}

// Función para generar un resumen de actividad semanal y mensual del banco
void generarResumenActividad() {
    printf("Generando resumen de actividad...\n");
    // Lógica para generar el resumen de actividad
    printf("Resumen de actividad generado correctamente.\n");
}

// Función para consultar e imprimir movimientos diarios, semanales y mensuales del banco
void consultarMovimientos() {
    printf("Consultando movimientos...\n");
    // Lógica para consultar e imprimir los movimientos
    printf("Movimientos consultados e impresos correctamente.\n");
}

// Función para crear, consultar e imprimir retiros diarios, semanales y mensuales del banco
void crearRetiros() {
    printf("Creando retiros...\n");
    // Lógica para crear, consultar e imprimir los retiros
    printf("Retiros creados, consultados e impresos correctamente.\n");
}

// Función para consultar e imprimir movimientos diarios, semanales y mensuales de una cuenta
void consultarMovimientosCuenta(struct Cuenta cuenta) {
    printf("Consultando movimientos de la cuenta %d...\n", cuenta.numeroCuenta);
    // Lógica para consultar e imprimir los movimientos de la cuenta
    printf("Movimientos de la cuenta consultados e impresos correctamente.\n");
}

// Función para crear, consultar e imprimir retiros diarios, semanales y mensuales de una cuenta
void crearRetirosCuenta(struct Cuenta cuenta) {
    printf("Creando retiros de la cuenta %d...\n", cuenta.numeroCuenta);
    // Lógica para crear, consultar e imprimir los retiros de la cuenta
    printf("Retiros de la cuenta creados, consultados e impresos correctamente.\n");
}

// Función principal del programa
int main() {
    int opcion;
    struct Cuenta cuenta;
    struct Expediente expediente;

    do {
        printf("\nBienvenido al Banco de Venezuela\n");
        printf("1. Crear cuenta de cliente\n");
        printf("2. Consultar registro de cuenta de cliente\n");
        printf("3. Crear expediente de cliente\n");
        printf("4. Consultar expediente de cliente\n");
        printf("5. Mostrar productos y requisitos\n");
        printf("6. Generar cobro por servicio de cuenta\n");
        printf("7. Generar pago en la cuenta\n");
        printf("8. Generar resumen de actividad\n");
        printf("9. Consultar movimientos diarios, semanales y mensuales\n");
         printf("10. Crear, consultar e imprimir retiros diarios, semanales y mensuales\n");
        printf("11. Consultar e imprimir movimientos diarios, semanales y mensuales de una cuenta\n");
        printf("12. Crear, consultar e imprimir retiros diarios, semanales y mensuales de una cuenta\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                crearCuenta(&cuenta);
                break;
            case 2:
                consultarCuenta(cuenta);
                break;
            case 3:
                crearExpediente(&expediente);
                break;
            case 4:
                consultarExpediente(expediente);
                break;
            case 5:
                mostrarProductos();
                break;
            case 6:
                generarCobro(&cuenta);
                break;
            case 7:
                generarPago(&cuenta);
                break;
            case 8:
                generarResumenActividad();
                break;
            case 9:
                consultarMovimientos();
                break;
            case 10:
                crearRetiros();
                break;
            case 11:
                consultarMovimientosCuenta(cuenta);
                break;
            case 12:
                crearRetirosCuenta(cuenta);
                break;
            case 0:
                printf("Gracias por utilizar nuestros servicios. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida. Por favor, intente nuevamente.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}
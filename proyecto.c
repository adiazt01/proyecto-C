#include <stdio.h>



int main()
{
    /*
    Menu de nuestro programa, esta compuesto por un ciclo do-while que permitira
    poder usar todo el programa sin la necesidad de volver a iniciarlo y una seleccion
    de tipo switch para poder ejecutar las proximas funciones de nuestro programa que
    por ahora solo tiene un printf que sera proximamente remplazado por nuestras funcionesLMEM
    */

    int opcionMenu = 0;
    do
    {
        printf("\nBienvenido al sistema del BanLMEM. :]\n");
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
            printf("\n1ra Opcion");
            break;
        
        case 2:
            printf("\n2ra opcion");
            break;
        
        case 3:
            printf("\n3ra Opcion");
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
    } while (opcionMenu != 9);

    return 0;
}

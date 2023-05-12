#include <stdio.h>

int main()
{
    /*
    Menu de nuestro programa, esta compuesto por un ciclo do-while que permitira
    poder usar todo el programa sin la necesidad de volver a iniciarlo y una seleccion
    de tipo switch para poder ejecutar las proximas funciones de nuestro programa que
    por ahora solo tiene un printf que sera proximamente remplazado por nuestras funciones
    */

    int opcionMenu = 0;
    do
    {
        printf("\n--Menu--\n");
        printf("1. opcion");
        printf("\n2. opcion");
        printf("\n3. Opcion\n");
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
            printf("\nSalir");
            break;
        default:
            break;
        }
    } while (opcionMenu != 4);

    return 0;
}

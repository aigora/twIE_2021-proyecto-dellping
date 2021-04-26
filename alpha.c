#include <stdio.h>

int main()
{
    int num;
    char op;

    do{
    printf("VIAJA CON DELLPING, EXITO ASEGURADOOOOOO \n \n \n");
    printf("Seleccione la opcion deseada para la eleccion de su viaje: \n ");
    printf("a.Fechas deseadas para viajar\n b.Cantidad de personas que van a viajar\n c.Preferencias de viaje\n d.Destinos disponibles\n e.Ver tarifas disponibles\n f.Salir del programa\n");
    scanf("%c", &op);


    switch(op)
    {
        case 'a':
        case 'A':
        printf("HA SELECCIONADO LA OPCION FECHAS.\n");

        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);


        break;

        case 'b':
        case 'B':
        printf("HA SELECCIONADO LA OPCION PERSONAS QUE VAN A VIAJAR. \n");

        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        break;

        case 'c':
        case 'C':
        printf("HA SELECCIONADO LA OPCION PREFERENCIAS DE VIAJE. \n");

        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);


        break;

        case 'd':
        case 'D':
        printf("HA SELECCIONADO LA OPCION DESTINOS DISPONIBLES. \n");

        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);

        break;

        case 'e':
        case 'E':
        printf("HA SELECCIONADO LA OPCION DE VER TARIFAS DISPONIBLES. \n");

        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);


        break;

        case 'f':
        case 'F':
        printf("SALIR. \n");

        break;

        default:
        printf("HA SELECIONADO OPCION DESCONOCIDA. \n");

        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);


        break;

        }

    }while(op!='f' && op!='F');



    return 0;
}

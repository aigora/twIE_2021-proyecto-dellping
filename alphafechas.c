#include <stdio.h>
#include <stdbool.h>

int d0, m0, a0, d1, m1, a1;

typedef struct {int d, m, a; }fecha;

typedef struct
    {fecha entrada;
     fecha salida;
     int np;
    }viaje;

void showData(){
    printf("    DATOS DEL VIAJE    \n");
    printf(" .- Fecha de entrda: %d/%d/%d\n", d0, m0, a0);
    printf(" .- Fecha de salida: %d/%d/%d\n\n\n", d1, m1, a1);
}



int main()
{
    int num;
    char op;


    do{
   system("cls");
    printf("VIAJA CON DELLPING, EXITO ASEGURADO \n \n \n");
    showData();
    printf("Seleccione la opcion deseada para la eleccion de su viaje: \n ");
    printf("a.Fechas deseadas para viajar\n b.Cantidad de personas que van a viajar\n c.Preferencias de viaje\n d.Destinos disponibles\n e.Ver tarifas disponibles\n f.Salir del programa\n");
    scanf("%c", &op);



    switch(op)
    {
        case 'a':
        case 'A':
        printf("HA SELECCIONADO LA OPCION FECHAS.\n");



            bool error = true;
            while(error)
            {
                printf("Por favor, seleccione la fecha de entrada deseada introduciendola en formato dd/mm/aaaa\n");
                scanf("%d/%d/%d", &d0, &m0, &a0);


                if (d0>31 || d0<=0 || m0<=0 || m0>12 || a0<2021)
                {
                  error = true;
                    printf("Ha seleccionado una fecha no disponible: %d/%d/%d, por favor escoja una fecha existente\n", d0, m0, a0);
                }
                else error = false;


            }
                printf("Ha seleccionado %d/%d/%d como fecha de inicio de su viaje\n", d0, m0, a0);

            error = true;
            while(error)
            {
                printf("Por favor, seleccione la fecha de final de viaje en formato dd/mm/aaaa\n");
                scanf("%d/%d/%d", &d1, &m1, &a1);


                if (d1>31 || d1<=0 || m1<=0 || m1>12 || a1<2021)
                {
                  error = true;
                    printf("Ha seleccionado una fecha no disponible: %d/%d/%d, por favor escoja una fecha existente\n", d1, m1, a1);
                }
                else error = false;
            }
                printf("Ha seleccionado %d/%d/%d como fecha de finalizacion de su viaje\n", d1, m1, a1);
                    viaje v;
                        v.entrada.d = d0;
                        v.entrada.m = m0;
                        v.entrada.a = a0;
                        v.salida.d = d1;
                        v.salida.m = m1;
                        v.salida.a = a1;


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

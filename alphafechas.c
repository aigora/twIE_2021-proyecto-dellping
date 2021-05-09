#include <stdio.h>
#include <string.h>
#include <stdbool.h>



int d0, m0, a0, d1, m1, a1, time, np, clase, tar;
// d, m, a son: dia, mes y año de inicio y fin consecutivamente. time es la variable tiempo de transcurso del viaje. np el numero de personas. clase es el tipo de turismo escojido. tar la tarifa.
char tipo[30];
char descuento[30];

typedef struct {int d, m, a; }fecha;

typedef struct
    {fecha entrada;
     fecha salida;
     int np;
    }viaje;

int dias(){
    if (m1 == m0){
     time = d1 - d0;
     //printf("dias: %d\n", time);
    }
    if (m1 > m0){
     time = d1 + (31 * (m1 - m0) - d0 + 1);
     //printf("dias: %d\n", time);
    }
}

float precio(){
//    total = np *
}

void showData(){
    printf("-------- DATOS DEL VIAJE --------\n");
    printf(" - Fecha de entrda: %d/%d/%d\n", d0, m0, a0);
    printf(" - Fecha de salida: %d/%d/%d\n", d1, m1, a1);
    printf("     *La duraci%cn de su viaje ser%c de %d d%cas\n", 162, 160, time, 161);
    printf(" - N%cmero de personas: %d\n", 163, np);
    printf(" - Clase de viaje: %s\n", tipo);
    printf(" - Destino seleccionado: \n");
    printf(" - Tarifa: %s\n\n\n", descuento);
}



int main()
{
    int num;
    char op;


    do{
   system("cls");
    printf("VIAJA CON DELLPING, EXITO ASEGURADO \n \n");
    showData();
    printf("Seleccione la opci%cn deseada para la elecci%cn de su viaje: \n", 162, 162);
    printf(" a.Fechas deseadas para viajar\n b.Cantidad de personas que van a viajar\n c.Preferencias de viaje\n d.Destinos disponibles\n e.Ver tarifas disponibles\n f.Salir del programa\n\n");
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
        dias();
        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        break;


        case 'b':
        case 'B':
        printf("HA SELECCIONADO LA OPCION PERSONAS QUE VAN A VIAJAR. \n");

        printf("Introduzca el numero de personas que van a participar en el viaje: ");
            scanf("%d", &np);

        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        break;


        case 'c':
        case 'C':

        printf("HA SELECCIONADO LA OPCION PREFERENCIAS DE VIAJE. \n");



            bool error1 = true;
            while(error1){

                printf("Seleccione la clase de viaje que desea realizar marcando el numero correspondiente:\n");
                printf(" 1.- Turismo cultural\n 2.- Turismo rural\n 3.- Turismo de sol y playa\n");
                scanf("%d", &clase);
                //printf("Ha seleccionado %d\n", clase);

                if (clase == 1){strcpy(tipo, "Turismo cultural"); error1 = false;}
                else if (clase == 2){strcpy(tipo, "Turismo rural"); error1 = false;}
                else if (clase == 3){strcpy(tipo, "Turismo de sol y playa"); error1 = false;}
                else {error1 = true; printf("Por favor seleccione una de las opciones posibles\n");}
            }
            printf("Ha seleccionado %s\n", tipo);


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
        printf("HA SELECCIONADO LA OPCION TARIFAS DISPONIBLES. \n");
        printf("Marque la tarifa correspondiente:\n 1.- Familia numerosa general: 30%c\n 2.- Familia numerosa especial: 50%c\n 3.- Mayores de 65 a%cos: 25%c\n", 37, 37, 164, 37);

            bool error2 = true;
            while(error2){
            scanf("%d", &tar);
                if (tar == 1) {(error2 = false); printf("Ha seleccionado Familia numerosa general\n"); strcpy(descuento, "Familia numerosa general");}
                else if (tar == 2) {(error2 = false); printf("Ha seleccionado Familia numerosa especial\n"); strcpy(descuento, "Familia numerosa especial");}
                else if (tar == 3) {(error2 = false); printf("Ha seleccionado Mayores de 65 a%cos\n", 164); strcpy(descuento, "Mayores de 65");}
                else {(error2 = true); printf("Por favor, seleccione una opci%cn v%clida\n", 162, 160);}
            }

        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);


        break;

        case 'f':
        case 'F':
        system("cls");
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

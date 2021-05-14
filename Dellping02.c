#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int np, clase, tar, dest, resumen;
// d, m, a son: dia, mes y año de inicio y fin consecutivamente. time es la variable tiempo de transcurso del viaje. np el numero de personas. clase es el tipo de turismo escojido. tar la tarifa.

float tarifa;
char tipo[30];
char descuento[30];
char destino[20];

typedef struct {
    int d, m, a, tiempo;
    }fecha;

typedef struct {
float price0, price1, price2;
}money;

typedef struct{
    char nombre[20], apellido1[20], apellido2[20], email[30];
} registro;

int dias(fecha entrada, fecha salida){
 int time;
    if (salida.m == entrada.m){
     time = salida.d - entrada.d;
     //printf("dias: %d\n", time);
    }
    if (salida.m > entrada.m){
     time = salida.d + (31 * (salida.m - entrada.m) - entrada.d + 1);
     //printf("dias: %d\n", time);
    }
 salida.tiempo = time;
 return time;
}

float precio(){
fecha salida;
money a;
    a.price1 = np * a.price0 * salida.tiempo;
    a.price2 = a.price1 * tarifa;
}

void showData(fecha entrada, fecha salida, int tiempo){
    money a;
    printf("\n-------- DATOS DEL VIAJE --------\n");
    printf(" - Fecha de entrda: %d/%d/%d\n", entrada.d, entrada.m, entrada.a);
    printf(" - Fecha de salida: %d/%d/%d\n", salida.d, salida.m, salida.a);
    printf("        La duraci%cn de su viaje ser%c de %d d%cas\n", 162, 160, tiempo, 161);
    printf(" - N%cmero de personas: %d\n", 163, np);
    printf(" - Clase de viaje: %s\n", tipo);
    printf(" - Destino seleccionado: %s\n", destino);
    printf(" - Tarifa: %s\n", descuento);
    printf("        PRECIO sin descuento: %f EUR\n", a.price1);
    printf("        PRECIO con descuento: %f EUR\n\n", a.price2);
}

void addFichero(){
FILE *pf;
    pf = fopen("Viaje.txt", "w");
        if(pf == NULL) printf("Ha habido un error al abrir el archivo");
        else {
            fecha entrada;
            fecha salida;
            int tiempo;
            money a;
            registro user1;
            fprintf(pf, "Registro de usuario:\n");
            fprintf(pf, "   Nombre: %s %s %s\n", user1.nombre, user1.apellido1, user1.apellido2);
            fprintf(pf, "   Email: %s\n\n\n", user1.email);

            fprintf(pf, "-------- DATOS DEL VIAJE --------\n");
            fprintf(pf," - Fecha de entrda: %d/%d/%d\n", entrada.d, entrada.m, entrada.a);
            fprintf(pf," - Fecha de salida: %d/%d/%d\n", salida.d, salida.m, salida.a);
            fprintf(pf,"        La duracion de su viaje sera de %d dias\n", tiempo);
            fprintf(pf," - N%cmero de personas: %d\n", 163, np);
            fprintf(pf," - Clase de viaje: %s\n", tipo);
            fprintf(pf," - Destino seleccionado: %s\n", destino);
            fprintf(pf," - Tarifa: %s\n", descuento);
            fprintf(pf,"        PRECIO sin descuento: %f EUR\n", a.price1);
            fprintf(pf,"        PRECIO con descuento: %f EUR\n\n", a.price2);
        }
    fclose(pf);
}

int main()
{
int d0, m0, a0, d1, m1, a1;
int num, numDias;
char op, name[20], ap1[20], ap2[20], mail[30];
fecha entrada, salida;
         entrada.d = 0;
         entrada.m = 0;
         entrada.a = 0;
         salida.d = 0;
         salida.m = 0;
         salida.a = 0;

printf("VIAJA CON DELLPING, %cXITO ASEGURADO\n\n", 144);
printf("Por favor, registre su usuario\n");
int comprobacion = 2;
while(comprobacion != 0){
registro user1;
printf("Nombre: ");
        scanf("%s", user1.nombre);
printf("Primer apellido: ");
        scanf("%s", user1.apellido1);
printf("Segundo apellido: ");
        scanf("%s", user1.apellido2);
printf("Correo electr%cnico: ", 162);
    scanf("%s", user1.email);
printf("Para confirmar los datos introducidos y continuar al menu principal, pulse 0. Si desea realizar algun cambio pulse 1: ");
    scanf("%d", &comprobacion);
    system("cls");
    }

    do{
    system("cls");
    printf("VIAJA CON DELLPING, %cXITO ASEGURADO\n", 144);

    precio();
    addFichero();
    showData(entrada, salida, numDias);

    printf("Seleccione la opci%cn deseada para la elecci%cn de su viaje: \n", 162, 162);
    printf(" a.Fechas deseadas para viajar\n b.Cantidad de personas que van a viajar\n c.Preferencias de viaje\n d.Ver tarifas disponibles\n     e.Salir del programa\n\n");
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
         entrada.d = d0;
         entrada.m = m0;
         entrada.a = a0;
         salida.d = d1;
         salida.m = m1;
         salida.a = a1;

        numDias = dias(entrada, salida);
        system("cls");
        showData(entrada, salida, numDias);



        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        break;


        case 'b':
        case 'B':
        printf("HA SELECCIONADO LA OPCION PERSONAS QUE VAN A VIAJAR. \n");
        printf("Introduzca el numero de personas que van a participar en el viaje: ");
            scanf("%d", &np);
        //printf("Pulse un numero si desea volver al menu principal. \n");
        //scanf("%d", &num);
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
        printf("    A continuacion escoja un destino:\n");
       money a;
        if (clase == 1) {
            printf("    1.- Granada: 120 EUR\n    2.- Salamanca: 60 EUR\n");
            scanf("%d", &dest);
            if (dest == 1) {printf("Ha seleccionado la opcion turismo cultural en Granada\n"); strcpy(destino, "Granada"); a.price0 = 120;}
            else if (dest == 2) {printf("Ha seleccionado la opcion turismo cultural en Salamanca\n"); strcpy(destino, "Salamanca"); a.price0 = 60;}
            else {printf("Ha seleccionado una opci%cn inexistente, por favor introduzca el n%cmero de nuevo: ", 162, 163); scanf("%d", &dest);}
        }
        else if (clase == 2) {
            printf("    1.- Picos de Europa: 89 EUR\n    2.- Sierra Nevada: 129 EUR\n");
            scanf("%d", &dest);
            if (dest == 1) {printf("Ha seleccionado la opcion turismo rural en Picos de Europa\n"); strcpy(destino, "Picos de Europa"); a.price0 = 89;}
            else if (dest == 2) {printf("Ha seleccionado la opcion turismo rural en Sierra Nevada\n"); strcpy(destino, "Sierra Nevada"); a.price0 = 129;}
            else {printf("Ha seleccionado una opci%cn inexistente, por favor introduzca el n%cmero de nuevo: ", 162, 163); scanf("%d", &dest);}
        }
        else if (clase == 3) {
            printf("    1.- Menorca: 186 EUR\n    2.- Lanzarote: 210 EUR\n    3.- Costa Brava: 70 EUR\n");
            scanf("%d", &dest);
            if (dest == 1) {printf("Ha seleccionado la opcion turismo de sol y playa en Menorca\n"); strcpy(destino, "Menorca"); a.price0 = 186;}
            else if (dest == 2) {printf("Ha seleccionado la opcion turismo de sol y playa en Lanzarote\n"); strcpy(destino, "Lanzarote"); a.price0 = 210;}
            else if (dest == 3) {printf("Ha seleccionado la opcion turismo de sol y playa en Costa Brava\n"); strcpy(destino, "Costa Brava"); a.price0 = 70;}
            else {printf("Ha seleccionado una opci%cn inexistente, por favor introduzca el n%cmero de nuevo: ", 162, 163); scanf("%d", &dest);}
        }

        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        break;

        case 'd':
        case 'D':
        printf("HA SELECCIONADO LA OPCION TARIFAS DISPONIBLES. \n");
        printf("Marque la tarifa correspondiente:\n 1.- Familia numerosa general: 30%c\n 2.- Familia numerosa especial: 50%c\n 3.- Mayores de 65 a%cos: 25%c\n", 37, 37, 164, 37);
        bool error2 = true;
        while(error2){
        scanf("%d", &tar);
            if (tar == 1) {(error2 = false); printf("Ha seleccionado Familia numerosa general\n"); strcpy(descuento, "Familia numerosa general"); tarifa = 0.7;}
            else if (tar == 2) {(error2 = false); printf("Ha seleccionado Familia numerosa especial\n"); strcpy(descuento, "Familia numerosa especial"); tarifa = 0.5;}
            else if (tar == 3) {(error2 = false); printf("Ha seleccionado Mayores de 65 a%cos\n", 164); strcpy(descuento, "Mayores de 65"); tarifa = 0.75;}
            else {(error2 = true); printf("Por favor, seleccione una opci%cn v%clida\n", 162, 160);}
        }
        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        break;


        case 'e':
        case 'E':
        system("cls");
        printf("SALIR. \n");

        break;

        default:
        printf("HA SELECIONADO OPCION DESCONOCIDA. \n");
        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        break;

        }

    }while(op!='e' && op!='E');


    printf("Si desea consultar el resumen de su viaje pulse 0: ");
    scanf("%d", &resumen);
    /*if(resumen == 0){
            FILE *pf2;
            pf2 = fopen("Viaje.txt", "r");
    }*/



    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    int d, m, a, tiempo;
    }fecha;

typedef struct {
float price0, price1, price2;
}dinero;

typedef struct{
fecha entrada;
fecha salida;
int np;
int clase;
char tipo[30];
float tarifa;
char descuento[30];
int dest;
char destino[20];
int resumen;
dinero d;
}viaje;


typedef struct{
    char nombre[20], apellido1[20], apellido2[20], email[30];
} registro;

int dias(viaje v){
    int timev;
    if (v.salida.m == v.entrada.m){
     timev = v.salida.d - v.entrada.d;

    }
    if (v.salida.m > v.entrada.m){
     timev = v.salida.d + (31 * (v.salida.m - v.entrada.m) - v.entrada.d + 1);

    }
 return timev;
}

float calculaTarifa1(viaje v, int numD){
    float auxTarifa;
    auxTarifa = v.np * v.d.price0 * numD;
    return auxTarifa;
}

float calculaTarifa2(viaje v){
    float auxTarifa;
    auxTarifa = v.d.price1 * v.tarifa;
    return auxTarifa;
}

void showData(viaje v){
    int numDias;
    numDias = dias(v);
    char destiny[20];
    strcpy(destiny, v.destino);

    printf("\n-------- DATOS DEL VIAJE --------\n");
    printf(" - Fecha de entrada: %d/%d/%d\n", v.entrada.d, v.entrada.m, v.entrada.a);
    printf(" - Fecha de salida: %d/%d/%d\n", v.salida.d, v.salida.m, v.salida.a);
    printf("        La duraci%cn de su viaje ser%c de %d d%cas\n", 162, 160, numDias, 161);
    printf(" - N%cmero de personas: %d\n", 163, v.np);
    printf(" - Clase de viaje: %s\n", v.tipo);
    printf(" - Destino seleccionado: %s\n", destiny);
    printf(" - Tarifa: %s\n", v.descuento);
    printf("        PRECIO sin descuento: %f EUR\n", v.d.price1);
    printf("        PRECIO con descuento: %f EUR\n\n", v.d.price2);
}

void addFichero(viaje v, registro user1){
FILE *pf;
    int numDias;
    numDias = dias(v);
    char nombre[20], apellido1[20], apellido2[20], correo[30];
    strcpy(nombre, user1.nombre);
    strcpy(apellido1, user1.apellido1);
    strcpy(apellido2, user1.apellido2);
    strcpy(correo, user1.email);

    pf = fopen("Viaje.txt", "w");
        if(pf == NULL) printf("Ha habido un error al abrir el archivo");
        else {
            fprintf(pf, "Registro de usuario:\n");
            fprintf(pf, "   Nombre: %s %s %s\n", nombre, apellido1, apellido2);
            fprintf(pf, "   Email: %s\n\n\n", correo);

            fprintf(pf, "-------- DATOS DEL VIAJE --------\n");
            fprintf(pf," - Fecha de entrada: %d/%d/%d\n", v.entrada.d, v.entrada.m, v.entrada.a);
            fprintf(pf," - Fecha de salida: %d/%d/%d\n", v.salida.d, v.salida.m, v.salida.a);
            fprintf(pf,"        La duracion de su viaje sera de %d dias\n", numDias);
            fprintf(pf," - Nucmero de personas: %d\n", v.np);
            fprintf(pf," - Clase de viaje: %s\n", v.tipo);
            fprintf(pf," - Destino seleccionado: %s\n", v.destino);
            fprintf(pf," - Tarifa: %s\n", v.descuento);
            fprintf(pf,"        PRECIO sin descuento: %f EUR\n", v.d.price1);
            fprintf(pf,"        PRECIO con descuento: %f EUR\n\n", v.d.price2);
        }
    fclose(pf);
}

int main()
{
int d0, m0, a0, d1, m1, a1;
int num, numDias;
char op, name[20], ap1[20], ap2[20], mail[30];
viaje v;
         v.entrada.d = 0;
         v.entrada.m = 0;
         v.entrada.a = 0;
         v.salida.d = 0;
         v.salida.m = 0;
         v.salida.a = 0;
         v.np = 0;
         v.salida.tiempo = 0;

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
    addFichero(v,user1);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    do{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("VIAJA CON DELLPING, %cXITO ASEGURADO\n", 144);
    numDias = dias(v);
    registro user1;
    v.d.price1 = calculaTarifa1(v,numDias);
    v.d.price2 = calculaTarifa2(v);

    addFichero(v, user1);
    showData(v);
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
         v.entrada.d = d0;
         v.entrada.m = m0;
         v.entrada.a = a0;
         v.salida.d = d1;
         v.salida.m = m1;
         v.salida.a = a1;

        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        break;

        case 'b':
        case 'B':
        printf("HA SELECCIONADO LA OPCION PERSONAS QUE VAN A VIAJAR. \n");
        int np;
        printf("Introduzca el numero de personas que van a participar en el viaje: ");
            scanf("%d", &np);
        v.np = np;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        break;

        case 'c':
        case 'C':
        printf("HA SELECCIONADO LA OPCION PREFERENCIAS DE VIAJE. \n");
        int clase;
        bool error1 = true;
        while(error1){
            printf("Seleccione la clase de viaje que desea realizar marcando el numero correspondiente:\n");
            printf(" 1.- Turismo cultural\n 2.- Turismo rural\n 3.- Turismo de sol y playa\n");
            scanf("%d", &clase);
            v.clase = clase;
            if (clase == 1){strcpy(v.tipo, "Turismo cultural"); error1 = false;}
            else if (clase == 2){strcpy(v.tipo, "Turismo rural"); error1 = false;}
            else if (clase == 3){strcpy(v.tipo, "Turismo de sol y playa"); error1 = false;}
            else {error1 = true; printf("Por favor seleccione una de las opciones posibles\n");}
        }
        printf("Ha seleccionado %s\n", v.tipo);
        printf("    A continuacion escoja un destino:\n");
        int dest;
        if (clase == 1) {
            printf("    1.- Granada: 120 EUR\n    2.- Salamanca: 60 EUR\n");
            scanf("%d", &dest);
            if (dest == 1) {printf("Ha seleccionado la opcion turismo cultural en Granada\n"); strcpy(v.destino, "Granada"); v.d.price0 = 120;}
            else if (dest == 2) {printf("Ha seleccionado la opcion turismo cultural en Salamanca\n"); strcpy(v.destino, "Salamanca"); v.d.price0 = 60;}
            else {printf("Ha seleccionado una opci%cn inexistente, por favor introduzca el n%cmero de nuevo: ", 162, 163); scanf("%d", &dest);}
        }
        else if (clase == 2) {
            printf("    1.- Picos de Europa: 89 EUR\n    2.- Sierra Nevada: 129 EUR\n");
            scanf("%d", &dest);
            if (dest == 1) {printf("Ha seleccionado la opcion turismo rural en Picos de Europa\n"); strcpy(v.destino, "Picos de Europa"); v.d.price0 = 89;}
            else if (dest == 2) {printf("Ha seleccionado la opcion turismo rural en Sierra Nevada\n"); strcpy(v.destino, "Sierra Nevada"); v.d.price0 = 129;}
            else {printf("Ha seleccionado una opci%cn inexistente, por favor introduzca el n%cmero de nuevo: ", 162, 163); scanf("%d", &dest);}
        }
        else if (clase == 3) {
            printf("    1.- Menorca: 186 EUR\n    2.- Lanzarote: 210 EUR\n    3.- Costa Brava: 70 EUR\n");
            scanf("%d", &dest);
            if (dest == 1) {printf("Ha seleccionado la opcion turismo de sol y playa en Menorca\n"); strcpy(v.destino, "Menorca"); v.d.price0 = 186;}
            else if (dest == 2) {printf("Ha seleccionado la opcion turismo de sol y playa en Lanzarote\n"); strcpy(v.destino, "Lanzarote"); v.d.price0 = 210;}
            else if (dest == 3) {printf("Ha seleccionado la opcion turismo de sol y playa en Costa Brava\n"); strcpy(v.destino, "Costa Brava"); v.d.price0 = 70;}
            else {printf("Ha seleccionado una opci%cn inexistente, por favor introduzca el n%cmero de nuevo: ", 162, 163); scanf("%d", &dest);}
        }
        v.dest = dest;
        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        break;

    int tar;
        case 'd':
        case 'D':
        printf("HA SELECCIONADO LA OPCION TARIFAS DISPONIBLES. \n");
        printf("Marque la tarifa correspondiente:\n 1.- Familia numerosa general: 30%c\n 2.- Familia numerosa especial: 50%c\n 3.- Mayores de 65 a%cos: 25%c\n", 37, 37, 164, 37);
        bool error2 = true;
        while(error2){
        scanf("%d", &tar);
            if (tar == 1) {(error2 = false); printf("Ha seleccionado Familia numerosa general\n"); strcpy(v.descuento, "Familia numerosa general"); v.tarifa = 0.7;}
            else if (tar == 2) {(error2 = false); printf("Ha seleccionado Familia numerosa especial\n"); strcpy(v.descuento, "Familia numerosa especial"); v.tarifa = 0.5;}
            else if (tar == 3) {(error2 = false); printf("Ha seleccionado Mayores de 65 a%cos\n", 164); strcpy(v.descuento, "Mayores de 65"); v.tarifa = 0.75;}
            else {(error2 = true); printf("Por favor, seleccione una opci%cn v%clida\n", 162, 160);}
        }
        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        break;


        case 'e':
        case 'E':
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("SALIR. \n");
        break;

        default:
        printf("HA SELECIONADO OPCION DESCONOCIDA. \n");
        printf("Pulse un numero si desea volver al menu principal. \n");
        scanf("%d", &num);
        break;

        }

    }while(op!='e' && op!='E');

    return 0;
}

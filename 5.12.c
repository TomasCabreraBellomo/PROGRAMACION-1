/*Realizar un programa que solicite que se ingrese por teclado el nombre de algún archivo de texto,
trabajado hasta el momento en el práctico, para luego mostrar por pantalla el contenido del mismo, en
caso de no encontrar ese archivo mostrar un mensaje*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void apertura(char arreglo[]);
void ingreso(char arreglo[]);

int main(int argc, char const *argv[])
{
    char arreglo[100];
    apertura(arreglo);
    ingreso(arreglo);
    return 0;
}

void apertura(char arreglo[]){
    FILE *puntero;

    puntero = fopen(arreglo,"r");

    if (puntero == NULL)
    {   printf("No se ha logrado abrir correctamente, intente nuevamente");
    }
    else{ 
        printf("Se abrio correctamente \n");
    }
         fclose(puntero);
    }


void ingreso(char arreglo[]){
    FILE *p;
    char car[100];

    printf("Ingrese el nombre de algun archivo de texto, que se haya utilizado anteriormente: \n");
    fgets(arreglo,100,stdin);
    arreglo[strlen(arreglo) -1] = '\0';

    p  = fopen(arreglo,"r");

    if (p == NULL)
    {
        printf("El archivo no existe, debe ingresar un archivo con el que se haya trabajado anteriormente");

    }
    else{printf("Se abrio correctamente \n");
        
        printf("Los caracteres y cadenas ingresadas en ese archivo son: \n");

        do
        {
            fgets(car,100,p);

            if (feof(p) == 0)
            {
                printf("%s",car);
            }
            
        } while (feof(p) == 0);
            fclose(p);
}}

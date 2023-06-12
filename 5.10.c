/*Diseñar un programa que permita leer el archivo del ejercicio 9, solicite un caracter al usuario y cuente
cuántas veces se encuentra el caracter en el archivo. Presente el resultado por pantalla.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void apertura(char arreglo[]);
int contador(char arreglo[]);
void mostrar(int cantidad);

int main(int argc, char const *argv[])
{
    char arreglo[] = "lenguajeC.txt";
    int cantc;

    apertura(arreglo);
   cantc = contador(arreglo);
    mostrar(cantc);
    return 0;
}

void apertura(char arreglo[]){
    FILE *puntero;

    puntero = fopen(arreglo,"w");

    if (puntero == NULL)
    {   printf("No se ha logrado abrir correctamente, intente nuevamente");
    }
    else{printf("Se abrio correctamente \n");
    }
         fclose(puntero);
    }
   
    
int contador (char arreglo[]){
    FILE *p;
    char car,car2;
    int contador = 0;
    printf("Ingrese el caracter que quiere buscar en el archivo: \n");
    scanf("%c",&car);

    p = fopen(arreglo,"r");

do
{
    car = fgetc(p);

        if (feof(p) == 0)
        {
            if (car == car2)
            {
                contador++;
            }
            
        }
        
} while (feof(p) == 0);
fclose(p);
return contador;
}
void mostrar(int cantidad){
    printf("La cantidad de caracteres que coinciden con el ingresado por teclado es: %i\n",cantidad);
}

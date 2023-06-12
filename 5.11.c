* Diseñar un programa que permita leer el archivo del ejercicio 9 y cuente cuantas veces se hace
referencia a la frase: “lenguaje en C". En este caso 4 veces*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void apertura(char arreglo[]);
int contador(char arreglo[]);

int main(int argc, char const *argv[])
{
    char arreglo[] = "lenguajeC.txt";
    int cantidad = 0;

    apertura(arreglo);
    cantidad = contador(arreglo);
    

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


int contador(char arreglo[]){
    FILE *p;
  	char cadena[100], cadena1[100];
  	int cont=0;

    printf("Ingrese la cadena que quiere buscar: \n");
    fgets(cadena1,100,stdin);
    cadena1[strlen(cadena1) -1] = '\0';

    p = fopen(arreglo,"r"); //abro el archivo en modo lectura

    do
    {
        fgets(cadena,100,p);
            if (feof(p) == 0)
            {
                if (strcmp(cadena,cadena1) == 0)
                {
                    cont++;
                }
                
            }
            
    } while (feof(p) == 0);
    
    printf("\n La cadena %s se encontro %i veces \n",cadena1,contador);
    
    fclose(p);
}

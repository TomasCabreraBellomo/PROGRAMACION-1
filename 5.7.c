/*Realizar un programa que solicite al usuario el nombre de un archivo, almacene caracteres en el mismo y
luego lo presente por pantalla. Al ingresar el nombre del archivo se debe verificar si existe, si el mismo
no existe se debe crear y permitir el ingreso de caracteres. Si el archivo existe se deben agregar
caracteres al final. Luego mostrar el contenido del archivo por pantalla. Usar:
○ Una función para verificar la existencia, en caso de no existir, realizar la creación del archivo.
○ Una función para solicitar al usuario los caracteres y almacenarlos en el archivo.
○ Una función para mostrar el contenido del archivo.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int control(char arreglo[]);

void ingreso(char arreglo[100]);

void mostrar(char arreglo[100]);

int main(int argc, char const *argv[])
{
    char arreglo[100];
    int bandera;

    printf("Ingrese el nombre del archivo: \n");
   
    fgets(arreglo,100,stdin);
    arreglo[strlen(arreglo)-1] = '\0';

    bandera = control (arreglo);

    if (bandera == 0)
    {
    ingreso(arreglo);
    mostrar(arreglo);
    }
    else if (bandera == 1)
    {
        ingreso(arreglo);
        mostrar(arreglo);
    }
    


    return 0;
}


int control(char arreglo[]){

FILE *p;

p = fopen(arreglo,"r");

if (p == NULL)
{
    printf("No existe ese archivo, se creara uno");
    p = fopen(arreglo,"w");

    if (p == NULL)
    {
        printf("No se pudo crear el archivo");
        fclose(p);
        exit(0);
    }  
    return 1;
}

if (p != NULL)
{
    printf("El arcvhvo se abrio correctamente");
    fclose(p);
    return 0;
}
}

void ingreso(char arreglo[100]){
    FILE *p;
    char c;
    p = fopen(arreglo,"a");

    do
    {
        printf("Ingrese caracteres en el arreglo: \n");
        scanf("%c",&c);
        fgetc(stdin);

        if (c != 'F')
        {
           fputc(c,p);
        }
        

    } while (c != 'F');
    
    fclose(p);
}

void mostrar(char arreglo[100]){
    FILE *p;
    char c;
    printf("Los caracteres ingresados son: \n");
    p = fopen(arreglo,"r");

    do
    {
        c = fgetc(p);
        if (feof(p) == 0)
        {
            printf("%c",c);
        }
        
    } while (feof(p) == 0);
    
    fclose(p);
}

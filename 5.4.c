/*Realizar un programa que solicite al usuario el nombre de un archivo. Se debe verificar si existe un
archivo con ese nombre, si el mismo no existe se debe crear y permitir el ingreso de caracteres. Si el
archivo existe se deben agregar caracteres al final. Luego mostrar el contenido del archivo por pantalla.*/

#include<stdio.h>
#include<string.h>


int main(int argc, char const *argv[])
{   
    FILE *p;
    char car[100],c;
    int band = 0;

    printf("Ingrese el nombre del archivo: \n");
    fgets(car,100,stdin);
    car[strlen(car) ] != '\0' ;

    p = fopen(car,"rt");
  
   if(p == NULL){
        
        printf("No es un archivo existente, se creara; \n");
    }
    else{ printf("Se abrio correctamente \n");
    fclose(p);}


    p = fopen(car,"a");

    if (p == NULL)
    {
    printf("Se abrio correctamente");

    }
    else{ printf("Se creo correctamente");}
    
    do
    {
        printf("Ingrese un caracter, ingrese F para finalizar: \n");
        scanf("%c",&c);
        fgetc(stdin);

    if (c != 'F'){
    fputc(c,p);

    }} while (c != 'F');
    
    
    fclose(p);

    p = fopen(car,"r");

    if (p == NULL)
    {
    printf("No existe,se lo creara");

    }
    else{ printf("Se creo correctamente \n");}

    printf("Los caracteres ingresados son: \n");

    do
    {
    c = fgetc(p) ;

    if (feof(p) == 0)
    {   

    printf("%c \n ",c) ;
    }

    } while (feof(p) == 0 );

    fclose(p);

    
    return 0;
}

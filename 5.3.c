/*Realizar un programa que permita ingresar caracteres desde el teclado, el programa deberá escribir los
caracteres a medida que se ingresen en un archivo de texto llamado archivoTexto.txt El ingreso de
caracteres debe finalizar cuando se ingrese la letra F, esta última no deberá ser escrita en el archivo.
Luego debe presentar por pantalla el contenido del archivo cargado*/

#include<stdio.h>

#include<stdio.h>

int main(int argc, char const *argv[])
{
char c,cadena[100] = "archivotexto.txt";

FILE *p;

p = fopen(cadena,"w");

if(p = NULL){
printf("No se ingreso correctamente \n");
}
else{ printf("Se abrio correctamente \n");}

fclose(p);

p = fopen(cadena,"a");

do
{
printf("Ingrese un caracter, para finalizar ingrese F :\n");
scanf("%c",&c);
fgetc(stdin);

if (c != 'F')
{
fputc(c,p);
}

} while (c != 'F');

fclose(p);

p = fopen(cadena,"r");

printf("Los caracteres ingresados son: \n");

do
{
c = fgetc(p) ;

if (feof(p) == 0)
{   

printf("%c \n ",c) ;
}

} while (feof(p) == 0 );

fclose(p) ;

return 0;
}

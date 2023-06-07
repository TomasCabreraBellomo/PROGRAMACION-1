*Realizar un programa que permita ingresar caracteres desde el teclado, el programa deberá escribir los
caracteres a medida que se ingresen en un archivo de texto llamado archivoTexto.txt El ingreso de
caracteres debe finalizar cuando se ingrese la letra F, esta última no deberá ser escrita en el archivo.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void ingresocar(char nombre[100]);

int main(int argc, char const *argv[])
{
    char nombre[100];

    return 0;
}

void ingresocar(char nombre[100]){
    FILE *p;

    char c;

    p = fopen(nombre,"a");

    if(p = NULL){
    printf("No se ingreso correctamente \n");
    }
    else{ printf("Se abrio correctamente \n");}


    do
    {
        printf("Ingrese una serie de caracteres, finaliza cuando ingresa F: \n");
        scanf("%c",&c);
        fgetc(stdin);

        if (c != 'F')
        {
            fputs(c,p);
        }
        

    } while (c != 'F');
    
    

fclose(p);
return;

}

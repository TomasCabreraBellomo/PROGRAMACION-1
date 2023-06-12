/*Realizar un programa que permita ingresar cadenas de caracteres que contengan dos o más palabras en
un archivo llamado cadenas.txt., almacenar un renglón o línea de texto por cada cadena ingresada. El
ingreso de cadenas finaliza con la cadena: "Fin del ingreso". Consideraciones:
○ El control de que las cadenas ingresadas tengan dos o más palabras debe realizarse con una
función.
○ La cadena “Fin del ingreso” no debe ser escrita en el archivo.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void apertura(char arreglo[100]);
void controlcadenas(char arreglo[100]);

int main(int argc, char const *argv[])
{
    char arreglo[100] = "cadenas.txt";

    apertura(arreglo);
    controlcadenas(arreglo);

    return 0;
}
void apertura(char arreglo[100]){
    FILE *p;

    p = fopen(arreglo,"w");

    if (p == NULL)
    {
        printf("El archivo no se abrió correctamente, abra de nuevo");

    }
    else{printf("Se abrio correctamente");
    }

    fclose(p);
}

void controlcadenas(char arreglo[100]){
    char cadena[100];
    int contespacios = 0;
    FILE *p;
    do
    {
        printf("Ingrese la cadena: \n");

        fgets(cadena,100,stdin);

        cadena[strlen(cadena) -1] != '\0';

            for (int i = 0; i < strlen(cadena); i++)
            {
                if (cadena[i] == ' ')
                {
                    fputs(cadena,p);
                }
                
            }
            
            
    } while (cadena == "Fin del ingreso");

    fclose(p);
    
}

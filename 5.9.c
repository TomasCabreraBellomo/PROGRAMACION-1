/*9. Dado el siguiente fragmento:
Suele decirse que programar en lenguaje en C es muy difícil!!! y las grandes masas no comprenden
por qué, ya que sienten que al leer en un fin de semana un Manual sobre lenguaje en C,
comprenderlo y aplicar exitosamente los Ejemplos del Texto han dominado el lenguaje. Y es allí el
gran error, el lenguaje en C es mucho más que su propio contenido. Yo solía decir, años atrás en que
impartí varios Cursos de lenguaje en C, que el citado lenguaje no era complejo, por el contrario, es
estupendamente sencillo y explícito, que su auténtico valor radica en su amplio alcance y versátil
profundidad.
Utilizando un editor de texto, almacenar el fragmento en un archivo de texto llamado lenguajeC.txt en el
directorio de trabajo. Implementar un programa que muestre el contenido de este archivo por pantalla.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mostrar(char arreglo[]);

int main(int argc, char const *argv[])
{
    char arreglo[] = "lenguajeC.txt";

    mostrar(arreglo);
    return 0;
}

void mostrar(char arreglo[]){
        FILE *p;

    p = fopen(arreglo,"r");

    if (p == NULL)
    {
        printf("No se ha logrado abrir correctamente, intente nuevamente");
    }
    else{printf("Se abrio correctamente \n");
    }
    

    printf("El texto ingresado es: \n");
    fgets(arreglo,100000000,p);

    printf("%s",arreglo);
    
    fclose(p);
}

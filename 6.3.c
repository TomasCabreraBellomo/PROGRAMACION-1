3. Realizar un programa que permita utilizar una variable tipo estructura, que contendrá información
referente a procesadores de computadoras (marca, modelo y precio). Mostrar por pantalla un menú
interactivo, que contenga las siguientes opciones:
A- Ingresar información de un procesador
B- Mostrar por pantalla la información del procesador
C- Salir del programa
Para resolver:
○ Respetar las opciones del menú como se indican
○ Usar una función para implementar el menú
○ Usar una función para ingresar los datos de cada procesador
○ Usar una función para mostrar por pantalla los datos de cada procesador. En el formato de
salida mostrar los títulos: Marca - Modelo - Precio y debajo uo y debajo un procesador por línea 
Ejemplo:
MARCA MODELO PRECIO
X925 124rT 385,22
INTEL 386MM 1589,0
Implementar controles de datos, en todos los casos si no se cumple el control se solicita el
reingreso:
i. Marca solo puede contener dígitos, letras y espacio
ii. Modelo solo puede contener dígitos, letras y guiones
iii. Precio es un valor real mayor que cero
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct {
    char marca[100],modelo[100];
    float precio;
} producto;

char menu ();//Usar una función para implementar el menú
producto ingresar ();//Usar una función para ingresar los datos de cada procesador
void mostrar(int orden,producto p1[]);/*Usar una función para mostrar por pantalla los datos de cada procesador. En el formato de
salida mostrar los títulos: Marca - Modelo - Precio y debajo uo y debajo un procesador por línea */


int main(int argc, char const *argv[])
{   
    producto p1[20];
    
    int ordeningreso = 0;



    while (1)
    {
     switch (menu())
    {
    case 'A':

       p1[ordeningreso] =  ingresar();
       ordeningreso++;
       
        break;

    case 'B': 

            if (ordeningreso != 0)
            {
                 mostrar(ordeningreso,p1);
            }
            else{printf("No se ingreso ningun procesador, ingrese uno! ");}
             break;

    case 'C': 
    printf("Fin del programa");
     exit (0);
    break;
    
    default: 
    printf("Seleccione una opcion dentro del menu");
    break;
    }

    fgetc(stdin);

    }
    return 0;
}

char menu(){
    producto p1;
    char opcion;

    do
    {
printf("Ingrese una de las siguientes opciones a continuacion:");
printf( "\nA-Ingresar información de un procesador.\n");
printf("B-Mostrar por pantalla la información del procesador\nC-Salir del programa \n");

scanf("%c",&opcion);

fgetc(stdin);

    opcion= toupper(opcion) ;

        if (opcion != 'A' && opcion != 'B' && opcion != 'C')
        {
            printf("No es valida! Debe elegir una de las definidas anteriormente!");
        }
        
    } while (opcion != 'A' && opcion != 'B' && opcion != 'C');
    
   return opcion;
}

producto ingresar(){
   producto p1;
        
        printf("Ingrese la marca del producto: \n");
        fscanf(stdin,"%s[0-9 A-Z]",p1.marca);
        getchar();
        
        printf("Ingrese el modelo del producto: \n");
        fscanf(stdin,"%s[0-9-A-Z]s",p1.modelo);
        getchar();

        do
        {
        printf("Ingrese el precio del producto:\n");
        scanf("%f",&p1.precio);
        } while (p1.precio<=0);
        getchar();

     return p1;   
}

void mostrar(int orden,producto p1[]) {

    printf("MARCA     MODELO     PRECIO \n");
   
    for (int i = 0; i < orden; i++)
    {
        printf("%s     %s     %f \n",p1[i].marca,p1[i].modelo,p1[i].precio);
    }
    
    

}

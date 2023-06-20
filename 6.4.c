#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct {
    char marca[100],modelo[100];
    float precio;
} producto;

void apertura(char c[]);
char menu ();//Usar una función para implementar el menú
producto ingresar ();//Usar una función para ingresar los datos de cada procesador
void mostrar(char c[]);/*Usar una función para mostrar por pantalla los datos de cada procesador. En el formato de
salida mostrar los títulos: Marca - Modelo - Precio y debajo uo y debajo un procesador por línea */
void escrituraenarchivo(char c[]);

int main(int argc, char const *argv[])
{   
    producto p1[20];
    char c[] ="procesadores.dat";
    int ordeningreso = 0;
    int bandera  = 0;

    apertura(c);

    while (1)
    {
     switch (menu())
    {
    case 'A':

    escrituraenarchivo(c);
    bandera = 1;
        break;

    case 'B': 

            if (bandera != 0)
            {
                 mostrar(c);
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
void escrituraenarchivo(char c[]){
    FILE *p;
    producto p1 = ingresar(); //ingreso procesador guardado en el struct en la variable de la funcion

    p = fopen(c,"wb"); //abro en modo escritura

    fwrite(&p1,sizeof(p1),1,p); //escribo en el archivo binario

    fclose(p);
}

void apertura(char c[]){
    FILE *p;

p=fopen(c,"rb");
    if(p==NULL){
        printf("No se pudo abrir el archivo, se lo crear�... \n");
        p=fopen(c,"wb");
        if(p==NULL){
            printf("No se pudo crear el archivo... Fin del programa\n");
            exit(0);
        }
    }
    fclose(p);
    return;
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

void mostrar(char c[]) {
    FILE *p;
    producto producto1;
    
    printf("MARCA     MODELO     PRECIO \n");


    p = fopen(c,"rb");
   fread(&producto1,sizeof(producto1),1,p);

   fclose(p);

        printf("%s     %s     %f \n",producto1.marca,producto1.modelo,producto1.precio);
    
}

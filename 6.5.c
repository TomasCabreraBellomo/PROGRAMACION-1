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
void listado(char c[]);/*Usar una función para mostrar por pantalla los datos de cada procesador. En el formato de
salida mostrar los títulos: Marca - Modelo - Precio y debajo uo y debajo un procesador por línea */
void escrituraenarchivo(char c[]);
int tienecontenido(char c[]);
void consultapr(float pr,char c[]);
void mostrarstruct(producto p1);
void fin();

int main(int argc, char const *argv[])
{   
    producto p1[20];
    char c[] ="procesadores.dat";
    int ordenprocesadores = 0;
    int bandera  = 0;
    float precio;

    apertura(c);

    while (1)
    {
     switch (menu())
    {
    case 'A':

    escrituraenarchivo(c);
    ordenprocesadores++;

        break;

    case 'B': 

            if (tienecontenido(c) != 0)
            {
                listado(c);
            }
            else{printf("No se ingreso ningun procesador, ingrese uno! ");}

             break;

    case 'C': 
    printf("Ingrese el precio que desa consultar:\n");
    scanf("%f",&precio);
    fgetc(stdin);

    consultapr(precio,c);
   
    break;
    
    case 'D':
     printf("Fin del programa");
     exit (0);

    default: 
    printf("Seleccione una opcion dentro del menu");
    break;
    }

    fgetc(stdin);

    }
    return 0;
}

void consultapr(float pr,char c[]){
    FILE *p;
    producto p1;

    p = fopen(c,"rb"); //abro el archivo en modo lectura
    fseek(p,0,2); //ubico el indicador de posicion al final del archivo

    int e = ftell(p)/sizeof(p1); // con esta operacion, calculo la cantidad de struct que tengo guardad en el archivo

    rewind(p); //ubica el indicador de posicion al principio del archivo


    printf("Listado con precio menor que: \n %f",pr);
    printf("\n\n\tMarca\t\t\t\tTamanio en GB\t\t\tPrecio\n");

    for (long i = 0; i < e; i++)
    {
        fread(&p1,sizeof(p1),1,p);
            if (p1.precio<pr)
            {
                mostrarstruct(p1);
            }
            
    }
    fclose(p);

    fin();
    }
    

int tienecontenido(char c[]){
    FILE *p;
    producto proc1;
    int boolean;

    p = fopen(c,"rb");

    fread(&proc1,sizeof(proc1),1,p);

    if (feof(p)==0)
    {
        boolean = 1;
    }
    else{boolean = 0;}

    fclose(p);

return boolean;
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
printf("B-Mostrar por pantalla la información del procesador\n");
printf("C-Ingrese un precio para comparar con los anteriormente ingresados\n");
printf("D-Salir del programa \n");


printf("\n\n\n Seleccione una opcion: \n");

scanf("%c",&opcion);

fgetc(stdin);

    opcion= toupper(opcion) ;

        if (opcion != 'A' && opcion != 'B' && opcion != 'C' && opcion !='D')
        {
            printf("No es valida! Debe elegir una de las definidas anteriormente!");
        }
        
    } while (opcion != 'A' && opcion != 'B' && opcion != 'C'&& opcion != 'D');
    
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

void listado(char c[]) {
    FILE *p;
    producto producto1;
    long i,t;
    //t sirve para indicar la cantidad de estructuras que hay en el archivo
    //i sirve para indicar la posicion del indicador de posicion

    p = fopen(c,"rb"); //abro el archivo en modo lectura

        fseek(p,0,2); //ubico el indicador de posicion al final del archivo

    t = ftell(p)/sizeof(producto1); //calculo la cantidad de structs que estan en el archivo

    rewind(p); // vuelvo a ubicar al principio el indicador
printf("\n\t\t\t\t\tListado");
    printf("\n\n\tMarca\t\t\t\tTamanio en GB\t\t\tPrecio\n");
    for ( i = 0; i < t; i++)
    {
        fread(&producto1,sizeof(producto1),1,p); //leo lo que esta en el archivo
        mostrarstruct(producto1); //muestro las estructuras en el archivo
    }
   fclose(p);
   fin();
}

void fin(){
    printf("\nPresionar enter para regresar al Menu... ");
 
    if(fgetc(stdin)!='\n')
        fgetc(stdin);
 
    return;
}

void mostrarstruct(producto p1){ //muestra el contenido de la estructura
     printf("\t%s",p1.marca);
    printf("\t\t\t\t%s",p1.modelo);
    printf("\t\t\t\t%f\n",p1.precio); 
 
}

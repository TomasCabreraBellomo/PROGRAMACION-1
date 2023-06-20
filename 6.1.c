/* Realizar un programa que solicite el ingreso de los datos de UNA persona: Apellido, Nombre, día, mes y
año de nacimiento; debe utilizar una estructura para contener dichos datos. Luego el programa deberá
escribir la estructura en un archivo binario llamado archivoBinario.dat*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct {
    char apellido[100],nombre[100];
    int dia,mes,anio;
} persona;


int main(int argc, char const *argv[])
{   
    char archivo[ ]= "archivoBinario.dat";
    persona p1;
    FILE *p;

    p = fopen(archivo,"rb");
if (p == NULL)
{
    printf("No existe el archivo, se intentara crearlo");
    p =fopen(archivo,"wb");
    if (p == NULL)
{
    printf("No se puede crear el archivo, fin del programa");
    exit(0);
}
}
fclose(p);

printf("\n Debe ingresar los datos solicitados:\n");


   printf("Ingrese el nombre de la persona: \n");
fgets(p1.nombre,50,stdin);

p1.nombre[strlen(p1.nombre)-1] = '\0';



printf("Ingrese el apellido de la persona: \n");
fgets(p1.apellido,50,stdin);

p1.apellido[strlen(p1.apellido)-1] = '\0';


do
{
  printf("Ingrese el dia de nacimiento de la persona: \n");
  scanf("%i",&p1.dia);

} while (p1.dia < 1 || p1.dia > 31);

do
{
  printf("Ingrese el mes de nacimiento de la persona: \n");
  scanf("%i",&p1.mes);

} while (p1.mes < 1 || p1.mes > 31);

do
{
  printf("Ingrese el anio de nacimiento de la persona: \n");
  scanf("%i",&p1.anio);

} while (p1.anio < 1 || p1.anio > 31);

//Ingreso todo lo que me solicita la consigna y despues lo guardo en el archivo

p = fopen(archivo,"ab");

fwrite(&p1,sizeof(p1),1,p);

fclose(p);


p = fopen(archivo,"rb");

fread(&p1,sizeof(p1),1,p);

printf("Los datos ingresados son: \n");
printf("Nombre de la persona: %s \n",p1.nombre);
printf("Apellido de la persona:%s \n",p1.apellido);
printf("Dia de nacimiento: %i \n",p1.dia);
printf("Mes de nacimiento de la persona:%i \n",p1.mes);
printf("Año de nacimiento de la persona: %i ",p1.anio );
    
    return 0;
}

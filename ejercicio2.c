#include
int main(int argc, char const *argv[])
{

char nombre[100] = "ejercicio1.txt" ;
FILE *p;

p = fopen(nombre,"r") ;

if (p == NULL)
{
printf("No se pudo abrir correctamente \n");
}
else{ printf("Se abrio correctamente \n");}



printf("Las cadenas ingresadas son: \n") ;

fgets(nombre,100,p);

printf("%s \n",nombre);




fclose(p);

return 0;
}

#include #include #include
int main(int argc, char const *argv[])
{
char nombre[] = "ejercicio1.txt" ;
FILE *p;



p = fopen(nombre,"w");

if (p == NULL)
{
printf("No existe,se lo creara");

}
else{ printf("Se creo correctamente");}

printf("Ingrese la cadena, debe ingresar unan por una cada cadena, hasta ingresar la cadena FIN ");

fgets(nombre,100,stdin); // ingreso la cadena


nombre[strlen(nombre)-1]='\0' ; // saco la barra

fputs(nombre,p);

fclose(p);

return 0;
}

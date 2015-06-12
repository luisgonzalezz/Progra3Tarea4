#include "Evaluador.h"
#include <fstream>
#include <math.h>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{  ofstream out;  //Se declara el ofstream
    out.open(nombre_archivo.c_str()); //Se abre el archivo con el ofstream
    out<<num; //Se ingresa el parametro "num" al archivo
    out.close();  //Se cierra el archivo
}
int leerNumeroTexto(string nombre_archivo)
{   ifstream in;  //Se declara el ifstream
     in.open(nombre_archivo.c_str()); //Se abre el archivo con el ifstream
     int numero; //Se declara una variable
     in>>numero; //Se ingresa la lectura a la variable

    return numero; //retorna la variable con la lectura
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{  ofstream out; //Se declara el ofstream
   out.open(nombre_archivo.c_str()); //Se abre el archivo con el ofstream
   out<<str; //Se ingresa el parametro "str"
   out.close(); //Se cierra el ofstream
}
string leerStringTexto(string nombre_archivo)
{  ifstream in; //Se declara el ifstream
   in.open(nombre_archivo.c_str()); //Se abre el archivo con el ifstream
   string texto; //Se declara una variable
   in>>texto; //Se ingresa la lectura a la variable

   return texto; //retorna la variable con la lectura
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{  ofstream out; //Se declara el ofstream
   out.open(nombre_archivo.c_str()); //Se abre el archivo con el ofstream
   out.write((char*)&num,4); //Se escribe el parametro "num"
   out.close(); //Se cierra el ofstream
}
int leerNumeroBinario(string nombre_archivo)
{  ifstream in;  //Se declara el ifstream
   in.open(nombre_archivo.c_str()); //Se abre el archivo con el ifstream
   int *numero_leido=new int; //Puntero para almacenar lo leido
   in.read((char*)numero_leido,4); // Almacena los datos en la variable

   return *numero_leido; //retorna la lectura
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
   ofstream out; //Se declara el ofstream
   out.open(nombre_archivo.c_str()); //Se abre el archivo con el ofstream
   out.write(str.c_str(),10); //Se escribe el parametro "num"
   out.close(); //Se cierra el ofstream
}
string leerStringBinario(string nombre_archivo)
{
 ifstream in;  //Se declara el ifstream
   in.open(nombre_archivo.c_str()); //Se abre el archivo con el ifstream
   char *texto_leido=new char[10]; //Puntero para almacenar lo leido
   in.read((char*)texto_leido,10); // Almacena los datos en la variable

   return texto_leido; //retorna la lectura
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
  ifstream in;  //Se inicializa el ifstream
  in.open(nombre_archivo.c_str());  //Se abre el archivo
  string texto; //Variable para almacenar los datos del archivo
  in>>texto;  //Se almacena
  if(texto==str) //Se compara si encuentra str en la variable texto
  return true;  //Si se cumple retorna true
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
   ifstream in;  //Se declara el ifstream
   in.open(nombre.c_str()); //Se abre el archivo con el ifstream
   int numero_leido; //variable para almacenar el numero leido

  in.seekg(0,ios::end); //Se va al final del archivo
  int tamano = in.tellg()/4;  //Se divide el archivo para saber el tamaño
  in.seekg(0,ios::beg);  //Vuelve al principio

  int mayor=0; //Variable para almacenar el mayor
  for(int i=0;i<tamano;i++)  //Ciclo para recorrer el archivo
  {
  in.read((char*)&numero_leido,4);  //Lee y almacena el numero leido
  if(numero_leido>mayor) //Se hace la condicion para saber cual es mayor
  mayor=numero_leido;  //Si cumple la condicion la variable "mayor" es reemplazado por el numero_leido
  }
   return mayor; //retorna el numero mayor
}




int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

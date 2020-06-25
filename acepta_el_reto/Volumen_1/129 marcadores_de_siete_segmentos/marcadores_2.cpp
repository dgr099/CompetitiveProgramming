
//2 5 2 5 -> 4 + 10 <-> 14*3=42
/**Planteamineto logico
 * Lo de programación dinamica es una gilipollez, son solo 11 casos que ya ves tu, los if me consumen reendimiento y ademas del mismo numero al mismo numero son 0 cmbios y meter mas if son tonteria    
 * * ---
   * --1
   * -12
   * 123
   * 23-
   * 3--
   * ---
   * Tienes que calcular todos los cambios
   * Al desplazarse de derecha a izquierda, siempre ocurre que el numero n sustituye al numero n-1
   * si te fijas en este caso, el 2 siempre sustituye al 1, el 1 siempre sustituye a la nada y asi.
   * ¿Cuántas veces el 1 sustituye a la nada? tantas como long del cartel, en este caso 3 veces
   * Que el uno sustituya a la nada implica 2 cambios
   * Que el 2 sustituya al 1 implica 5 cambios
   * Que el 3 sustituya al 2 implica 2 cambios
   * Que cualquier numero desaparezca no cuenta como cambio
 *              
 *              
 * 
 *                              todos los cambios se producen el numero de la longitud es decir, el 1 sustituye a la nada 3 veces, el 2 al 1 3 veces, el 3 al 2 3 veces y la nada al 3 otras 3 veces
 * 
 * 
 * */
#include <iostream>
#include <vector>
using namespace std;
int main(){
  int cambios[11][11]; //hay 11 origenes y 11 destinos diferentes 
  //voy a omitir el uso de vectores, realmente solo me interesan los dos ultimos numeros
  //vector<int> numeros; //utilizo un vector porque desconozco el ancho max
  int aux, aux_2; //utilizo un int porque los numeros son de 0 a 9 no me preocupa un overflow, sirven para identificar el nuevo numero y el anterior
  int ida; //aquí empleo un int porque desconozco el ancho entonces pueden liarmela y producir overflow
  int ct; //cambios totales
  //lo primero que hare sera calcular todos los cambios para asi ahorrarme los if, en este caso creo que no me rents la programacion dinamica
  int fa[11][7]={ //aqui guardo los filos activos para cada numero empezando por el 0
  {1, 1, 1, 1, 1, 0, 1}, //el 0 que son todos activados menos el del medio
  {0, 0, 0, 1, 1, 0, 0}, //el 1 solo activados el 4 y 5
  {0, 1, 1, 0, 1, 1, 1}, // el 2 el 2, 3, 5, 6, 7
  {0, 0, 1, 1, 1, 1, 1}, //el 3 todos menos el 1 y 2
  {1, 0, 0, 1, 1, 1, 0}, //el 4 todos menos el 2, 3, 7
  {1, 0, 1, 1, 0, 1, 1}, //el 5 todos menos el 2 y 5
  {1, 1, 1, 1, 0, 1, 1}, //el 6 todos menos el 5
  {0, 0, 0, 1, 1, 0, 1}, //el 7 como el 1 usando el 7
  {1, 1, 1, 1, 1, 1, 1}, //el 8 todos activados
  {1, 0, 1, 1, 1, 1, 1}, //el 9 todos menos el 2
  {0, 0, 0, 0, 0, 0, 0}, //la nada :-)
  };
  /*   __       7
      |  |  1       5
      |  |      
      |__|      6
      |  | 
      |__|  2       4
                3
  
  */
  for(aux=0; aux!=11; aux++){
    for(aux_2=0; aux_2!=11; aux_2++){
      for(ct=ida=0; ct!=7; ct++){
        if(fa[aux][ct]!=fa[aux_2][ct])
          ida++;
      }
      cambios[aux][aux_2]=cambios[aux_2][aux]=ida; //el pasar de un 2 a un 3 es lo mismo que de un 3 a un 2
    }
  }

  while(cin>>aux_2 && !(aux_2==-1)){
    ct=0; //reinicio el contador de cambios
    //Esto lo puedo omitir creo pero me viene bien 
    //aux=10;
    ida=1; //reiniciamos los valores de ida    
    ct+=cambios[aux_2][10]; //los cambios que produce cambiar la nada por el primer numero

    while(cin>>aux && !(aux==-1)){
      ida++; //sumamos 1 a la ida (la ida cuenta la longitud del cartel e indice del vector)
      ct+=cambios[aux][aux_2]; //sumo los cambios de pasar al nuevo numero desde el anterior
      aux_2=aux; //en aux_2 siempre guardo el numero anterior a aux
    }
    //aux=10; //cambiamos el -1 por la nada
    ct+=cambios[10][aux_2]; //los cambios que produce cambiar el ultimo numero por la nada
    ct*=ida;
    cout<<ct<<endl; //el indice empieza en 0 pero hay dos numeros más en los vectores a comparacion con la longitud que son las nadas que los envuelven
    //realmente tambien se podria omitir introducir la nada empleando los aux_2 y utilizando al principio y al final la comparación con el 10 ("la nada") sin tener que añadirlos en el vector
  }
  return 0;
}

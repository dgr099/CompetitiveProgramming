/*
 * Hay 4 casos posibles pues:
 *  -Si se encuentra en la diagonal directa con un movimiento llegas a donde quieres
 *  .Si no se encuentra en la diagonal directa y no esta en un cuadrado de distinto color 2 movimientos puede llegar
 *  -Por último, si está en un cuadrado de distinto color jamás podrá llegar
 *  -Que ambos esten en la misma posicion
*/
#include <iostream>

using namespace std;
int main(){
  pair<long long, long long> cor_in, cor_fin; //cordenadas inicio y final (las cordenadas son x, y y van de 0 a n-1)
  long long acera;//numero de baldosas
  int pasos;
  while(cin>>acera && !(acera==0)){
    cin>>cor_in.first>>cor_in.second>>cor_fin.first>>cor_fin.second; //guardamos las posiciones
    /** Como sabes que se encuentra en un cuadrado de distinto color?
     * __________
     * |02|12|22|
     * |01|11|21|
     * |00|10|20|
     * unos colores tienen suma de coordenadas par y otros impar con eso ya sabes si se trata de un color u otro
     * */
    if( ((cor_in.first + cor_in.second)%2) != ((cor_fin.first + cor_fin.second)%2) ){
      cout<<"IMPOSIBLE"<<endl; //si está en otro color es imposible que pueda llegar
      continue;
    }
    //si estamos en la misma posicion con 0 movimientos lleva al destino
    if(cor_in.first == cor_fin.first && cor_in.second == cor_fin.second){
        cout<<"0"<<endl;
        continue;  
    }
    /**
     * el siguiente paso es saber si se puede hacer en un movimiento o por el contrario requiere de 2
     * Requerira de solo un movimiento si el destino se encuentra en las diagonales del inicio
     * |03|13|23|33|
     * |02|12|22|32|
     * |01|11|21|31|
     * |00|10|20|30|
     * ¿Cómo sé si está en diagonal?
     * Está en diagonal si es la misma la variacion de x que de y
     * estan en diagonal si x+z, y+z=x_2, y_2---->x+z=x_2--->z=x_2-x si las z coinciden se encuentran en diagonal
     */
      if(abs(cor_fin.first - cor_in.first) == abs(cor_in.second - cor_fin.second)){
        cout<<"1"<<endl;
        continue;
      }
      //si no está en diagonal y es posible llegar significa que deben ser dos movimientos
      else{
        cout<<"2"<<endl;
        continue;
      }
    }
  return 0;
}
/*

     * |03|13|23|33|
     * |02|12|22|32|
     * |01|11|21|31|
     * |00|10|20|30|
     * 
* */
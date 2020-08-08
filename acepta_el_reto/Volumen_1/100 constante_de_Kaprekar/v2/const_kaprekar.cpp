twitter/insta: @dgr_099 ;-)
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
#define NUM_MAX 4
int main(){
  int j=0, i=0, z=0, vueltas=0, h=0, pos, maximo[4], min[4];
  bool ordenado=false;
  long long o, inv;
  string der, max;
  cin >> i;
  for(j=0; j!=i; j++){/*por cada uno de los números de 4 bits ejecutas las acciones principales*/
    cin >> o; 
    vueltas=0;  /*inicializa las vueltas a 0*/
    if(o==6174){ /*si resulta que el número es la propia constante imprime directamente 0*/
      goto fin_bucle;
      continue;   
    }

    if(o==0){
        vueltas=8;
        goto fin_bucle;
    }

    while(o!=6174){ /*mientras que el numero no sea la const*/
      der.clear();/*reseteamos las strings*/
      max.clear();   
      /*rellenamos el string añadiendo los 0 necesarios con ayuda de max*/
      while(o<1000){
        o*=10; //vas desplazando un bit a la izquiera hasta rellenar todos los bits necesarios*/
      }
      der=to_string(o);
      /*if(o<10){
        for(z=0; z!=3; z++){
          der+='0';
        }
        der+=max;

      }
      else if(o<100){
        for(z=0; z!=2; z++){
          der+='0';
        }
        der+=to_string(o);
      }
      else if(o<1000){
        for(z=0; z!=1; z++){
          der+='0';
        }
        der+=to_string(o);      
      }
      else{
        der=to_string(o);
      }*/

      /*
      max[0]=der[0]+'0';
      max[1]=der[1]+'0';
      max[2]=der[2]+'0';
      max[3]=der[3]+'0';
      */
      ordenado=false;
      while(ordenado!=true){ /*ordenamos por metodo burbuja apoyándonos en max*/
      ordenado=true;
        for(z=0; z!=NUM_MAX; z++){
          if(der[z]<der[z+1]){
            max[0]=der[z+1];
            der[z+1]=der[z];
            der[z]=max[0];
            ordenado=false;
          }
        }
      }

      max=der;
      for(z=0; z!=2; z++){
        swap(der[z], der[4-z-1]);
      }

      if(max.compare(der)==0){/*compruebas que no sean iguales, en cuyo caso se trataria de un repdigits*/
        vueltas=8;
        goto fin_bucle;
      }
      o=atoll(&max[0]);
      inv=atoll(&der[0]);
      o=o-inv;
      vueltas++;
    }
    fin_bucle:
    cout<< vueltas << endl;
  }
  return 0;
}

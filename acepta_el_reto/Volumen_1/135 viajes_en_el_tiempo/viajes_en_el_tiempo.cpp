/** Planteamiento
 * 1-5
 * 4 numeros de diferencia
 * 5-7
 * 2 numeros de diferencia //1ºcambio
 * 7-9
 * 2 numeros de diferenca
 * 9-11 
 * 2 numeros de diferencia
 * 1 cambio y el siguiente numero es 11+constante_ultima=13
 * 
 * lo complicado aqui es que es una maquina circular pero eso con el modulo se arregla
 * 
 * 10->9
 * el cambio es -1
 */
typedef long long ll;
#define masi 1000000
#include <iostream>
using namespace std;
ll modulo(ll a, ll b){
  ll r = a%b;
  return r<0?r+b:r; //si r es negativo le sumas la "base"
}
int main(){
  ll cambios, numero, cons, casos, aux, cons_2;
  cin>>casos;
  while(casos--){ //mientras que aun haya casos de prueba
    cambios=0; //iniciamos los cambios a 0
    cin>>aux>>numero;
    cons=modulo((numero-aux), masi); //calculas la constante original
    aux=numero; //en aux guardamos el numero anterior
    while(cin>>numero && numero!=-1){ //mientras lea numeros y el numero no sea el de final
      cons_2=modulo((numero-aux), masi); //miramos el cambio (la nueva constante)
      if(cons_2!=cons){ //cada vez que la constante cambie
        cambios++;
        cons=cons_2;
      }
      aux=numero; //en aux guardamos el anterior
    }
    printf("%lld %lld\n", cambios, modulo((aux + cons), masi)); //aux es el ultimo numero distinto de -1 del que se tiene conocimiento

  }
  return 0;
}
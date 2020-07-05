/**4 niños, se elimina de 1 en 1
 * se elimina el numero 2, y 4; falta el 1 y 3
 * se elimina el 3 el 1 es al que le toca
 * 
 */ 
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int num, saltos;
  while(cin>>num>>saltos && (num!=0)){
    if(!saltos){
      printf("%d\n", num); //si te vas eliminando a ti mismo el el ultimo en ser borrado será el ultimo
      continue;
    }
    int i=1;
    list<int> lista;
    for(i; i<=num; i++){
      lista.push_back(i);//insertas los numeros
    }
    while(lista.size()!=1){ //mientras que no quede solamente uno
      int aux;
      for(i=0; i!=saltos; i++){
        aux=lista.front();
        lista.pop_front();
        lista.push_back(aux);
      }
      lista.pop_front();
    }
    printf("%d\n", lista.front());
  }
  return 0;
}
/**Estoy 300% seguro que esto se tiene que hacer con formulas matemáticas
 * tienes 10^5 numeros por tanto un n^3 lo maximo que a lo mejor entra será un n^2 en 2/3 segundos
 * 1 2 3 4 5 6 7 8 9 10
 * primero se eliminan los impares (1 de cada 2)
 * 2 4 6 8 10
 * de estos se eliminan cada 3
 * 4 6 10
 * ahora seria uno cada 4 pero eso es menor que los 3 elementos que quedan, asi que todo piola
 * 100% debe existir una formula matematica pero no caigo, parece que el tiempo da cierto juego, y creo un bucle entra en tiempo asi que lets try ;-)
 * vamos a ir eliminando
 */
#include<bits/stdc++.h> 
using namespace std;
int main(){
  int num;
  while(cin>>num && num){ //mientras que leas un numero distinto de 0 podemos aplicar todo
    vector<int> vl(num); //creo un vector y lo comienzo inicializando a 0(similar a trabajar con arrays dinamicas usando calloc)
    int i, j, cont=0;
    for(i=2; i<=num; i++){ //cada 1 de cada i numeros se eliminan
     //if(count(vl.begin(), vl.end(), 0)<i) break; //si no hay sufientes numeros terminamos
      for(j=cont=0; j!=num; j++){ if(vl[j]==0) cont++; if(cont>=i) break;}
      if(i>cont)  break;
      for(j=cont=0; j!=num; j++){ //recorremos toda la tabla eliminando los numeros
        if(vl[j]==0){ //si estamos ante un numero que antes era válido
          if((cont)%(i)==0){ //si se han contado tantos true como son necesarios 
            vl[j]=1; //eliminamos ese valor al ya no ser valido
          }
          cont++;
        }
      }
    }
    cout<<num<<":";
    for(vector<int>::reverse_iterator p=vl.rbegin(); p!=vl.rend(); p++, num--){
      if((*p)==0){
        cout<<" "<<num;
      }
    }
    cout<<endl;
  }
  return 0;
}
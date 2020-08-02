/*planteamiento
en el intervalo de 1 a 9 ganaria el 1º dado que puede conseguir cualquier numero en el rango entre 2 y 9 y por tanto puede superar o igualar cualquier nummero de ellos
después, en el intervalor de 10 a 18 ganará el 2º pues el menor numero que puede decir el primer jugador es el 2 y al multiplicarlo por 9 que es el máximo del rango de los jugadores obtienes el 18
nuevamente desde 11 hasta 9*2*9 vuelve a ganar el 1º ya que ese es el rango que alcanza desde el 1º valor al que no puede llegar el 2º y el maximo valor que alcanza con el menor numero escogido por el 2º


*/
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
  long long cas, num;
  pair<string, string> names;
  cin>>cas;
  while(cas--){
    string aux; long long aux_2; //variables auxiliares
    cin>>names.first; cin>>names.second; //guardas los nombres
    cin>>num>>aux;
    if(aux!=names.first)  swap(names.first, names.second); //quiero tenerlos ordenados en funcioón de quien empiece
    long long i;
    for(i=0, aux_2=1; num>aux_2; i++){ //vamos a ir mirando los rangos que abarca cada jugador
      if(!(i%2)){ //si i es par quiere decir que nos encontramos en un rango del jugador 1
        aux_2*=9;  
      } else  aux_2*=2;
    }
    ((i%2==0) ? printf("%s ha perdido :(\n", &names.first[0]) :  printf("%s ha perdido :(\n", &names.second[0])); //si es par quiere decir que se encontraba en el rango del 2º y si es impar en el rango del 1º
  }
  return 0;
}

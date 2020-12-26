/**¡recuerda! longitudes enteras
 * suma de las longitudes de los lados de todos los triangulos
 */ 
#include <bits/stdc++.h>
using namespace std;
long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) { //cuando llegue la potencia a 0 retornas el mismo numero
/*si no es impar por ejemplo 4, calculara el 2, no aplicará nada, calculará el 2 del 2 (la 4) y hay el exponente sera 1 (impar)*/
        if(power % 2 == 1) { //si la potencia es impar significa que tiene k^1 por ejemplo k^3=k^2*k
            result = (result*base); //aplicamos ese k^1
        }
        base = (base * base); //se eleva la base al cuadrado (se calcula k^2) (luego se volverá a calcular el cuadrado obteniendo k^4...)
        power = power / 2; //la parte decimal la saltará
    }
    return result;
}

int main(){
  fast_power(2, 3);
  fast_power(2, 4);
  int tam;
  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
  while(cin>>tam){
    int area=0;
    for(int i=0; tam>=1; i++){
      area+=4*tam*fast_power(4,i);
      tam/=2;
    }
    printf("%d\n", area);
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  cout.tie(NULL);
  int o, f;
  while(cin>>o>>f && !(o==0 && f==0)){
      /**Posibilidades 
       * f > o ---> la distancia entre f y o, o puede que te rente más bajar hasta dar la vuelta
       * f < o ---> dos opciones, tal vez te rente más avanzar hasta dar la vuelta o retroceder
       * 
       */ 
      if(f>o){
        printf("%d\n", min(f-o, (o + 99 - f))); //si es subiendo pues f-o, si es bajando, retrocedes el numero que tienes y a eso le sumas la distancia desde el 99 hasta el numero
      }
      else{ //caso o mayor que f
        printf("%d\n", min((o-f), (99 - o + f))); //si es bajando pues es solo la diferencia
      }
  }
  return 0;
}
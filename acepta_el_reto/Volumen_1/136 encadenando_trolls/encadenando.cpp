/** Planteamiento logico
 * se divide haciendo una cadena el doble de larga que la otra
 * huele un poco a recursividad :-)
 * 2*x+y=z como dividimos la cadena
 * las podemos dividr en tres partes y que una sea 2/3 y la otra 1/3
 * 
*/
typedef long long ll;
#include <iostream>
#include <cmath>
using namespace std;
ll personas(const ll *f_h, long cadena){
  if(((double)cadena /(*f_h))<=2){
    return 0;
  }
  return personas(f_h, cadena/3) + personas(f_h, ceil(2*(double)cadena/3)) + 1;

}
int main(){
  ll f_h=0, esla=0;
  while(scanf("%lld", &f_h) && f_h!=0){
    scanf("%lld", &esla);
    printf("%lld\n", personas(&f_h, esla));
  }
  return 0;
}
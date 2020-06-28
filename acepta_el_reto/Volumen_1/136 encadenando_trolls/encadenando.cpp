/** Planteamiento logico
 * se divide haciendo una cadena el doble de larga que la otra
 * huele un poco a recursividad :-)
 * 2*x+y=z como dividimos la cadena
 * las podemos dividr en tres partes y que una sea 2/3 y la otra 1/3, al se long long va a quitar la parte decimal por ello hacemos el cast a double
 * 
*/
typedef long long ll;
#include <iostream>
#include <cmath>
using namespace std;
ll personas(const ll *f_h, long cadena){ //empleo un puntero para ahorrar memoria
  if(((double)cadena /(*f_h))<=2){ //comprobamos si uno solo es capaz de llevar la cadena, (el cast es importante para no perder parte decimal)
    return 0;
  }
  return personas(f_h, cadena/3) + personas(f_h, ceil(2*(double)cadena/3)) + 1; //la cadena no se puede cortar es 1/3 con decimales, deben ser eslabones enteros
//es por ello quue en la segunda lo hago double para que me de decimales y ceil para obtener la parte superior (es como si sumara los decimales perdidos de la primera divisón y los que se perderían en la segunda=
}
int main(){
  ll f_h=0, esla=0;
  while(scanf("%lld", &f_h) && f_h!=0){ //mientras tenga casos de prueba
    scanf("%lld", &esla); //leo el número de eslabones
    printf("%lld\n", personas(&f_h, esla)); //llamo a la función recursiva
  }
  return 0;
}

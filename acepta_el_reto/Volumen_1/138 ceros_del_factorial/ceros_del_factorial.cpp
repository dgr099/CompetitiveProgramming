/**David Teófilo Garitagoitia Romero @dgr_099
 * 10->(5*2)
 * precisamente son 32 los bits de un entero->2*^31 son los numeros que puede representar
 * por lo que podemos emplear un entero sin problema
 * recuerdo el problema nº 126 que es interesante para pensar en este
 * el factorial más pequeño que contiene un 0 es el 5
 *  5!=5*4!=24*5=120
 * por tanto dado que el factorial es n*n-1*.....*1
 * el factorial de 6 = 6->(3*2) * 5! tiene un 0 al final al multiplicarlo por 120=12*10
 * 7->primo, 8->4*2, 9->3^2 con ninguna mezcla de las operaciones logramos un múltiplo de 10 al carecer de 5 ya que cualquier multiplo de 10 será 5*2*x nuevamente por lo que tambien tienen solo 1 0 al final
 * 10 es el primer numero que multiplica por 10 2 veces su factorial y por ende que tiene 2 ceros al final 10!=10*9*8**...*5!
 * el 11! es 11(primo)*10! por tanto mantiene unicamente 2 ceros...
 * 15 = 15*14*13*12*11*10!; 15*14=(3*5)(7*2)->(21*10) es el primer numero que multiplica por 10 3 veces y por ende al final tiene 3 ceros 
 * con el 20 llegas a 2*10 un 10 mas que se une al 19! que tiene 2 ceros de esa forma aqui tienes 4 ceros
 * Por tanto para obtener el siguiente 0 necesitas volver a multiplicar por un 10 que es 5*2 por tanto el inmediatamente factorial posterior con un 0 más al final debe ser múltiplo de 5
 * ya que cualquier numero mayor que 2 tendra un factorial par al estar multiplicando por 2, del 5 a 5*2 hay 10/2-5/2=3 numeros pares (es decir que son multiplos de 2) por tanto los unicos casos en los que tiene lugar una nueva multiplicación por 10 son los multiplos de 5
 * que son los unicos en los que hay un nuevo 5 y un nuevo 2 multiplicando
 */
#include <iostream>
using namespace std;
int main(){
  int casos;
  scanf("%d", &casos);
  while(casos--){
    int num=0, ceros_counter=0;
    scanf("%d", &num);
    while(num>=5){ //mientras que aun puedas dividir entre 5
      num/=5;
      ceros_counter+=num;     
    }
    printf("%d\n", ceros_counter);
  }
  return 0;
}
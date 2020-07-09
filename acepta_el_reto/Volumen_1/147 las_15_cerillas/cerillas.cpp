/** Inicio->| | | | |                     quita 2
 *                                        --->  | | mi turno(quito 1)  || -->| pierde el contrario (hay una opcion de ganar)
 *                                       |
 * mi turno (quito 1)->| | | |su turno---| 
 *                                       |quita 1
 *                                        ---> | | | ---> mi turno (quito 1)--> | |
 * 
 * lo que pide es mantener la esperanza, no la certeza de una victoria, en que casos pierdo seguro???
 * cuando pierdes seguro????
 * ->en el caso en el que sin importar lo que quites, el rival sea capaz de dejar una, entonces definitivamente pierdes
 *    por ejemplo 4 y puedes quitar como máximo 2 (en 1 movimiento lo tienes), no importa si quitas 1 (y dejas 3) o si quitas 2 y dejas 2, el rival es capaz de dejarte en 1 (quitando 2 y 1 respectivamente)
 *    ejemplo en 2 movimientos
 *                                                
 *                                     |-->6    aqui me vale con quitar 2 y vuelvo al caso 4 y 2 de arriba  |
 *                                     |                                                                    |
 *    por ejemplo 7 y puedo quitar 2---                                                                      ---->sin importar que haga vuelvo al caso en que pierdo
 *                                     |                                                                    |
 *                                     |-->5 aqui me vale con quitar 1 y vuelvo al caso 4 y 2 de arriba-----|
 * 
 * 
 *  
 * ejemplo en 3 movimientos
 *                               -->9 quitas 2 y llegas al caso de 7-   
 *                              |                                   |
 *                              |                                   |
 * 10 cartas y puedo quitar 2---                                    |--->sin importar lo que hagas acabas llegando al caso enn el que pieres
 *                              |                                   |
 *                              |                                   |
 *                               -->8 quitas 1 y llegas al caso de 7-
 * 
 * etc etc... esos son los casos que pierdo en los que puedo quitar 2 cartas, simplifiquemos más, caso en el que puedo quitar solo 1 carta (me veo obligado si o si a quitar)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  int cerillas, max, res;
  while(cin>>cerillas>>max){
    /**La formula que se aplica realmente es sencilla, 
     * si lo piensas imagina que tiene 100 cerillas y 5 por movimiento, 
     * realmente el limite está cuando queden 5 cerillas y 5 por movimiento 
     * y debes saber que ocurre
     * 
     * De esta manera se justifica el % que se aplica. 
     * Por eso mismo se cogen las cerillas totales %  
     * cerillas que se pueden quitar + 1 de esta forma, si da == 0
     * significa que jugando perfecto, el otro jugador nos ganará
     * 
     * el +1 significa que quita la última el otro jugador
     */ 
    ((res=(cerillas-1)%(max+1))==0 ? printf("PIERDO\n") : printf("%d\n", res));
  }
}
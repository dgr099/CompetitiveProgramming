/**- ->inicio
 * + -> fin
 * * -> f->
 * 3 -> supr
*EDA  |->c
 * ->EDA|
 * 
 * EDA-333
 * |EDA->|DA->|A->|
 * 
 * dD-3*A-E+
 * dD     -3  * A       -   E     +
 * |dD-->|D->D|->DA|->|DA->E|DA->ED|A   
 * 
 * ADA*3A
 * ADA|->AD|->ADA
 * 
 * EDA-3E*3A
 * EDA|-->|EDA->|DA->E|DA->ED|A->ED|->EDA
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
  string entr;
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  //cout.tie(NULL);
  while(getline(cin, entr)){
    int cursor=0, fin=entr.size();
    for(int it=0; it!=entr.size(); it++){ //en it se guarda el iterador de la entrada y en cursor la posicion del cursor
      /*if(cursor>it){
        cursor=it;
      }*/
      /*if(cursor<0){
        cursor=0;
      }*/
      if(entr[it]=='-'){
        entr.erase(entr.begin()+(it--));  cursor=0; continue; //borramos el - y colocamos el cursor en el 0
      }
      if(entr[it]=='+'){
        entr.erase(entr.begin()+(it--));  (it<0 ? cursor=0 : cursor=it+1);  continue; //borramos el + y colocamos el cursor al final (en el iterador de entrada)
      }
      if(entr[it]=='*'){
        entr.erase(entr.begin()+(it--));  (it<0 ? cursor=0 : it==cursor-1 ? cursor=it+1 : cursor++); continue; //eliminamos el * y sumamos uno en la posicion del cursor
      }
      if(entr[it]=='3'){
        entr.erase(entr.begin() + (it--)); //borramos el 3 (la entrada) y restamos uno en la posición al global al perder 1 en el total
        if(cursor==it+1) continue;//(si el cursor y el iterador estaban apuntando a la entrada y al quitar el 3 el cursor esta por delante (por eliminar el 3)) 
        entr.erase(entr.begin()+(cursor));  it--; //borramos una letra
        continue;
      }
      if(cursor<it){ //si estan en posiciones diferentes es que estas escribiendo en otra posicion a la de la entrada
        entr.insert( entr.begin()+cursor, entr[it]); //insertas el caracter que lee la entrada en la posicion del cursor
        entr.erase(entr.begin() + ++it); //borras ese iterador (sumas 1 porque en el global se añade uno debido a la insercción)
        it--; //restas 1 debido a que se ha perdido uno del total
      }
      cursor++; //en cualquier otro caso has introducido una letra del teclado normal y corriente, sigues como si nada
    }
    printf("%s\n", &entr[0]);
  }
  return 0;
}
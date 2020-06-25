/** Planteamiento
 * te piden comprobar si todas las letras son las mismas o no
 *  y debes hacerlo de forma eficiente (no es eficiente meterte en un bucle comprobando letra a letra para cada caso)
 * en todos los casos te piden lo mismo pero para indices diferentes, debe haber alguna forma de hacerlo de una vez
 * 
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
  string palabra;
  int i, j, z, ind_abs, ind_max, size; //z son los casos de prueba
  vector<int>::iterator ind_aux;
  vector<int> ind; //en ind vamos a ir guardando la posicion de las nuevas palabras
  char aux, aux_2;
  while(getline(cin, palabra)){
    ind.clear(); //limpio mi vector
    ind.push_back(0);
    for(aux=palabra[0], size=0, ind_abs=1, ind_max=palabra.size(); ind_abs!=ind_max; ind_abs++){
      aux_2=palabra[ind_abs];
      if(aux_2!=aux){ //si estamos ante una nueva letra
        aux=aux_2;
        size++;
        ind.push_back(ind_abs); //inserto el punto donde se introduce una nueva variable
      }
    } //sl terminar ya tengo un vector con todas las posiciones criticas
    if(cin>>z && z==0){
      break;
    }
    for(ind_abs=0; ind_abs!=z; ind_abs++){ //empleo el ind_abs por no crear otra variable jajaja
      scanf("%d %d", &i, &j); //leo las posiciones en cuestion
      if(i>j)
        swap(i, j);
      ind_aux=upper_bound(ind.begin(), ind.end(), i); //busco la posicion del ultimo cambio ántes del extremo
      ind_max=ind_aux-ind.begin();
      if((ind_max>size || ind_max<0)){
        printf("SI\n");
        continue;
      }
      else if((ind[ind_max]>i && ind[ind_max]<=j)){ //si el valor del cambio esta entre los valores posibles
        printf("NO\n");
        continue;
      }
      printf("SI\n");
    }
    printf("\n");
    cin.ignore();
  }
  return 0;
}
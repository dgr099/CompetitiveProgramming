#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool comp_pair(pair<pair<long long, string>, long long> &left, pair<pair<long long, string>, long long> &right){
  if(left.second>right.second){
    return true;
  }
  else if(left.second==right.second){
    if(left.first.first<right.first.first)
      return true;
    return false;
  }
  return false;
}

int main(){
  long long num, index, j=0, index_1=0, tam=0, aux_1=0, i, z;
  string aux;
  vector<pair<pair<long long, string>, long long>> vs; //vector donde guardo orden de aparicion, nombre, veces que aparece
  map<string, pair<long long, long long>>prendas;// nombre, orden de aparicion veces que aparece
  scanf("%lld\n", &num);
  for(i=1; i!=num+1; i++){ //por cada una de las prendas
    getline(cin, aux); //lees la prenda
    prendas[aux].second++; //sumas 1 a las apariciones de esa prenda 
    if(!prendas[aux].first){ //pones el indice de aparición
      prendas[aux].first=i;  
    }
  }

  //al llegar a este punto debes tener un mapa con las veces que aparece cada prenda
  scanf("%lld", &index); //escaneas la posicion que llamaremos indice

  i=0;
  for(auto p : prendas){
    vs.push_back(make_pair(make_pair(p.second.first, p.first), p.second.second)); //aqui conseguiemos un vector con todas las string y sus apariciones
    i++;
  }

  tam=vs.size(); //vemos cuantas prendas hay en total

  sort(vs.begin(), vs.end(), comp_pair);//ordenamos el vector de mayor a menor y en orden de inserccion


  for(i=0, aux_1=vs[0].second, index_1=0, tam=vs.size(); index_1!=index && tam>i; i++){ //buscamos la posición que te pide
    if(aux_1!=vs[i].second){ //si las apariciones son distintas tenemos una nueva posicion
      aux_1=vs[i].second; //cambiamos el aux
      index_1++; //sumamos 1 al indice aux de posiciones
    } 
    if(index_1==index-1){ //si estamos en el mismo del ejercicio
      z=i; //marcas el indice de inicio en el que ocurre esto
      while(aux_1==vs[i].second){ //mientras que las apariciones sean las mismas que las del inicio de la pos significa que seguimos en la pos
        j++; //sumamos uno al numero de posiciones
        i++; //sumamos al posicionamiento absoluto en el vector para seguir comprobando más posiciones
      }
      break;
    }
  }
  printf("%lld\n", j); //imprimimos la cantidad que hayamos obtenido
  for(i=0; i!=j; i++, z++){
    cout<<vs[z].first.second<<endl; //desde el indice marcado vamos imprimiendo esas prendas
  }
  return 0;
}

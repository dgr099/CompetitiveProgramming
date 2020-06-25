#include <iostream>
#include <vector>
using namespace std;
int main(){
  long long h_1, h_2, kim;
  vector<pair<long long, long long>> km; //en el primer long guardo la distancia y en el segundo el km de inicio
  while(cin>>h_1 && !(h_1==-1)){
    kim=0;
    km.clear();
    km.push_back(make_pair(0, 0));
    km.push_back(make_pair(0, 0));
    while(cin>>h_2 && h_2!=-1){
      kim++;
      if(h_2==h_1){ //si son iguales se suma 1 al numero de km a esa altura
        km[1].first++;
      }
      else{ //si no son iguales
        if(km[0].first<km[1].first){ //si se han alcanzado más km a la nueva altura se actualiza
          km[0].first=km[1].first;
          km[0].second=km[1].second;
        }
        km[1].second=kim; //se vuelve a formatear el anterior km
        km[1].first=0;
      }
      h_1=h_2; //guardas el valor del km anterior
    }
    //compruebas por si el ultimo dato es el mayor
    if(km[0].first<km[1].first){ //si se han alcanzado más km a la nueva altura se actualiza
      km[0].first=km[1].first;
      km[0].second=km[1].second;
    }
    //al terminar todo imprime los datos
    if(km[0].first<1){
      cout<<"HOY NO COMEN"<<endl;
      continue;
    }
    cout<<km[0].second<<" "<<km[0].first<<endl;
  }
  return 0;
}
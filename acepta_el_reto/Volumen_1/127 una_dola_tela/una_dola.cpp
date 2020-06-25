#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;
int main(){
  long long c_p, c_d, n_p, index, size, cont; //c_d=casos_prueba; c_d=camas_disponibles; n_p=numero_palabras
  string nombre;
  //set<string> nombres;
  //set<string>::iterator it;
  vector<string> nombres;
  cin>>c_p;
  while(c_p--){
    size=0;
    nombres.clear();
    while(cin>>nombre && strcmp(&nombre[0], "F")!=0){ //vas introduciendo los nombres en el vector de nombres
      nombres.push_back(nombre);
      //nombres.insert(nombre);
      size++;
    }
    cin>>c_d>>n_p;
    if(size<=c_d){ //si el tamaño (los nombres) son menos o los mismo que las camas disponibles todos felices
      cout<<"TODOS TIENEN CAMA"<<endl;
      continue;
    }
    else if(c_d==0){ //si las camas son 0 nadie tiene cama
      cout<<"NADIE TIENE CAMA"<<endl;
      continue;
    }
    //it=nombres.begin();
    for(index=0, cont=1; size>c_d; index=(index + 1)%(size), cont++){ //el modulo lo uso para que sea ciruclar
      /*if(index==0){
        it=nombres.begin();
      }*/
      if(cont%n_p==0){ //si estamos en un multiplo del size
        //nombres[index-1]="\0";
        nombres.erase(nombres.begin() + index);
        size--;
        index--;
        cont=0;
      }
    }
    for(cont=0; cont<=size-2; cont++){
      cout<<nombres[cont]<<" ";
    }
    cout<<nombres[cont];
    cout<<endl;
  }
}
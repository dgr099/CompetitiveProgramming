#include <iostream>
#include <map>
#include <string.h>
using namespace std;
int main(){
  string fila;
  map<char, long long>calcetines;
  char *tok;
  while(getline(cin, fila) && fila.compare(".")){
    calcetines.clear();
    tok=strtok(&fila[0], " ");
    calcetines[*tok]++;
    tok=strtok(NULL, " ");
    while(*tok!='.'){
      calcetines[*tok]++;
      tok=strtok(NULL, " ");
    }
    if(calcetines['N']%2!=0){
      if(calcetines['G']%2!=0){
        cout<<"PAREJA MIXTA"<<endl;
        continue;
      }
      cout<<"NEGRO SOLITARIO"<<endl;
      continue;
    }
    if(calcetines['G']%2!=0){
      cout<<"GRIS SOLITARIO"<<endl;
      continue;
    }
    cout<<"EMPAREJADOS"<<endl;
      
  }
  return 0;
}
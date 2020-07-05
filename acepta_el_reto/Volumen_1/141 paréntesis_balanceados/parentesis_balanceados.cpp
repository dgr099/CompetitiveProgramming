#include <bits/stdc++.h>
using namespace std;
bool parentesis(string &str){
  int lon=str.size();
  stack<char> pila;
  for(int i=0; i!=lon; i++){
    if(str[i]=='(' || str[i]=='{' || str[i]=='['){ //si son parentesis de apertura
      pila.push(str[i]); //los metemos en la pila
      continue;
    }
    if(!(str[i]==')' || str[i]=='}' || str[i]==']'))  continue; //si no es parentesis nos importa -3
    if(pila.size()==0)  return false; //si es un parentesis de cierre y no hay nada que cerrar
    if(str[i]==')'){ //si son parentesis de cierre
      if(pila.top()!='('){
        return false; //si no se cierran en orden no estan balanceados
      }
      pila.pop(); //si es de cierre quitamos un parentesis de la pila
      continue;
    }
    if(str[i]=='}'){
      if(pila.top()!='{'){
        return false; //si no se cierran en orden no estan balanceados
      }
      pila.pop(); //si es de cierre quitamos un parentesis de la pila
      continue;
    }
    if(str[i]==']'){
      if(pila.top()!='['){
        return false; //si no se cierran en orden no estan balanceados
      }
      pila.pop(); //si es de cierre quitamos un parentesis de la pila
      continue;
    }      
  }
  return(pila.size()==0 ? true : false);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string case_;
  while(getline(cin, case_)){
    printf(parentesis(case_)==true ? "YES\n" : "NO\n");
  }
  return 0;
}
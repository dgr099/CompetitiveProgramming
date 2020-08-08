twitter/insta: @dgr_099 ;-)
#include <iostream>
#include <string.h>
using namespace std;
int main(){
  int num; cin>>num;
  string nombre;
  char *tok;
  cin.ignore();
  while(num--){
    nombre.clear();
    getline(cin, nombre);
    tok=strtok(&nombre[0], " ");
    tok=strtok(NULL, " ");
    cout<<"Hola, "<<tok<<"."<<endl;
  }
  return 0;
}

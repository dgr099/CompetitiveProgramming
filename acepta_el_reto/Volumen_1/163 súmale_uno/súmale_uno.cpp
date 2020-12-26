#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string entrada;
  while(cin>>entrada && entrada!="FIN"){
    int i=entrada.size()-1; //te colocas en lo ultimo leido que a su vez equivale en el más bajo
    while(entrada[i]=='F' && i>-1){ //si esta en el máximo que es la F, esta pasa a 0 y se suma al siguiente numero
      entrada[i]='0';
      i--; //el siguiente numero que sera el leido anteriormente
    } 
    entrada[i]++; //le sumas 1
    if(entrada[i]>'9' && entrada[i]<'A'){ //si esta en lo que sería un "10" eso hay que pasarlo a numero
    }
    (i==-1 ? printf("1%s\n", &entrada[0]) : printf("%s\n", &entrada[0])); //si era todos FF por ejemplo, estos dos pasan a 0 y se añade el 1 que no se puede colocar en el string al no tener tamaño suficiente por lo que se concatena un 1 al imprimir
  }
  return 0;
}
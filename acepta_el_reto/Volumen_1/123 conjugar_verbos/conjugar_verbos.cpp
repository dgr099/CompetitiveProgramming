//fijandonos en la entrada de ejemplo (viVir se puede ver como mantiene viV) lo que nos da una pista de que los inicios de la palabras hay que mantenerlos
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main(){                                                                                //matriz tridimensional (matriz de matrices), una matriz de 3x3 cada una con 6 elementos (tres matrices de 3x6)
  string palabra, inversa, sujetos[]={"yo", "tu", "el", "nosotros", "vosotros", "ellos"};
  string terminaciones[3][3][6] = {
      {
        {"o", "as", "a", "amos", "ais", "an"},
        {"e", "aste", "o", "amos", "asteis", "aron"},
        {"are", "aras", "ara", "aremos", "areis", "aran"},
      },
      {
        {"o", "es", "e", "emos", "eis", "en"},
        {"i", "iste", "io", "imos", "isteis", "ieron"},
        {"ere", "eras", "era", "eremos", "ereis", "eran"},
      },
      {
        {"o", "es", "e", "imos", "is", "en"},
        {"i", "iste", "io", "imos", "isteis", "ieron"},
        {"ire", "iras", "ira", "iremos", "ireis", "iran"}
      }
    };
  char tiempo;
  int f, t, i;
  while(cin>>palabra>>tiempo && tiempo!='T'){
    //en infinitivo los verbos solo terminan en ar/er/ir
    //inversa=palabra;
    //reverse(inversa[0], inversa[inversa.size()-1]);
    //vale unicamenre con mirar la ultima vocal no hace falta invertir y mirar el final
    (palabra[palabra.length()-2]=='a' ? f=0 : (palabra[palabra.length()-2]=='e' ? f=1 : f=2)); //f de final :-)
    (tiempo=='A' ? t=0 : (tiempo=='P' ? t=1 : t=2)); //t de tiempo
    for(i=0; i!=6; i++){
      cout<<sujetos[i]<<" "<<palabra.substr(0, palabra.size()-2)<<terminaciones[f][t][i]<<endl;
    }
  }
  return 0;
}
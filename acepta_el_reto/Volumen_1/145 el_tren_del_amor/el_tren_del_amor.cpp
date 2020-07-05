/**     H.$.*M el hombre llega a la mujer, los dos son altos asi que sin problemas
 *   
 *   
 *      H==@M no puede llegar el hombre porque se choca con la @
 *
 *
 *        M HM HM HHMM  hay ya 4 parejas pues todos happy salvo la primera mujer que F :-(
 */ 

#include <bits/stdc++.h>
using namespace std;
int main(){
  string tren;
  while(getline(cin, tren)){//mientras lea un tren
  //la primera idea que se me viene es tirar como con el balanceo de parentesis
  //los hombres serán los paréntesis de inicio y las mujeres los de cierre, tambien, como en cada vagon entra solo una persona
  //hHm seria 0 parejas H y m no se encuentran por la altura diferente y como H no se mueve h no concerá a m
  //hHMm se conocerán todos pues HM se conocen y todos happy, se bajan por tanto y dejan por ende camino libre para h  
    stack<char> pila;
    int lon=tren.size(), parejas=0;
    for(int i=0; i!=lon; i++){
      if(tren[i]=='@' || tren[i]=='h' || tren[i]=='H'){ //si nos encontramos con un obstaculo infranqueable o con un hombre 
        //while(!pila.empty())  pila.pop(); //vacias toda la pila, el que se encuentra con el obstaculo no se puede mover y por tanto los hombres anteriores no sirven para nada :-)
        pila.push(tren[i]); //introducimos la @
        continue;
      }
      if( tren[i]=='m' || tren[i] == 'M'){ //si nos encontramos con una mujer
        if(pila.empty())  continue; //so sorry pero si no hay nadie con quien pueda ligar la muchacha no se puede hacer nada; que se hubiera movido que es muy cómodo estar sentada esperando.
        if(tren[i]-5 == pila.top()){ //si habia antes un hombre esperando su momento de brillae (en la tabla ascii la distancia entre h-m es la misma que H-M pero es diferente que h-M)
          pila.pop(); //nuestro pequeño soldado se baja en la parada esperando encontrar el amor (yo confio en ti)
          parejas++; //sumamos 1 al numero de posibles parejas y continuamos en la aventura
          continue;
        }
        //si no, significa que la mujer no era de la altura optima
        pila.push(tren[i]); //la introducimos en la pila como quien introduce un obstaculo, se fastidia el resto jaja salu2
      }
    }
    //al terminar de recorrer todo el tren
    cout<<parejas<<endl;
  }
  return 0;
}
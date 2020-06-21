/*
                                                        /////PLANTEAMIENTO DE LOGICA PREVIO\\\\\

5 17 32
    valor a partir del que es favorable:
    abs(17-z)<abs(5-z) && abs(32-z)<abs(5-z) z>18.5     (32+5)/2=18.5
    caso minimo:
    x/3>18.5    x>55.5
    caso max
    (x+128)/3>18.5  x>-72.5
    resultado x>55.5->x=56

5 32 17
    5<17<32 esta en la mitad siempre va a ser favorable, nunca puede perder, puede no ganar pero perder jamás

31 17 5
valor a partir del que es favorable:
  (31+5)/2   z<18
  caso min:
  x/3<18  x<54
  caso max
  x+128<54  x<-74
  x<54 && x<-74
  valor negativo---->imposible


60 55 50
    valor a partir del cual es favorable:
    abs(50-z)<abs(60-z) && abs(55-z)<abs(60-z) z<55       (60+50)/2
    caso minimo
    x/3<55  x<165
    caso max
    (x+128)/3<55 x<165-128 x<37
    resultado
    x<165 && x<37------------>x<37->x=36

5 5 17
        valor a partir del cual es fvorable:
        (5+17)/2=11
        caso min
        x>33
        caso max
        x>-95
        x>33 && x>-95
        x>33
17 17 5
        valor a partir del cual es favorable:
        (5+17)/2=11
        caso min
        x<33
        caso max
        x<-95
        x<-95 imposible
*/

#include <iostream>
#include <cmath>
#include <algorithm>    // std::max
using namespace std;
int main(){
    int prim, seg, ter, men, may;
    double media, minimo, maximo, x;
    while(cin>>prim>>seg>>ter && !(prim==-1 && seg==-1 && ter==-1)){
        if((ter>prim && ter<seg) || (ter>seg && ter<prim) || (prim==seg && prim==ter)){ //si es imposible que pierda o se considera nulo
            cout<<"0"<<endl;
            continue;
        }
        /*(prim>seg ? ((prim>ter) ? (may=prim, cod=1) : (may=ter, cod=3)) : (seg>ter ? (may=seg, cod=2) : (may=ter, cod=3))); //asignas el mayor, y guardas su posicion en cod
        (prim<seg ? ((prim<ter) ? men=prim : men=ter) : (seg<ter ? men=seg : men=ter)); //asignas el menor*/
        may=max(max(prim, seg), ter);
        men=min(min(prim, seg), ter);

        media=(may+men)/2.0;
        minimo=3*media;
        maximo=minimo-(64*2); //el caso máx es aquel en el que los dos reciben 64 cartas (mandan a 8 y esos 8 a otros 8->8²=64)
        if(may==ter){ //si eres el mayor de los 3
            if(maximo>minimo){
                x=maximo;
            }
            else{
                x=minimo; //guardas el mayor de los valor y como x>maximo(max, min), redondeas para abajo y sumas 1 3.2->3 3+1=4 asi consiges el entero mayor más próximo
            }
            x=floor(x); x++;
            ((x>64 || x<0) ? (cout<<"I"<<endl) : cout<<x<<endl); //si no se produce ningun error imprimes el numero, en otro caso, imprimes I si  x da un numero imposible (mayor de 64 es imposible dado que solo puedes enviar a 8 y eso 8 a otros 8, en caso de responder todos recibirás 64 recetas como max), (menor que 0 es imposible, no te puede salir a devolver)
            continue;
        }
        //la unica posibilidad restantes es que sea el menor de los 3
        else{
            if(maximo<minimo){
                x=maximo;
            }
            else
                x=minimo; //guardas el menor de los valor y como x<min(max, min), redondeas para arriba y restas 1 1 3.2->4 4-1=3 asi consiges el entero menor más próximo
            x=ceil(x); x--;
            ((x>64 || x<0) ? (cout<<"I"<<endl) : (cout<<x<<endl)); //si no se produce ningun error imprimes el número, x da un numero imposible (mayor de 64 es imposible dado que solo puedes enviar a 8 y eso 8 a otros 8, en caso de responder todos recibirás 64 recetas como max), (menor que 0 es imposible, no te puede salir a devolver)
        }
    }
    return 0;
}
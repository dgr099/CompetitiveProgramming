#include <iostream>
#include <cmath>
//un escudo si estan en el interios, dos si estan en un lado y tres si estan en una esquina
//el cuadrado más grande, y se repite con los sobrantes
using namespace std;
int main(){
  long long legionarios, fil, escudos;
  while(cin>>legionarios && legionarios!=0){
    //x² tiene que ser lo más proximo al numero, x²=z x=(z)^(1/2)
    fil=escudos=0; //reiniciamos los valores del numero de escudos y filas
    while(legionarios!=0){
      fil=floor(sqrt(legionarios));
      legionarios-=fil*fil; //al ser un cuadrado, el area (numero de legionarios corresponde con base*altura y la base=altura) //cuando solo quede 1, -*-=+ eliminará al legionario restante
      //dentro hay un cuadrado de 2 fila menos cada uno con un escudo
      escudos+=(fil-2)*(fil-2); //1-2=-1; -1*-1=+1 contará el escudo verical cuando solo quede uno
      //los lados tienen 2 escudos, los legionarios que hay en los lados son 4 veces la fila -2 que son los de las esquinas, cuando solo quede 1 restara 8 que se compensán luego al considerar que tuviese esquinas 12-8=4 que son los de los lados+el contado mirando arriba tenemos los 5 escudos de un solo legionario
      escudos+=8*(fil-2);
      //las esquinas, que un cuadrado siempre tiene 4 y cada una con 3 
      escudos+=3*4;
    }
    cout<<escudos<<endl;
  }
  return 0;
}

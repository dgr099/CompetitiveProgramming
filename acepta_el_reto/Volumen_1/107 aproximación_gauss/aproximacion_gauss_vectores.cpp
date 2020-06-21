#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  bool *matr=NULL;
  //FILE *f;
  //f=fopen("prueba,txt", "w");
  long long i, j, n, m, pi;
  vector<long long> primos;
  long double error_permitido[6]={1.0, 1/10.0, 1/100.0, 1/1000.0, 1/10000.0, 1/100000.0}, error_gauss; //el error_gauss permitido mejor lo pongo como array porque en internet hay gente que hace eso y así te ahorras calculos después
  matr=(bool*)calloc(100000, sizeof(bool)); //va de 0 a 100000-1 el calloc sirve tambien para ponerlo todo a false, los true serán los que no son primos
  matr[0]=matr[1]=true; //corresponde al 1, y 0 que no se considera primo
  for(i=2; i!=100000; i++){
    if(!matr[i]){ //si esta a false significa que no es multiplo de ningun numero anterior y por tanto es primo//
      for(j=i*i; j<100000; j+=(i)) //eliminas todos los múltiplos del primo*//*j=i^2 (esto es porque los valores anteriores ya se han descartado al ser multiplos de numeros inferiores) se suma i que es lo mismo que multiplicar por 1 mas desde el i
        matr[j]=true;
      primos.push_back(i); //introduces el primo en la lista de primos
      //fprintf(f, "%lld ", i); //esto es para comprobar comporando con diff con una lista de primos de internet
    }
  }


  /*al terminar deberias tener una listas con todos los numeros primos del 1 al 100000*/
  while(cin>>n>>m && (n || m)){
    //for(pi=0; primos[pi]<=n ; pi++); //esto no se porque en el ultimo caso no funciona para el resto si pero para el ultimo no se porque no funciona -\(0_o)/-
    pi=distance(primos.begin(), upper_bound(primos.begin(), primos.end(), n)); //esto si que funciona para el ultimo
    error_gauss=abs(((long double)pi/n)-(long double)(1.0/log(n))); //calculas el error_gauss de gauss
    /*if (error_gauss < error_permitido[m]) cout << "Menor" << endl;
    else if (error_gauss == error_permitido[m]) cout << "Igual" << endl;
    else cout << "Mayor" << endl;*/      
    cout << (error_gauss == error_permitido[m] ? "IGUAL": (error_gauss>error_permitido[m] ? "MAYOR" : "MENOR"))<<endl; //imprimes el resultado empleando condicionales ternarios que la gente los usa mucho y también queda muy cute jajajaja
  }
  //free(matr);//liberas la matriz
  return 0;

}

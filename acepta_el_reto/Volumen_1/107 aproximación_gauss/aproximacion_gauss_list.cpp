#include "iostream"
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  bool *matr;
  long long i, j, n, m, pi;
  list<long long> primos;
  long double error_permitido[6]={1, 1/10.0, 1/100.0, 1/1000.0, 1/10000.0, 1/100000.0}, error_gauss;
  matr=(bool*)calloc(100000, sizeof(bool));
  matr[0]=true; /*corresponde al 1 que no se considera primo*/
  for(i=2; i!=100000; i++){
    if(!matr[i-1]){ /*si esta a false significa que no es multiplo de ningun numero anterior y por tanto es primo*/
      for(j=pow((i), 2); j<100000; j+=(i)) /*eliminas todos los múltiplos del primo*//*j=i^2 (esto es porque los valores anteriores ya se han descartado al ser multiplos de numeros inferiores) se suma i que es lo mismo que multiplicar por 1 mas desde el i²*/
        matr[j-1]=true;
      primos.push_back(i); /*introduces el primo en la lista de primos*/
    }
  }
  /*al terminar deberias tener una listas con todos los numeros primos del 1 al 100000*/
  while(cin>>n>>m && (n && m)){
    pi=distance(primos.begin(), upper_bound(primos.begin(), primos.end(), n));
    error_gauss=abs(((double)pi/n)-1.000/log(n));
    cout << (error_gauss == error_permitido[m] ? "IGUAL": (error_gauss<error_permitido[m] ? "MENOR" : "MAYOR"))<<endl;
  }
  free(matr);
  return 0;

}
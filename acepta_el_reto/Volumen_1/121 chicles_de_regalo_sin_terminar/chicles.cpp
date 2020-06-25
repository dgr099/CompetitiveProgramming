#include <iostream>
using namespace std;
int main(){
  long env, cant, chicles, aux, n_chicles, gastados; //aux_2; 
  long double aux_3; //para calcular los decimales
  while(cin>>env>>cant>>chicles && !(env==0)){
    aux_3=cant/(double)env;
    //aux=/*aux_2=*/chicles; //en aux guardamos los envoltorios de cada momento
    //cant>=env --->cant/env>=1
    if(aux_3>=1 && chicles >= env){ //si la cant/env es mayor que 1 (si cada vez damos más y más chicles acabas en la ruina)
      printf("RUINA\n");
      //cout<<"RUINA"<<endl;
      continue; 
    }
    if(cant==0){
      //cout<<chicles<<" "<<aux<<endl;
      printf("%ld %ld\n", chicles, chicles);
      continue;
    }
    aux=chicles;
    while(aux>=env){ //mientras que los envoltorios que tienes son mayor o igual que los que necesitas para la oferta
      n_chicles=aux*aux_3; //eston son los chicles que dan nuevos (env * cant/env)
      chicles+=n_chicles;
      gastados=n_chicles/aux_3;
      aux+=n_chicles-gastados;
      //en aux tienes que quitar los que consumes y sumarle los nuevos

    }
    printf("%ld %ld\n", chicles, aux);
    continue;
  }
  return 0;
}
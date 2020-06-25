#include <iostream>
using namespace std;
int main(){
  long env, cant, chicles, aux; //aux_2; 
  long double aux_3; //para calcular los decimales
  while(cin>>env>>cant>>chicles && !(env==0 && cant==0 && chicles==0)){
    aux_3=cant/(double)env;
    aux=/*aux_2=*/chicles; //en aux guardamos los envoltorios de cada momento
    //cant>=env --->cant/env>=1
    if(cant >= env && aux >= env){ //si la cant/env es mayor que 1 (si cada vez damos más y más chicles acabas en la ruina)
      cout<<"RUINA"<<endl;
      continue; 
    }
    if(cant==0){
      cout<<chicles<<" "<<aux<<endl;
    }
    while(aux>=env){ //mientras que los envoltorios que tienes son mayor o igual que los que necesitas para la oferta
      aux*=aux_3; //los envoltorios que tenias entre los envoltorios necesarios *los chicles que te dan por los envoltorios necesarios*/
      /*aux=(aux/env)*cant;
      if(aux>aux_2){ //se produce una ruina cuando se dan chicles indefinidos (se van aumentando cada vez más los aux)
        //tambien valdria comprobar si cant/env>=1 si de promedio te dan mas o los mimos que consumes será infinito los chicles que te llevas
        flag=0;
        cout<<"RUINA"<<endl;
        break;
      }*/
      chicles+=aux; //sumamos los chicles
    }
    cout<<chicles<<" "<<aux<<endl;
  }
  return 0;
}
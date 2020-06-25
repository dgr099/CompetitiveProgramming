#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;
int main(){
  long long lp_1, lb_1, lm_1, cp_1, cpt_1, pm_1; //lp->litros piscina, lb->litros barreños. lm->litros menos, cp->contador de pasos
  long long lp_2, lb_2, lm_2, cp_2, cpt_2, pm_2;
  long long aux;
  while(cin>>lp_1>>lb_1>>lm_1>>lp_2>>lb_2>>lm_2 && !(lp_1==0 || lp_2==0)){
    cp_1=cp_2=cpt_1=cpt_2=pm_1=pm_2=0;
    //esto funciona pero debe existir alguna formula matemática más fácil
    /*for(lp_act_1=0, lp_act_2=0; lp_act_1<lp_1 && lp_act_2<lp_2; cp++) { //lp_act litros actuales de la piscina ambos inician en 0 
      lp_act_1+=lb_1;
      lp_act_1-=lm_1;
      lp_act_2+=lb_2;
      lp_act_2-=lm_2;
    }*/
    if(lm_1>=lb_1 && lm_1>lb_1){ //si pierde más o lo mismo que mete tenemos un problema
       pm_1=1;
       cpt_1=LONG_LONG_MAX;
    }
    
    if(lm_2>=lb_2 && lp_2 > lb_2){
      pm_2=1;
      cpt_2=LONG_LONG_MAX;
    }

    while(pm_1==0){ //comprobacion de que no pierde más o lo mismo que mete
      cp_1=ceil((long double)lp_1/lb_1); //los pasos son lo que ocupa la piscina entre lo que llenas por cada pasada
      lp_1-=(cp_1*lb_1)-(lm_1 * (cp_1-1)); //actualizas el valor de los litros de la piscina con lo que sumas y lo que pierdes por los viajes salvo el ultimo
      cpt_1+=cp_1; //sumas a los pasos totales los pasos parciales
      if(lp_1<=0){ //cuando la piscina le queden litros negativos o 0 litros por llenar termina
        break;
      }
      lp_1-=-(lm_1); //si aun no has terminado de llenar haces otro viaje y por tanto cuentas las perdidas que tienes en el viaje
    }

    while(pm_2==0){
      cp_2=ceil((long double)lp_2/lb_2); //los pasos son lo que ocupa la piscina entre lo que llenas por cada pasada
      lp_2-=(cp_2*lb_2)-(lm_2 * (cp_2-1)); //actualizas el valor de los litros de la piscina 
      cpt_2+=cp_2; //sumas a los pasos totales los pasos parciales
      if(lp_2<=0){ //cuando le queden litros negativos para llenar entonces termina
        break;
      }
      lp_2-=-(lm_2); //si aun no has terminado de llenar haces otro viaje y cuentas las perdidas del nuevo viaje
    }
f:
    if(cpt_1<cpt_2){
      cout<<"YO"<<" "<<cpt_1<<endl;
      continue;
    }
    else if(cpt_1>cpt_2){
      cout<<"VECINO"<<" "<<cpt_2<<endl;
      continue;
    }
    else{
      if(cpt_1==LONG_LONG_MAX){
        printf("EMPATE 0\n");
        continue;
      }
      printf("EMPATE %lli\n", cpt_1);
    }

    /*if(lp_act_1>=lp_1 && lp_act_2>=lp_2){
      cout<<"EMPATE"<<" "<<cp_1<<endl;
      continue;
    }
    else if(lp_act_1>=lp_1){
      cout<<"YO"<<" "<<cp_1<<endl;
      continue;
    }
    else{
      cout<<"VECINO"<<" "<<cp_2<<endl;
      continue;
    }*/
  }
  return 0;
}
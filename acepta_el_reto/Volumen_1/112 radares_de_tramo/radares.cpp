twitter/insta: @dgr_099 ;-)
#include <iostream>
using namespace std;
int main(){
  long double  dist, max, tiempo, vel;
  while(cin>>dist>>max>>tiempo && !(tiempo==0 && dist==0 && max==0)){
    dist/=1000.0; //m->km
    tiempo/=60.0*60.0; //s->h
    vel=dist/tiempo; //1s*h/60s       1m*1km/1000m
    if(max<=0 || tiempo<=0 || dist<=0){
      cout<<"ERROR"<<endl;
      continue;
    }
    if(vel<=max){
      cout<<"OK"<<endl;
      continue;
    }
    if(vel>=max+(((20*max)/100.0))){ //si vel<=maximo+20%maximo
      cout<<"PUNTOS"<<endl;
      continue;
    }
    cout<<"MULTA"<<endl;
  }
  return 0;
}

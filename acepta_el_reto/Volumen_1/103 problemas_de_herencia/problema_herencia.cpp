twitter/insta: @dgr_099 ;-)
#include <iostream>
#include <cmath>
using namespace std;
#define MIN 
int main(){
  int i, n, pol[20], exp, base;
  float h, x=0, f, area=0;
  while(cin>>i && i!=20){
    for(n=0; n!=i+1; n++){
      cin >> pol[n];
    }
    cin>>n; /*ahora n toma el valor de los cuadrados*/
    for(n, h=1.0/n, f=x=area=0; n!=0; n--){
      f=0;
      for(exp=i, base=0; exp!=-1; exp--, base++){
        f+=pol[base]*pow(x, exp);
      }
      if(f>1){/*f tiene que estar acotado entre 1 y o)*/
        f=1;
      }
      else if(f<0){
        f=0;
      }
      x+=h;
      area+=f; /*sumatorio de las alturas de los rectangulos*/
    }
    area*=h; /*la suma de las alturas por la base te da el area*/
    if(abs(area-(0.5))<=0.001){
      cout<<"JUSTO"<<endl;
    }
    else if(area<0.5){/*si el area es menor que la mitad y no es justo signifia que su opuesto es mayor*/
      cout<<"ABEL"<<endl;
    }
    else{ /*el ultimo caso es aquel en el el resultado es superior*/
      cout<<"CAIN"<<endl;
    }
  }
  return 0;
}

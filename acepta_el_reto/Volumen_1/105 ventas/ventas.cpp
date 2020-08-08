twitter/insta: @dgr_099 ;-)
#include <iostream>
using namespace std;
int main(){
  double week[6], media;
  string semana[6]={"MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO"};
  int i=0, max, min;
  do{
    inicio:
    for(i=media=max=min=0; i!=6 && cin>>week[i] && week[i]!=-1; i++){
      if(week[max]<week[i]){
        max=i;
      }
      if(week[min]>week[i]){
        min=i;
      }
      media+=week[i];
    }
    if(week[0]!=-1){
      if(semana[max]==semana[min] && week[0]!=-1){
        cout<<"EMPATE"<<endl;
        goto inicio;
      }
      media/=6;
      cout<<semana[max]<<" "<<semana[min]<<" "<< (week[5]>media ? "SI" : "NO")<<endl;      
    }
  }while(week[0]!=-1);
  return 0;
}

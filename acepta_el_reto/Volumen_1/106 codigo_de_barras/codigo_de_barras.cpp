#include <iostream>
#include <string.h>
using namespace std;
#define NUM_C 9;
int main(){
  int control, num, index, lon, i;
  string aux, cod, cod_pais[]={"0", "380", "50", "539", "560", "70", "759", "850", "890"}, pias_cod[]={"EEUU", "Bulgaria", "Inglaterra", "Irlanda", "Portugal", "Noruega", "Venezuela", "Cuba", "India"};
  while(cin>>aux && aux.compare("0")!=0){
    cod.clear();
    lon=aux.length();

    while(lon!=8 && lon!=13){
      cod+='0';
      lon++;
    }
    cod+=aux;
    control=cod[lon-1]-'0';
    for(index=lon-2, i=1, num=0; index!=-1; index--, i++){
      if(i%2==0){
        num+=(cod[index]-'0');
        continue;
      }
      num+=(cod[index]-'0')*3;
    }
    if((num+control)%10==0){
      cout<<"SI";
        if(lon==13){
        for(i=0, control=-1; i!=9; i++){
          if(strncmp(&cod_pais[i][0], &cod[0], cod_pais[i].length())==0){
            control=i;
            break;
          }
        }
          /*if(strcmp(&cod_pais[i][0], &cod[0])==0){
            control=i;
            break;
          }
        }*/
        if(control==-1){
          cout<<" Desconocido"<<endl;
          continue;
        }
        cout<<" "<<pias_cod[i]<<endl;
        continue;
      }
    }
    else{
      cout<<"NO";
    }
    cout<<endl;
  }
  return 0;
}
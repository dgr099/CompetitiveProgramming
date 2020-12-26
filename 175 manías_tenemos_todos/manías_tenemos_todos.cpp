#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  cout.tie(NULL);
  int casos;
  cin>>casos;
  while(casos--){
    int semanas;
    pair<int, int> mas; //el dia que mas pastillas se han tomado
    cin>>semanas;
    //compra el dia que menos pastillas tenga o lo que viene a ser lo mismo
    //el dia que mas veces haya cumplido con la compra
    char dias[7]={'L', 'M', 'X', 'J', 'V', 'S', 'D'};
    int *pastis=NULL; //aqui guardamos el numero de pastillas consumidas cada dia
    pastis=(int*)calloc(7, sizeof(int)); //esto me sirve para inicializarlas ya a 0
    for(int i=0; i!=semanas; i++){
      string semana;
      cin>>semana;
      for(int i=0; i!=7; i++){
        if(semana[i]=='-')  pastis[i]++; //vamos contando las pastillas tomadas en cada dia de la semana
      }
    }
    mas.first=pastis[0]; mas.second=0; //en el first guardo el numero de pastillas y en el second que dia de la semana 
    for(int i=0; i!=7;i++){
      if(pastis[i]>mas.first){ //buscamos el dia en el que más pastillas hemos consumido
        mas.first=pastis[i];
        mas.second=i;
      }
    } 
    free(pastis);
    //en mas tienes guardado, en el second el dia (empezando desde 0) en el que más pastillas has tomado y por ende menos tienes
    //en el first tienes guardado el numero de pastillas, el total de pastillas que debiste tomar - las gastadas + 1 te dan el dia de la semana
    printf("%c %d\n", dias[mas.second], semanas-mas.first+1);
  }
  return 0;
}
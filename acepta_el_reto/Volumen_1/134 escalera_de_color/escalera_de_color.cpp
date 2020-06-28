// 4 cartas , para conseguir escalera real necesitas  casar 5 del mismo palo por tanto todas las cartas de la mesa deben coindicir en palo
//si en algun momento se lee un palo distinto no se puede hacer escalera 
#include <iostream>
#include <string.h> //esto es por el 10 que me jode la vida
#include <vector>
#include <algorithm>
using namespace std;
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

int to_int(string aux){
  char f[]={'J', 'Q', 'K', 'A'}; //f de figuras
  if(aux[0] <='9'){
    if(aux[1] == '0'){
      return 9;
    }
    return aux[0]-'0' - 1;
  }
  for(int i=0, j=10; i!=4; i++, j++){
    if(aux[0]==f[i]){
      return j%13;
    }
  }
}

int main(){
  string num;
  int flag=0;
  char palo, palo_aux;
  string f[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
  int pos, pos_2, seg;
  vector<int>mesa;
  while(getline(cin, num, ' ') && !(num[0]=='0')){
    //mesa=(int*)calloc(14, sizeof(int));
    mesa.clear();
    flag=0;
    scanf("%c", &palo);
    cin.ignore();
    for(int i=0; i!=13; i++){
      mesa.push_back(0);
    }
    pos=to_int(num);
    mesa[pos]=1;
    //mesa[pos%13]==1;
    for(int i=1; i!=4; i++){
      getline(cin, num, ' ');
      if(scanf("%c", &palo_aux) && palo_aux!=palo){
        flag=1; //sigues leyendo valores porque la entrada debe proseguir pero la salida será NADA
      }
      cin.ignore();
      pos=(to_int(num));
      mesa[pos]=1; //vas introduciendo los numeros de la entrada
      //mesa[pos%13]==1;
    }
    if(flag==1){
      printf("NADA\n");
      continue;
    }
    for(pos=0; pos!=14 && mesa[pos]!=1; pos++); //el primer 1
    for(pos_2=pos+1; pos_2!=14 && mesa[pos_2]!=0; pos_2++); //el ultimo 1 que tiene segido (sin rotar)
    pos_2--;

    //caso en que la escalera se completa por abajo  
    if(pos_2<=3 && mesa[pos_2+2]!=1){
      pos_2=mod(pos_2-1, 13);
      for(seg=1; mesa[pos_2]!=0;seg++, pos_2=mod(pos_2-1, 13)); //buscas los 1 seguidos desde el más alto de los continuados (sin rotar)
      if(seg==4){ //si encuentra cuatro 1 seguidos al rotar
        cout<<f[pos_2]<<" "<<palo<<endl;
        continue;
      }
      for(int pos_aux=mod(pos_2-1, 13); mesa[pos_aux]!=0; pos_aux=mod(pos_aux-1, 13), seg++);
      if(seg==4){
        cout<<f[mod(pos_2, 13)]<<" "<<palo<<endl; //si añadiendoo el que faltaba logras escalera
        continue;
      }
      printf("NADA\n");
      continue; //cualquier otra situacion es que es imposible completar la escalera
    }  
    //aqui es en caso de que la escalera se complete por arriba
    if((seg=(pos_2-pos+1))==4){ //si ya forman 4 unos el primero y el ultimo y no esta en posicion de poder rotar
        cout<<f[mod(pos_2+1, 13)]<<" "<<palo<<endl; //si añadiendoo el que faltaba logras escalera
        continue;
    }
    for(int i=pos_2+2; mesa[i]!=0; i=mod(i+1, 13), seg++);
    if(seg==4){
      cout<<f[mod(pos_2+1, 13)]<<" "<<palo<<endl; //si añadiendoo el que faltaba logras escalera
      continue;
    }
    printf("NADA\n");
    continue; //cualquier otra situacion es que es imposible completar la escalera
  }

  return 0;
}

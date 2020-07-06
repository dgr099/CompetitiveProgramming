#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int lon;
  while(cin>>lon && lon>0){
    char c; cin>>c;
    int aux=lon-1, aux_2=lon, i;
    while(lon--){
      //primero un bucle para dibujar los espacios en blanco
      for(i=0; i!=lon; i++){
        printf(" ");
      }
      for(i=0; i!=aux_2; i++){
        printf("%c", c);
      }
      aux_2+=2; //sumas uno a cada extremo
      printf("\n");
    }
    aux_2-=2;
    int z=1;
    while(aux--){
      aux_2-=2;
      for(i=0; i!=z; i++){
        printf(" ");
      }
      z++;
      for(i=0; i!=aux_2; i++){
        printf("%c", c);
      }
      printf("\n");
    }
  }
  return 0;
}
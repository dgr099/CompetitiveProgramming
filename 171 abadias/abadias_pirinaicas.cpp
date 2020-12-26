#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int montains;
  while(cin>>montains && montains!=0){
    vector<int> mont; //el vector para guardar los tamaños en posiciones
    //set<pair<int, int>> mon; //en uno guardo su tamaño y en el otro su posicion, como van ordenados no problem
    int aux_2;
    pair<int, int> big; big.first=0;
    for(aux_2=0; aux_2!=montains; aux_2++){
      int aux;
      cin>>aux;
      if(aux>big.first){
        big.first=aux;  big.second=aux_2;
      }
      mont.push_back(aux);
    }
    //como minimo debe poderse una abadia (el ultimo pico no tiene ninguno a la izquierda para molestar)
    //todos los que tengan una posicion menor al más alto no valen
    int abadias=0;  big.first=0;
    aux_2--;
    do{
      if(big.first<mont[aux_2]){
        abadias++;
        big.first=mont[aux_2];
      }
      aux_2--;
    }while(aux_2>=big.second);
    printf("%d\n", abadias);
  }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int casos, casos_2, aux, aux_2;
  cin>>casos;
  while(casos--){
    int up, down;
    up=down=0;
    cin>>casos_2;
    cin>>aux_2; casos_2--;
    while(casos_2--){
      cin>>aux;
      if(aux==aux_2){
        aux_2=aux;
        continue;
      }
      if(aux>aux_2){
        up++;
        aux_2=aux;
        continue;
      }
      down++;
      aux_2=aux;
    }
    printf("%d %d\n", up, down);
  }
}
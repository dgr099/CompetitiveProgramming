#include <bits/stdc++.h>
using namespace std;
int main(){
  //son numeros muy grandes por lo tanto no entran en un int
  int num;
  while(cin>>num){
    int v; cin>>v;
    num--;
    while(num--){
      int aux;
      cin>>aux;
      if(aux>v) v=aux;
    }
    printf("%d\n", v);
  }
  return 0;
}
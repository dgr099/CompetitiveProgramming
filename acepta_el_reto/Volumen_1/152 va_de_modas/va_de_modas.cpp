#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int cas;
  while(cin>>cas && cas){
    map<int,int> min;
    set<int> ord;
    while(cas--){
      char aux;
      cin>>aux;
      min[aux]++;
    }
    for(auto p : min){ //en este set tengo ordenados los apariciones
      ord.insert(-p.second);
    }
    //basta con colocar el que corresponde al mayor numero de apariciones
    auto it = ord.begin();
    for(auto m : min){
      if(m.second== -*it){
        printf("%d\n", m.first);
        break;
      }
    }
  }
  return 0;
}
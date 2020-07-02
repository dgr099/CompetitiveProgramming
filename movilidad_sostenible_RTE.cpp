#include <bits/stdc++.h>
using namespace std;

/*bool compare (pair<int, int> &left, pair<int,int> &right){
  if(left.first<=right.first)
    return true;
  return false;
}*/

void recurs(set<int> *ll, vector<int> *v){
  if(!v){
    return;
  }
  for(auto p : *v){ //recorres todas las posibles uniones de ese edge con otros
    if((*ll).find(p)==(*ll).end()++){
      (*ll).insert(p); //insertas el que recorres
      recurs(ll, &v[p]); //recorres recursivamente desde ese edge los nuevos edges disponibles 
    }
  }
  return;
}

int main(){
  int p_i, c_b, aux, aux_1, i, j; //p_i puntos de interes, c_b carril bici
  vector<int> v[100];
  set<int> ll;
  //vector<pair<int, int>> v_no;
  ios_base::sync_with_stdio(false);
  while(cin>>p_i>>c_b){
    ll.clear();
    for(i=0; i!=100; i++){ //limpiamos los vectores
      v[i].clear();
    }
    for(i=0; i!=c_b; i++){
      cin>>aux>>aux_1;
      //(aux_1<aux ? v[aux_1-1].push_back(aux-1) : v[aux-1].push_back(aux_1-1)); //vas insertando los edges
      v[aux-1].push_back(aux_1-1);
      v[aux_1-1].push_back(aux-1);
    }
    ll.insert(0);
    recurs(&ll, &v[0]);
    //sort(v_no.begin(), v_no.end(), compare);
    if(ll.size()==p_i){
      printf("BICI\n");
      continue;
    }
    printf("A PIE\n");
  }
  return 0;
}

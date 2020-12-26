#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
  int casos, corredores, hermanos;
  cin>>casos;
  while(casos--){
    string linea;
    corredores=hermanos=0;
    map<string, int> participantes;
    while(cin>>linea && linea!="===="){
      corredores++;
      linea.pop_back();
      int i=linea.size()-1;
      for(i; i>=0; i--){
        linea[i]=tolower(linea[i]); //pasamos a minusculas
      }
      participantes[linea]++;
      cin>>linea; //su nombre me importa entre 0 y nada
    }
    for(auto p : participantes){
      if(p.second>1){
        hermanos+=p.second;
      }
    }
    cout<<corredores<<" "<<hermanos<<endl;
  }
  return 0;
}
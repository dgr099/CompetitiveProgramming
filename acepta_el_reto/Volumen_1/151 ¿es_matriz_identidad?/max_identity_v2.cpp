#include <iostream>
using namespace std;
int main(){
  int x, i, j, v;
  bool identidad;
  while(cin>>x && x!=0){
    for(identidad=true, i=0; i!=x; i++){
      for(j=0; j!=x; j++){
        cin >> v;
        if(i==j && v!=1){
          identidad=false;
        }
        else if(i!=j && v!=0)
        {
          identidad=false;
        }             
      }
    }
    cout<<((identidad==true) ? "SI" : "NO" ) << endl;
  }
  return 0;
}
#include <iostream>
using namespace std;
//programacion dinamica calculando los factoriales y comprobando el resto
int main(){
  long long p, m;
  while(cin>>p && !(p<0)){
    cin>>m;
    if(p<=m || p==1){ //si m es más grande que p significa que el factorial en algun momento multiplica por p, es decir es multiplo de p y por tanto p es divisor
      cout<<"YES"<<endl;
      continue;
    }
    else{
      cout<<"NO"<<endl;
      continue;
    }

  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  cout.tie(NULL);
  short meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  int casos;  cin>>casos;
  while(casos--){
    int dias=0, mes;
    cin>>dias>>mes;
    dias=meses[mes-1]-dias;
    for(int i=mes; i!=12; i++){
      dias+=meses[i];
    }
    printf("%d\n", dias);
  }
}
    
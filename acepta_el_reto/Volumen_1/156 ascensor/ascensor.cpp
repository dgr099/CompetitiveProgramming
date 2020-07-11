#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long num, piso_pas, piso_act;
  while(cin>>piso_pas && piso_pas>-1){
    num=0;
    while(cin>>piso_act && piso_act!=-1){
      num+=abs(piso_act-piso_pas);
      piso_pas=piso_act;
    }
    printf("%d\n", num);
  }
  return 0;
}
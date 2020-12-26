#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int p;
  while(cin>>p && p!=0){
    char f, d='0', i='0';
    while(p--){
      cin>>f;
      if(f=='D'){
        d='1';
      } else if(f=='I') i='1';
    }
    printf(d=='1' && i=='1' ? "ALGUNO NO COME\n" : "TODOS COMEN\n");
  }
  return 0;
}
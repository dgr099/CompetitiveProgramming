
#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,y;
  while(cin>>x>>y && !(x<0 || y<0)){
    x*=2; x+=(2*y);
    printf("%d\n", x);
  }
  return 0;
}

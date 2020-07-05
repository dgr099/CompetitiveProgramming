#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string num;
  while(getline(cin, num)){
    if(num[0]=='-') return 0;
    int cifras = strlen(&num[0]) - 1, sum=0, i=0;
    while(cifras--){
      sum+=num[i]- '0' ;
      printf("%c + ", num[i]);
      i++;
    }
    sum+=num[i]- '0';
    printf("%c = %d\n", num[i], sum);
  }
  return 0;
}

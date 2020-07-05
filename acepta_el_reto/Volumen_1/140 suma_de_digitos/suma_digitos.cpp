#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int num, aux;
  while(cin>>num && num!=-1){
    int sum=0, cifras=log10(num);
    while(cifras!=0){
      aux = num/(pow(10, cifras));
      aux%=10;
      printf("%d + ", aux);
      sum+=aux;
      cifras--;
    }
    aux=num%10;
    printf("%d ", aux);
    sum+=aux;
    printf("= %d\n", sum);

  }
  return 0;
}
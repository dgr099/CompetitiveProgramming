#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  cout.tie(NULL);
  string entrada;
inicio:
  while(cin>>entrada && entrada[0]!='-'){
    entrada+='-';
    char *pointer=&entrada[0];
    while((*pointer)!='-'){
      if(*pointer%2!=0){
        printf("NO\n");
        goto inicio;
      }
      pointer++;
    }
    printf("SI\n");
  }
  return 0;
}
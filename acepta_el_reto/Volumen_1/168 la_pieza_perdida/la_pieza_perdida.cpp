#include <bits/stdc++.h>
using namespace std;
int main(){
  int tam;
  while(cin>>tam && tam!=0){
    bool *array;  array=(bool*)calloc(tam, sizeof(bool));
    int aux;
    tam--;
    while(tam--){
      cin>>aux;
      array[--aux]=true;
    }
    for(aux=0;true;aux++){
      if(!array[aux]){
        printf("%d\n", ++aux);
        break;
      }
    }
    free(array);
  }
  return 0;
}
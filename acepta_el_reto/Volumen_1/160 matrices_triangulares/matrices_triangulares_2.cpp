#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  cout.tie(NULL);
  int num;
  while(scanf("%d\n", &num) && num!=0){
    int i, j, superior, inferior, top, aux; //superior e inferior sirven como banderas para saber si es matriz superior o no
    //for(i=0; i!=num; i++) for(j=0; j!=num; j++){cin>>mat[i][j];} yo creo que esto entra on time pero tampoco es necesario, se pueden ir leyendo los datos mientras tratamos con ellos
    for(i=top=0, superior=1, inferior=1; i!=num /*&& (superior || inferior)*/; i++, top++) for(j=0; j!=num; j++){ //toca recorrer la matriz para comprobar
      scanf("%d\n", &aux); //leemos el numero
      if(j==top)  continue; //si esta en el punto en el que i dont give a f**k pues paso
      if(j>top){
        if(aux!=0)  superior=0;
      } else  if(aux!=0)  inferior=0;
    }
    (superior==1 || inferior==1 ? printf("SI\n") : printf("NO\n"));
  }
}
/*Este programa permite crear casos de prueba, si os da WA tal vez os sea de ayuda
* crear mapas, ejecutarlo con mi codigo redireccionando la salida, despues ejecutar el vuestro
* y emplear el comando diff para ver diferencias, espero que os sirva jaja
*/
#include <bits/stdc++.h>
#define MAX_R 999
#define MAX_C 999
#define MAX_MAP 10
using namespace std;
int main(){
  srand(time(NULL));
  for(int b=0; b!=rand()%MAX_MAP; b++){
    int f=rand()%MAX_R, c=rand()%MAX_C;
    printf("%d %d\n", c, f);
    for(int i=0; i!=f; i++){
      for(int j=0; j!=c; j++){
        if((rand()%2)){
          printf("*");
        }else printf("-");
      }
      printf("\n");
    }
  }
}
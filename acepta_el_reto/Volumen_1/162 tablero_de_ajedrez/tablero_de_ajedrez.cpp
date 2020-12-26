#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  cout.tie(NULL);
  int tam;
  char car;
  while(cin>>tam>>car && tam!=0){
    int i, j, aux; //aux indica si debe colocarse en pares o impares

    printf("|");
    for(i=0; i!=tam*8; i++){
      printf("-");
    }
    printf("|\n");
    //64 cuadrados, luego es 8*8
    for(i=aux=1; i<=8; i++){ //filas
      for(int z=0; z!=tam; z++){ //cada fila tiene el tamaño especificado por lo que hay que repetir lo que se muestra varias veces
        printf("|");
        for(j=0; j!=8; j++){ //columnas
          if(j%2==aux){ //dependiendo de si es par o impar se coloca espacio o casilla
            for(int lol=0; lol!=tam; lol++) //se van mostrando las casillas en funcion de si toca una cosa u otra
              printf("%c", car);
          } else{
              for(int lol=0; lol!=tam; lol++)
                printf(" ");
            }   
        }
        printf("|\n");
      }
      (aux==0 ? aux=1 : aux=0); //la siguiente fila tendra que poner en el siguientee
    }

    printf("|");
    for(i=0; i!=tam*8; i++){
      printf("-");
    }
    printf("|\n");
  }
  return 0;
}
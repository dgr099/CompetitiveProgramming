#include <bits/stdc++.h>
using namespace std;
int main(){
  pair<int, int> dimensiones; //alto y ancho
  while(cin>>dimensiones.second>>dimensiones.first && (dimensiones.first!=0 && dimensiones.second!=0)){
    int i=0, j=0, casillas=0;
    char tablero[dimensiones.first][dimensiones.second];
    for(i=0; i!=dimensiones.first; i++){
      for(j=0; j!=dimensiones.second; j++){
        cin>>tablero[i][j];
      }
    }
    //al llegar aqui ya tenemos todo el tablero leido y guardado
    for(i=0; i!=dimensiones.first; i++){ //fila
      for(j=0; j!=dimensiones.second; j++){ //columna
        if(tablero[i][j]=='-'){ //si detecta una vacia procede a mirar sus alrededores
        /**
         * _______
         * |_|_|_|
         * |_|_|_|
         * |_|_|_|
         */ 
          int aux=0;
          //este bucle barre la parte de arriba y abajo
          for(int aux_1=j-1; (aux_1<=j+1 && aux_1<dimensiones.second); aux_1++){
            if(aux_1>=0 && aux_1<dimensiones.second){ //si la anchura esta dentro de los limites, haces las comprobaciones
              if(i-1>=0) //si no te sales por la parte de arriba
                if(tablero[i-1][aux_1]=='*') aux++;
              if(i+1<dimensiones.first) //si no te sales por la parte de abajo
                if(tablero[i+1][aux_1]=='*') aux++;
            }
          }
          //comprobamos los laterales
          //si no te sales por los bordes
          if(j-1>=0){ //izquierda
            if(tablero[i][j-1]=='*')  aux++;
          }
          if(j+1<dimensiones.second){ //derecha
            if(tablero[i][j+1]=='*')  aux++;
          }
          if(aux>=6)  casillas++; //si esta rodeada por más de 6 minas
          //printf("%d\n", aux);
        }
      }
    }
    printf("%d\n", casillas);
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
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
          /*creo que la v1 es más eficiente pero esta version se entiende mejor*/
          //gracias a ISAAC LOZANO por ayudarme con su perspectiva para esta versión @isaac_lozano_97
          //recuerda un poco a como se solucionaba el problema 129 (marcador de 7 segmentos)
          //la cosa es la siguiente, hay 8 proximidades a la mina, utilizando su posicion relativa
          //podemos obtener la posición absoluta en funcion del hueco vacio
          //si esa coordenada es legal y encima valida sumamos 1 al numero de bombas proximas
          //                                       up           down          left              rigt            left upper corner   right upper corner    lower left corner   lower right corner
          pair<int, int> c_alrededor[8]={make_pair(1, 0), make_pair(-1, 0), make_pair(0, -1), make_pair(0, 1), make_pair(1, -1), make_pair(1, 1),       make_pair(-1, -1),    make_pair(-1, 1)};
          pair<int, int> coordenada;
          for(int b=0; b!=8; b++){
            coordenada.first=i+c_alrededor[b].first;  coordenada.second=j+c_alrededor[b].second;
                //si la coordenada vertical es valida                             //la coordenada horizontal es valida                              //y hay una bomba en esa posicion
            if((coordenada.first>=0 && coordenada.first<dimensiones.first) && (coordenada.second>=0 && coordenada.second<dimensiones.second) && tablero[coordenada.first][coordenada.second]=='*')  aux++;
          }
          if(aux>=6) casillas++;
        }
      }
    }
    printf("%d\n", casillas);
  }
  return 0;
}
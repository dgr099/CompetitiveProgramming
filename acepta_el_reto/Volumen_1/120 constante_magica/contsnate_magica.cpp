#include <iostream>
#include <vector>
using namespace std;
int main(){
  vector<int> arr;
  long long centro, filas, x, y, **matriz, aux, conts;
  bool **max;
  while(cin>>filas>>centro && !(centro==0 && filas==0)){
    /*buscamos la posición de inicio*/
    x=(filas/2); y=filas-1;
    /*reseteamos las dos matrices*/
    if(!(matriz=(long long**)calloc(filas, sizeof(long long*)))) return 1; //en esta se guardan los numeros
    if(!(max=(bool**)calloc(filas, sizeof(bool*))))  return 1; //en este se comprueba si ya se habia escrito un numero en la posicion
    for(aux=0; aux!=filas; aux++){
      if((matriz[aux]=(long long*)calloc(filas, sizeof(long long)))==NULL){
        return 1;
      }
      if(!(max[aux]=(bool*)calloc(filas, sizeof(bool)))){
        return 1;
      }
    }
    matriz[x][y]=centro; //se asigna el primer valor
    max[x][y]=true;
    while(!(x==(filas-1) && y==(filas-1))){ //cuando llegue a la esquina para porque ya habra terminado una fila entera, no es necesario continuar ya que ya se puede calcular la contante
      x++;  y++; //actualizas la posición de la matriz;
      if(x>filas-1){ //si se sale por el lateral
        x=0;
      }
      else if(y>filas-1){  //si sale por arriba
        y=0;
      }
      if(max[x][y]!=false){
        y--; x--; //vuelve a donde estaba
        y--; //baja una
      }
      //se asignan los valores
      max[x][y]=true;
      matriz[x][y]=++centro;
    }
    for(x=y=conts=0; !(x==filas && y==filas); x++, y++){
      //se cuenta la constante mágica
      conts+=matriz[x][y];
    }
    //se imprime su valor
    cout<<conts<<endl;
    //se vuelven a formatear las cadenas
    for(aux=0; aux!=filas; aux++){
      free(matriz[aux]);
      free(max[aux]);
    }
    free(matriz);
    free(max);    
    continue;
  }
  return 0;
}
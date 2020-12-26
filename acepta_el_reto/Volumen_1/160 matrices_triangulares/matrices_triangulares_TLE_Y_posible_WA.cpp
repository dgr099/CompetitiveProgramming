#include <bits/stdc++.h>
using namespace std;
/*la principal diferencia entre ambas funciones es que en una act sirve para saber desde donde comprobar (superior) y en la otra, actual sirve para saber hasta donde comprobar*/
void eliminar_sobras(int num){
  string pa_tirar;
  while(num--){
    getline(cin, pa_tirar);
  }
  return;
}
int matriz_superior(int &filas, int &act){
  string entrada; getline(cin, entrada);
  if(act==filas){ //si has comprobado todas las filas hasta el final sin problemas es que efectivamente es triangular
    return 0;
  }
  for(int i=act*2, j=filas*2; i!=j; i+=2){
    if(entrada[i]!='0'){
      eliminar_sobras(filas-act);
      return 1;
    }
  }
  return matriz_superior(filas, ++act);
}

int matriz_inferior(int &filas, int &act){
  if(act==filas){
    return 0;
  }
  string entrada; getline(cin, entrada);
  for(int i=0, j=act*2; i!=j; i+=2){
    if(entrada[i]!='0'){
      eliminar_sobras(--filas-act);
      return 1;
    }
  }
  return matriz_inferior(filas, ++act);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int num;
  f:
  while(cin>>num && num!=0){
    string fila;
    char *tok;
    cin.ignore();
    getline(cin, fila); //leemos la primera fila para probar;
    int aux;
    /*dos posibles matrices triangulares, aquellas supperiores o inferiores, comprobamos si es posible superior*/
    if(fila[2]=='0'){
      /*posible matriz triangular superior*/
      for(int i=4, j=num+num; i<j; i+=2){
        if(fila[i]!='0'){
          printf("NO\n");
          eliminar_sobras(--num);
          goto f;
        }
      }
      aux=2;
      /*problemita, puede que la primera fila correspona con matriz superior puede que realmente sea matriz inferior y aqui la cagas :_( */
      (matriz_superior(num, aux)==0 ? printf("SI\n") : printf("NO\n"));
    } else{
        /*si no es superior aun puede ser inferior*/
        aux=1;
        (matriz_inferior(num, aux)==0 ? printf("SI\n") : printf("NO\n"));
      }
  }
  return 0;
}
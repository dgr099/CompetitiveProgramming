#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
  char act;
  while(cin>>act && act!='F'){
    char pas='A';
    bool print = false;
    pair<int, int> match;
    int i_set=0; //esta variable es para saber si hay que dejar un espacio o no (si es el primer set que se imprime o no)
    match.first=match.second=0;
    if(act==pas)  match.first++;
    else  pas='B';
    while(cin>>act && act!='F'){
      if(act==pas){ //si ya tenia ganado el saque
        if(act=='A') //se comprueba si el punto va para uno u otro jugador
          match.first++;
        else 
          match.second++;
      }
      else  pas=act; //si cambia el saque
      print=true;
      if((match.first>8 || match.second>8) && abs(match.first-match.second)>1){ //si alguno de los dos gana el set (mas de 8 puntos con 2 de diferencia)
        if(i_set==0){
          printf("%d-%d", match.first, match.second);
          i_set=1;
        }
        else{ //si no es el primer set que se ha impreso en este partido
          printf(" %d-%d", match.first, match.second);
        }
        print=false;
        match.first=match.second=0; //reinicio los puntos para el nuevo set
      }
    }
    if(i_set==0){ //al finalizar si no se ha impreso ningun set entonces, quiere decir que no han terminado el partido y no se ha impreso nada
      printf("%d-%d\n", match.first, match.second);
      continue;
    }
    //if(match.first!=0 || match.second!=0) esto no vale pues para que alguno sume un punto deben ganar 2 es decir, puede que al final cambie el saque pero no sume puntos y por tanto debe imprimir el 0-0 final y no solo un salto de linea
    if(print){ //si han tenido que dejar algun set a medias imprimes el resultado parcial
      printf(" %d-%d\n", match.first, match.second);
      continue;
    }
    printf("\n");
  }
  return 0;
}
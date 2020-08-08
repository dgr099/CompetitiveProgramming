twitter/insta: @dgr_099 ;-)
#include <iostream>
#include <string.h>
using namespace std;
#define MAX_CASOS 1024
#define MAX_STR 4000 //aprox 1024*4
int main(){
  int c, cuadrado[MAX_CASOS][MAX_CASOS], i, j, med;
  long long CM, aux_l, aux_d, CM2, sum_esquinas, sum_centro, sum_lados;
  char *tok;
  bool diabolico=true, esoterico=true;
  /*char fila[MAX_STR];*/
  string matrix;
  while(cin >> c && c!=0){
    cin.ignore();
    esoterico=true;
    getline(cin, matrix);
    tok=strtok(&matrix[0], " ");
    for(diabolico=true, i=aux_l=aux_d=CM=CM2=0; i!=c; i++){ //primero guardo el cuadrado en una matriz
      for(j=aux_l=0; j!=c && diabolico==true; j++, tok=strtok(NULL, " ")){ /*si diabolico esta a false no tiene sentido continuar*/
        if((cuadrado[i][j]=atoll(tok))>c*c)
          esoterico=false;
        aux_l+=cuadrado[i][j]; /*va guardando la CMa parcial del lado*/
        if(i!=0 && (aux_l > CM || aux_d > CM)){ /*si las CMas parciales ya son superiores a la CMa que debería dar pasa a la siguiente fila omitiendo las columnas restantes*/
          diabolico=false; /*pone diabolico a false ya que alguna de las CMas parciales fue superior a la CMa del primer lado*/
          break;
        }
        if(i==j){
          aux_d+=cuadrado[i][j]; /*tambien guarda la suma parcial de la diagonal*/
        }
      }
      if(diabolico==false){
        break;
      }
      if(CM<aux_l)
        CM+=aux_l; /*la unica posibilidad de que aux_l sea superior es que se encuentre en la 1º fila, que sera el valor que tomará CMa*/
      if(aux_l!=CM){
        diabolico=false; /*si no son iguales significa que no es diabólico*/
      }
       
    }
    if(diabolico==true && aux_d==CM){ /*si se cumplen ambas quiere decir que es diabólico, falta comprobar si es esoterico*/
      sum_lados=0;
      sum_centro=0;
      sum_esquinas=0;
      med=c/2;
      CM2=(CM*4)/c;
      if(c%2!=0 && esoterico==true){ /*si el numero de filas y columnas es par*/
        sum_lados=cuadrado[0][med] + cuadrado[c-1][med] + cuadrado[med][0] + cuadrado[med][c-1];
        sum_centro=cuadrado[med][med];
        sum_esquinas=cuadrado[0][0]+cuadrado[0][c-1]+cuadrado[c-1][0]+cuadrado[c-1][c-1];
        if(CM2!=sum_lados || CM2!=4*sum_centro || CM2!=sum_esquinas)
          esoterico=false;
      }
      else if(c%2==0 && esoterico==true){
        sum_lados=cuadrado[0][med]+cuadrado[0][med-1] + cuadrado[med][0] + cuadrado[med-1][0] + cuadrado[c-1][med] + cuadrado[c-1][med-1] + cuadrado[med][c-1] + cuadrado[med-1][c-1];
        sum_centro=cuadrado[med][med]+cuadrado[med][med-1]+cuadrado[med-1][med]+cuadrado[med-1][med-1];
        sum_esquinas=cuadrado[0][0]+cuadrado[0][c-1]+cuadrado[c-1][0]+cuadrado[c-1][c-1];
        if(2*CM2!=sum_lados|| CM2!=sum_centro || CM2!=sum_esquinas)
          esoterico=false;         
      }
      if(esoterico==false){
        cout<<"DIABOLICO"<<endl;        
      }
      else{
        cout<<"ESOTERICO"<<endl;         
      }
    }
    else{
      cout<<"NO"<<endl;
    }
  }


  return 0;
}

twitter/insta: @dgr_099 ;-)
#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;
#define num 5;
int main(){
  //variables
  char tab[]={'D', 'A', 'M', 'I', 'C'};
  string tab2[]={"DESAYUNOS#", "COMIDAS#", "MERIENDAS#", "CENAS#", "COPAS#"};
  long double *din, media, max, min, aux;
  char c;
  int i, z, comidas;
  int repetido_max, repetido_min, ind_max, ind_min;
  din=(long double*)calloc(5, sizeof(long double)); /*reseteamos el array de dinero*/ 
  media=comidas=z=0;

   while((cin>>c>>aux)){
    if(!(c=='N' && aux==0)){ //si no se cumple la condición de parada
      for(i=0; i!=5; i++){
        if(tab[i]==c){
          z++; //suma uno al numero total
          if(i==1){ //si es una comida suma uno al numero de comidas
            comidas++;
          }
          din[i]+=aux;
          media+=aux;
          break;
        }
      }
    }

    else{ //si c=N y aux=0 fin del dia y pones los resultados
      min=max=din[0];
      ind_min=ind_max=repetido_max=repetido_min=0; 
      for(i=1; i!=5; i++){
        if(din[i]>max){
          max=din[i];
          ind_max=i;
          repetido_max=0;
        }
        else if(din[i]==max){
          repetido_max=1;
        }
        if(din[i]<min){
          min=din[i];
          ind_min=i;
          repetido_min=0;
        }
        else if(din[i]==min){
          repetido_min=1;
        }
      }
      //si el max esta repetido se pone empate, si no, se pone el max, lo mismo con el minimo, y por ultimo se comprueba si la comida (din[a]) es mayor que la media
      cout << (repetido_max==1 ? "EMPATE#" : tab2[ind_max]) << (repetido_min==1 ? "EMPATE#" : tab2[ind_min]) <<((din[1]/comidas)>(media/z) ? "SI" : "NO")<<endl; /*imprimimos los resultados*/
      /*inicializamos los datos para repetir el bucle*/
      z=comidas=media=0; //ponemos los contadores a 0
      //formateamos las matrices de dinero y datos
      free(din);
      din=(long double*)calloc(5, sizeof(long double));
    }

  }
  free(din);
  return 0;
}

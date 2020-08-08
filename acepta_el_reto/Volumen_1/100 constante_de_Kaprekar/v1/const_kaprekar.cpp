twitter/insta: @dgr_099 ;-)
#include <iostream>
#include <string.h>
using namespace std;
#define NUM_MAX 4
#define MAX_CASES 9999
int main(){
  int j=0, i=0, z=0, vueltas=0, h=0, l=0;
  long long o[MAX_CASES], inv;
  char *der, *max;
  cin >> i;
  for(j=0; j!=i; j++){/*guardas todos los números en un array*/
    cin >> o[j];
  }

  for(j=0; j!=i; j++){ /*por cada uno de esos arrays ejecutas las acciones principales*/
    vueltas=0;  /*inicializa las vueltas a 0*/
    if(o[j]==6174){ /*si resulta que el número es la propia constante imprime directamente 0*/
      goto fin_bucle;
      continue;   
    }

    while(o[j]!=6174){ /*mientras que el numero no sea la const*/
      if(!(max=(char*)calloc(4, sizeof(char)))){ /*utilizo punteros para reiniciar su valor en cada vuelta*/
        return 1;
      }  
      if(!(der=(char*)calloc(4, sizeof(char)))){
        free(max);
        return 1;
      }      
      /*rellenamos el string añadiendo los 0 necesarios con ayuda de max*/
      if(o[j]<10){
        for(z=0; z!=3; z++){
          der[z]='0';
        }
        sprintf(max, "%lld", o[j]);
        strcat(der, max);
      }
      else if(o[j]<100){
        for(z=0; z!=2; z++){
          der[z]='0';
        }
        sprintf(max, "%lld", o[j]);
        strcat(der, max);
      }
      else if(o[j]<1000){
        for(z=0; z!=1; z++){
          der[z]='0';
        }
        sprintf(max, "%lld", o[j]);
        strcat(der, max);        
      }
      else{
        sprintf(der, "%lld", o[j]);        
      }
      for(h=z=0; h!=4; h++){ /*busco el máx para ahorrar busquedas en el siguiente bucle*/
        if(z<int(der[h] - '0')){
          z=der[h] - '0';
        }
      }
      for(z, l=0; z!=-1 && l!=4; z--){ /*ordenas los numeros de mayor a menor con apoyo de der en max (busca si se encuentra el max, si esta se introduce si no busca el siguiente)*/
        for(h=0; h!=4; h++){
          if(der[h]==(char)z + '0'){
            max[l]=der[h];
            l++;
          }
        }
      }
      for(z=4-1, l=0; z!=-1; z--, l++){
        der[l]=max[z];/*inviertes en derecho para obtener el min*/
      }
      if(strcmp(der, max)==0){/*compruebas que no sean iguales, en cuyo caso se trataria de un repdigits*/
        vueltas=8;
        free(max);
        free(der);
        goto fin_bucle;
      }
      o[j]=atoll(max);
      inv=atoll(der);
      free(max);
      free(der);
      o[j]=o[j]-inv;
      vueltas++;
    }
    fin_bucle:
    cout<< vueltas << endl;
  }
  return 0;
}

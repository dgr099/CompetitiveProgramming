twitter/insta: @dgr_099 ;-)
//sin terminar//
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main(){
  int i, tam_a, tam_b, tam_t, z, j, aux_1, aux_2, filas;
  string linea, lin;
  char *rima_A=NULL, *rima_B=NULL, car1, car2;
  vector<string> poema;
  
  while(cin>>filas && filas!=0){
    cin.ignore();
    poema.clear();
    cin.ignore();
    rima_A=(char*)calloc(72, sizeof(char));
    rima_B=(char*)calloc(72, sizeof(char));    
    //insertamos el poema
    for(i=0; i!=filas; i++){
      getline(cin, linea);
      poema.push_back(linea);
    }
    switch (filas)
    {
    case 2:
      i=0;
      z=strlen(&poema[0][0])-1;
      j=strlen(&poema[1][0])-1;              //si alguna de las comparaciones no es una letra
      for(i=aux_1=aux_2=0; poema[0][z]==poema[1][j] || ((poema[0][z]>'Z' && 'A'>poema[0][z]) && (poema[0][z]>'z' && 'a'>poema[0][z])) || ((poema[1][j]>'Z' && 'A'>poema[1][j]) && (poema[1][j]>'z' && 'a'>poema[1][j]));rima_A[i]=poema[0][z], i++, z--, j--){
        car1=poema[0][z];
        car2=poema[1][j];
        
        if(isalpha(car1)){ //si z era una letra activa aux1
          aux_1=1;
          if(isalpha(car2)){ //si los dos son vocales todo bien
            continue;
          }
          j++; //si j no es caracter pero 
          i--;
        }
        if(isalpha(car2)){ //si j era una letra activa aux2
          aux_2=1;
        }
        aux_1=aux_2=0;
      }
      if(i>1){
        cout<<"PAREADO"<<endl;
        break;
      }
      cout<<"DESCONOCIDO"<<endl; 
      break;

    case 3:
      z=strlen(&poema[0][0])-1;
      j=strlen(&poema[2][0])-1;
      for(i=0; poema[0][z]==poema[2][j]; rima_A[i]=poema[0][z], i++, j--, z--);
      if(i>1){
        lin=poema[1].substr(poema[0].size()-i); //se coge el final de la linea ya que al ser solo llanas la rima esta al final
        if(lin.compare(rima_A)==0){
          cout<<"DESCONOCIDO"<<endl; //si todas riman será desconocido
          break;
        }
        cout<<"TERCETO"<<endl; //si solo riman la primera y la ultima será un terceto
        break;
      }
      cout<<"DESCONOCIDO"<<endl; //si directamente no existe rima será desconocido
      break;

    default: //4 filas
      z=strlen(&poema[0][0])-1;
      j=strlen(&poema[3][0])-1;
      for(i=0; poema[0][z]==poema[3][j]; rima_A[i]=poema[0][z], i++, j--, z--);
      if(i>1){ //si la primera y la ultima tienen rima solo puede ser cuarteto ABBA, cuaderna via AAAA, o desconocido
        z=strlen(&poema[1][0])-1;
        j=strlen(&poema[2][0])-1;
        for(i=0; poema[1][z]==poema[2][j]; rima_B[i]=poema[1][z], i++, z--, j--);
        if(i>i){ //si las dos del medio tienen rima entonces no puede ser desconocido, falta ver si es la misma rima que rima_A o es una rima nueva
          tam_a=strlen(&rima_A[0]);
          tam_b=strlen(&rima_B[0]);
          (tam_a<tam_b ? tam_t=tam_a : tam_t=tam_b);//se coge al menor
          if(strncmp(&rima_A[tam_a-tam_t], &rima_B[tam_b-tam_t], tam_t)==0){
            cout<<"CUADERNA VIA"<<endl;
            break;
          }
          cout<<"CUARTETO"<<endl;
          break;
        }
        cout<<"DESCONOCIDO"<<endl; //si solo rima la 1 y la 4 entonces es deconocido
        break;
      }
      //si la primera y la ultima no tienen rima solo puede ser seguidilla /A/A o Cuarteta ABAB
      z=strlen(&poema[0][0])-1;
      j=strlen(&poema[2][0])-1;
      for(i=0; poema[0][z]==poema[2][j]; rima_A[i]=poema[0][i], i++, j--, z--);
      if(i>1){ //si la primera y la 3º tienen rima solo puede ser cuarteta
        z=strlen(&poema[1][0])-1;
        j=strlen(&poema[3][0])-1; 
        for(i=0; poema[1][i]==poema[3][i]; rima_B[i]=poema[0][i], i++, j--, z--);
        if(i>1){ //si el 2 y el ultimo tienen rima se trata de una cuarteta
          cout<<"CUARTETA"<<endl;
          break;
        }
        cout<<"DESCONOCIDO"<<endl;
        break;
      }
      //si no tienen rima puede ser una seguidilla o no ser nada
      z=strlen(&poema[1][0])-1;
      j=strlen(&poema[3][0])-1;
      for(i=0; poema[1][i]==poema[3][i]; rima_B[i]=poema[0][i], i++, j--, z--);
      if(i>1){
        cout<<"SEGUIDILLA"<<endl;
        break;
      }
      cout<<"DESCONOCIDO"<<endl;
      break;
    }
    free(rima_A);
    free(rima_B);
  }
  return 0;
}

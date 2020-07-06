#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
using namespace  std;
#define MAX_STR 300 /*1.000-->5 bits/numero * 50 numeros + 49 espacios de separacion entre numero=299*/
int main(int argc, char **argv){
  int f, i, r;
  float aux;
  bool flag=true;
  char *temp;
  char fila[MAX_STR];
  do{
    cin >> f; /*guarda las filas de la matriz*/
    cin.ignore();
    for(flag=true, i=0; i!=f; i++){ /*por cada fila comprueba que se cumplen los requisitos para ser matriz identidad*/
      cin.getline(fila, MAX_STR);
      temp=strtok(fila, " ");      
      for(r=0; r!=f; r++, temp=strtok(NULL, " ")){
        aux=atof(temp);
        if(r!=i){
          if((aux)!=0){
            flag=false;
            break;
          }
          continue;          
        }
        //considerando como mil el .
        /*if(aux<0 && temp[2]=='.'){ //el único caso en el que se equivoca es en 1.000 el resto no daran problemas ya que se confundiran con valores <1
          flag=false;
          continue;
          }*/        
        if(aux!=1){
          flag=false;
          break;          
        }
      }
    }


    if(f!=0){ 
      if(flag==true){
        cout<<"SI"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }


  }while(f!=0);
  return 0;
}
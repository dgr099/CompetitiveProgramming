#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
//#include <bits/stdc++.h>
typedef struct{
    char nombre[100];
    int casos;
}moda;

int main(){
    int casos;
    int tam;
    moda modas[40000];
    scanf("%d\n", &casos);
    tam=-1;
    int m;
    int aux=1;
    int ind=0;
    int ant;
    while(casos--){
        char aux[max];
        int aux_2;
        short aux_3=-1;
        aux_2=tam;
        fgets(aux, max, stdin); /*leemos el string*/
        while(aux_2>=0 && (aux_3=strcmp(modas[aux_2].nombre, aux))!=0){
            aux_2--;
        }
        if(aux_2<0){ /*si no lo has encontrado*/
            strcpy(modas[++tam].nombre, aux);
            modas[tam].casos=1;
            continue;
        }
        /*si llegas hasta aquí es que lo has encontrado*/
        modas[aux_2].casos++;
        aux_3=modas[aux_2].casos;
        aux_2--;
        /*toca ordenarlo*/
        while(aux_2>=0 && modas[aux_2].casos<aux_3){
            modas[aux_2+1]=modas[aux_2];
            aux_2--;
        }
        modas[aux_2+1].casos=aux_3;
        strcpy(modas[aux_2+1].nombre, aux);
    }
    /*tenemos una cadena ordenada por tamaño*/
    scanf("%d\n", &m);
    ant=modas[0].casos;
    while(aux!=m && ind<=tam){
        if(modas[ind].casos!=ant){
            aux++;
            ant=modas[ind].casos;
            continue; /*mantengo el indice por si es el que me piden*/
        }
        ind++;
    }
    if(ind>tam){
        printf("0\n");
    }
    while(modas[ind].casos==ant){
        printf("%s", modas[ind].nombre);
        ind++;
    }



    return 0;
}
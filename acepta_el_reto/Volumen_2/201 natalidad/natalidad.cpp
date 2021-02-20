
#include "bits/stdc++.h"
/**
 * si no tiene hijos retorna 1
 * si tiene 1 hijo retorna 2
 * si tiene 2 hijos retorna 3
 */
using namespace std;
int recurs(int *index, int *size, string *tree){
    int l, r;
    if(tree->at(*index)=='.'){
        return 0;
    }
    (*index)++;
    l=recurs(index, size, tree);
    (*index)++;
    r=recurs(index, size, tree);
    if(l==r){
        /*no tiene hijos*/
        if(r==0)
            return 1;
        /*tiene 2 hijos*/
        /*si tiene 2 que no tienen hijos o tiene 2 que tienen 2 hijos*/
        if(r==1 || r==3)
            return 3;
    }

    /*tiene un hijo*/
    /*si tiene solo un hijo o tiene un hijo que tiene solo un hijo*/
        if((l==1 && r==0) || (r==1 && l==0)){
            return 2;
        }
        if((l==2 && r==0) || (r==2 && l==0)){
            return 2;
        }
    /*tiene dos hijos*/
    /*si tiene uno sin hijos y otro con dos hijos*/
        if(r==3 && l==1 || r==1 && l==3){
            return 3;
        }

    else
        return 4;

}

int main(){
    //si ningun matrimonio tiene más de un hijo->1
    //si todos los que tienen, tienen 2 hijos->2
    //si no es ninguna de las anteriores N
    string entrada;
    int tam;
    while(cin>>entrada && (tam=entrada.length())>1){
        int index=0;
        int cod=recurs(&index, &tam, &entrada);
        switch (cod)
        {
            /*si no tiene hijos cumple tanto una como dos*/
        case 1:
            cout<<12<<endl;
            break;
            /*si todos tienen un hijo cumple 1*/
        case 2:
            cout<<1<<endl;
            break;
        case 3:
            /*si todos tienen 2 cumple 2*/
            cout<<2<<endl;
            break;
            /*si no cu,ple ninguna*/
        default:
            cout<<'N'<<endl;
            break;
        }
    }
    return 0;
}
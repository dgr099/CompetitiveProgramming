#include "bits/stdc++.h"
using namespace std;
int fib[1000] = {0};
/*calcular los numeros de fibonacci*/
void fibonacci(int num){
    if(!fib[num] && num!=0){
        fibonacci(num-1);
        fibonacci(num-2);
        fib[num]=fib[num-1]+fib[num-2];
    }
    return;
}

void printFib_rec(int num, int *prof){
    if(num<=1) return;

    for(int i=0; i!=*prof; i++){
        cout<<"   ";
    }
    /*imprimimos hijo izq*/
    cout<<fib[num-2]<<endl;
    (*prof)++
    /*imprimimos los hijos del hijo izq*/;
    printFib_rec(num-2, prof);
    (*prof)--;
    for(int i=0; i!=*prof; i++){
        cout<<"   ";
    }
    /*imprimimos hijo der*/
    cout<<fib[num-1]<<endl;
    /*imprimimos hijos del hijo derecjo*/
    (*prof)++;
    printFib_rec(num-1, prof);
    (*prof)--;
}

void printFib(int num){
    int aux=num;
    int prof=1;
    //imprime el numero "raiz"
    cout<<fib[aux]<<endl;
    printFib_rec(num, &prof);
}
int main(){
    int prof=0;
    fib[0]=0, fib[1]=1;
    while(cin>>prof && prof>-1){
        fibonacci(prof);
        printFib(prof);
        cout<<"====\n";
    }
}
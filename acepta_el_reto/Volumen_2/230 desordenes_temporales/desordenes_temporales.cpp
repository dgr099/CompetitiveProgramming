/**nivel de desorden temporal--> numero de personas que aun siendo más viejas 
 *      que uno mismo desde el punto de vista administrativo, han vivido menos días
 * se quiere conocer la suma de desordenes temporales
 * 
 */

#include "bits/stdc++.h"
using namespace std;

/*void swap(long long *a, long long *b){
    long long aux_3=*a;
    *a=*b;
    *b=aux_3;
}*/

long long Merge(long long *v, int a, int b){
    int m=(a+b)/2;
    int aux_1=m-a; //tamaño izq-1 va desde a hasta m incluida
    int aux_2=b-(m+1); //tamaño der va desde m+1 hasta b incluido
    long long izq[aux_1+1];
    long long der[aux_2+1];
    long long inv=0;
    /*auxiliares para copiar izquierda y derecha*/
    for(int i=0; i<=aux_1; i++){
        izq[i]=v[a+i];
    }
    for(int i=0; i<=aux_2; i++){
        der[i]=v[(m+1)+i];
    }
    int i, j, k;
    i=j=0;  k=a;
    /*vas comprobando los topes*/
    while(i<=aux_1 && j<=aux_2){
        /*si lo de la izquierda es menor, va primero eso*/
        if(izq[i]<=der[j]){
            
            v[k]=izq[i];
            i++;
            /*este, esta en inversión con todos los de la derecha que se hayan puesto antes ya que cada subtabla está ordenada*/
            inv+=j;
            /*si por el contrario lo de la derecha es menor*/
        }   else{
            v[k]=der[j];
            j++;

        }
        k++;
    }
    while(i<=aux_1){
        v[k]=izq[i];
        i++;
        k++;
        inv+=j;
    }
    while(j<=aux_2){
        v[k]=der[j];
        j++;
        k++;
    }
    return inv;    
}
//a->inicio del vector, b->fin del vector
long long MergeSort(long long *v, int a, int b){
	long long inversiones = 0;
    long long m= (b+a)/2; //punto medio
	if (b <= a) {
		return inversiones;		
	}
	inversiones +=MergeSort(v, a, m); //uno va de a hasta m incluido
	inversiones +=MergeSort(v, m+1, b); //la otra mitad desde m sin incluir hasta b
	inversiones += Merge(v, a, b); //juntas las mitades y calculas las inversiones
	return inversiones;
}

int main(){
    int nhab;
    cin.tie(NULL); cout.tie(NULL);
    while(cin>>nhab && nhab!=0){ //numero de dias vividos ordenados por edad administrativa
        long long dias [nhab];
        //vector<int> aux(nhab);
        long long sum=0;
        cin>>dias[0];
        for(int i=1; i!=nhab; i++){
            cin>>dias[i];
            //numero de personas mayores con menos dias
            //              ==
            //numero de personas menores con mas dias
            //              ==
            //numero de inversiones
            //metodo burbuja TLE
            /*for(int aux_2=i; aux_2!=0 && dias[aux_2-1]>dias[aux_2]; aux_2--){
                    //swap(&dias[aux_2-1], &dias[aux_2]);
                    swap(dias[aux_2-1], dias[aux_2]);
                    sum++;
                }*/
            }
            //metodo MergeSort
            sum=MergeSort(dias, 0, nhab-1);
            cout<<sum<<endl;
        }
    return 0;
    }
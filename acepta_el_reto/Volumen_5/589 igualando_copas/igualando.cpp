/*no es posible guardar toda la entrada por lo que debe ser haber alguna forma de leer y procesar la entrada a la vez*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long num=0;
    while(cin>>num && num!=0){
        long long aux=0, max=0, sum=0, copas=0, dif=0;
        for(aux=0; aux!=num; aux++){
            cin>>copas;
            if(copas>max){ //nuevo máximo
                dif=copas-max; //<-diferencia entre el nuevo máximo y el anterior
                max=copas; //<- nuevo máximo
                sum+=dif * (aux); //<- compensamos las sumas que faltan para que todos se igualen con el nuevo máximo
            }   else    sum+=max-copas; //si no hay nuevo máximo simplemente sumamos lo que nos falta para igualar al máxmo
        }
        cout<<sum<<endl;
    }
    return 0;
}

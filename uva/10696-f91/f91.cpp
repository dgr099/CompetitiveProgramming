#include <bits/stdc++.h>
using namespace std;
int f91(int &num){
    if(num>100)
        return num-10;
    num+=11;
    int aux=f91(num); //f91(num+11)
    return f91(aux); //f91(f91(nunm+11))
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int casos, aux;
    while(cin>>casos && casos!=0){
        aux=casos;
        printf("f91(%d) = %d\n", aux, f91(casos));
    }
    return 0;
}
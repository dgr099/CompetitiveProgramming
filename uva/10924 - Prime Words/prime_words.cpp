#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    string palabra;
    short criba[1041]={0};
    for(int i=2; i*i<=52*20; i++){
        int z=i;
        int total;
        int j=z;
        for(total=j*z; total<=52*20; z++, total=j*z){
            criba[total]=1;
        }
    }
    /*for(int i=1; i<=1040; i++){
        if(criba[i]==0){
            printf("%d ", i);
        }
    }*/
    while(cin>>palabra){
        int sum=0;
        int aux=palabra.length();
        for(int i=0, t=aux; i!=t; i++){
            if(palabra[i]>='a' && palabra[i]<='z'){
                sum+=palabra[i]-'a'+1;
            }   else{
                sum+=palabra[i]-'A'+27;
            }
        }
        criba[sum]==0 ? printf("It is a prime word.\n") : printf("It is not a prime word.\n"); 
    }
    return 0;
}
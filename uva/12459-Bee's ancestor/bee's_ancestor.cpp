#include <bits/stdc++.h>
using namespace std;
long long f[81]={ 1, 1 };
void f_rec(long long &num){
    if(f[num]!=0)  return;
    long long aux;
    if(f[num-1]==0){
        aux=num-1;
        f_rec(aux);
    }
    if(f[num-2]==0){
        aux=num-2;
        f_rec(aux);
    }
    f[num]=f[num-1]+f[num-2];

}
void fibonacci(long long &num){
    if(f[num]!=0){
        return;
    }
    f_rec(num);

}
int main(){
    long long casos;
    while(scanf("%lld", &casos) && casos!=0){
        fibonacci(casos);
        printf("%lld\n", f[casos]);
    }
}
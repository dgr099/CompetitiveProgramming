/*si es menor que 101 va a ir sumando 1 hasta llegar al limite que sera cuando retorne 101 y al restar 10 devuelva 91*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int casos;
    while(scanf("%d", &casos) && casos!=0){
        casos>=101 ? printf("f91(%d) = %d\n", casos, casos-10) : printf("f91(%d) = 91\n", casos);
    }
    return 0;
}
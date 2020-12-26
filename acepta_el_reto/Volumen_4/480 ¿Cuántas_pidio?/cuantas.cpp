#include <bits/stdc++.h>
using namespace std;
void fast_int(int &num){
    char c=getchar_unlocked();
    while(c==' ')   c=getchar_unlocked();
    while(c>='0' && c<='9'){
        num=(num<<3) + (num<<1) + c-'0';
        c=getchar_unlocked();
    }
    return;
}
int main(){
    cin.tie(NULL);  cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cas=0;
    //cin>>cas;
    fast_int(cas);
    while(cas--){
        int total, a, b, aux;
        total=a=b=0;
        fast_int(total);    fast_int(a);    fast_int(b);
        //cin>>total>>a>>b;
        aux=total%b;
        if(aux>=a){
          cout<<(total/b+1) * a<<endl;
          continue;  
        }
        cout<<total/b*a + aux<<endl; 
    }
    return 0;
}

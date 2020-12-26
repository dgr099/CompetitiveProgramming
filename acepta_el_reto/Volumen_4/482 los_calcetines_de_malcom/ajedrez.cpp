#include <bits/stdc++.h>
using namespace std;
void fast(int &num){
    char c;
    while(c=getchar_unlocked() && c==' ');
    while(c<='9' && c>='0'){
        num=((num<<3) + (num<<1)) + c-'0';
        c=getchar_unlocked();
    }
    return;
}
int main(){
    cin.tie(NULL);  cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int x, y;
    char tab_x[8]={'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    while(cin>>x>>y && !(x==0 && y==0)){
        cout<<tab_x[x-1]<<y<<endl;
    }
    return 0;
}
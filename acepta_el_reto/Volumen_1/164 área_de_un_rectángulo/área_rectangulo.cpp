#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
  pair<int, int> o, f;
  while(cin>>o.first>>o.second>>f.first>>f.second && !(o.first>f.first || o.second>f.second)){
    printf("%d\n", (f.first-o.first)*(f.second-o.second));
    //cout<<(f.first-o.first)*(f.second-o.second)<<"\n";
  }

}
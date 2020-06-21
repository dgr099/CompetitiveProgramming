#include <iostream>
using namespace std;
int main(){
  long long n, i, j;
  cin>>j;
  for(int z=0; z!=j; z++){
    cin>>n;
    /*for(i=n-1; i!=1; i--){
      n*=i;
    }
    cout<<n%10<<endl;
    */

    // 5!=5*4!=5*4*3!=5*4*3*2!=5*4*3*2=5*24=120
    // 6!=6*5!=6*120
    // {xeR | x>4}--> x!=x*x-1!=x*x-1*x-2!=x*x-1*x-2*....5!
    if(n==0 || n==1){
      cout<<1<<endl;
      continue;
    }
    if(n>=5){
      cout<<0<<endl;
      continue;
    }
    if(n==3){
      cout<<6<<endl;
      continue;
    }
    if(n==4){
      cout<<4<<endl;
      continue;
    }
    cout<<2<<endl;
    continue;
  }
  return 0;
}
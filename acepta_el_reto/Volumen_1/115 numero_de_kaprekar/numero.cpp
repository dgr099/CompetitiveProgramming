#include <iostream>
#include <cmath>
using namespace std;
int main(){
  long long num,num2, part1, part2, i, z, max, flag;
  while(cin>>num && num!=0){
    num2=num*num;
    max=log10(num2)+1;
    for(z=flag=0, i=10, part1=num2/i, part2=num2%i; z!=max ; i*=10, part2=num2%i, part1=num2/i){ //z!=max
      z++;
      if(part1+part2==num && (part2!=0)){
        cout<<"SI"<<endl;
        flag=1;
        break;
      }
    }
    if(flag==0){
      cout<<"NO"<<endl;
      continue;
    }
  }
  return 0;
}
/**\                           /
 *  \-----    <---->    ------/
 * Cuando invertimos que estamos haciento realmente?
 */
#include <bits/stdc++.h>
using namespace std;
int modulo(int &num1, int num2){
  num1 = num1%num2;
  if(num1<0) num1+=num2;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int casos;
  cin>>casos;
  while(casos--){
    int hora, min, dif;
    cin>>hora; cin>>min;
    modulo(hora-=2*hora, 12);
    if(min>0) modulo(hora-=1, 12);
    if(hora==0) hora=12;
    modulo(min-=2*min,  60);
    /*if(hora<10) printf("0");
    printf("%d:",hora);
    if(min<10) printf("0");
    printf("%d\n", min);*/
    printf("%02d:%02d\n", hora, min);
  }
}
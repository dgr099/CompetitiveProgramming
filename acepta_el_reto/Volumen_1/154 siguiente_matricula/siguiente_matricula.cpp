/** Notas:
 *  saltate las vocales
 */
#include <bits/stdc++.h>
using namespace std;
void subir_letra(string &palabra, int &num){
  if(num==-1) return; //si llegamos al final será el caso de parada
  if(palabra[num]=='Z'){
    palabra[num]='B';
    num--;
    return subir_letra(palabra, num);
  }
  palabra[num]++;
  while(palabra[num]=='A' || palabra[num]=='E' || palabra[num]=='I' || palabra[num]=='O' || palabra[num]=='U'){
    palabra[num]++;
  }
  return;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int num, index; string fra, tot;
  char *tok;
  while(cin>>num>>fra && !(num==9999 && fra=="ZZZ")){
    num=((num+1)%(10000));
    if(num==0){ //si da la vuelta el numero
      index=fra.length()-1;
      subir_letra(fra, index);
    }
    if(num>999){
      goto final;
    }
    else if(num<10){
      printf("000");
    } else if(num<100){
        printf("00");
      } else if(num<1000){
        printf("0");
      }
final:
    printf("%d %s\n", num, &fra[0]);
  }
  return 0;
}
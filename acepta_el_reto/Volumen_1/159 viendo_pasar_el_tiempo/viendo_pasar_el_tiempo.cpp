/**los numeros van de 0 a 9 (00, 10, 20, 30, 40, 50) 6 veces por hora
 * ojo no es cuantas numeros veas si no cuantas veces ves 1 o mas
 * luego, del 0 al 5 se repiten otras 10 veces por hora 00 01 02 03 04 05 06 07 08 09
 * veras 15 veces el numero por hora como maximo
 */
#include <bits/stdc++.h>
using namespace std;
/*void read(int &num){
  num=0;
  char f=getchar_unlocked();
  while(!isdigit(f))  f=getchar_unlocked();
  while(isdigit(f)){
    num = (num<<3) + (num<<1) + f - 48;
    f=getchar_unlocked();
  }
}*/
void read(pair<int, int> &inicio, pair<int, int> &fin, int &num){
  string cadena; getline(cin, cadena);
  char *tok;  
  tok=strtok(&cadena[0], ":");  inicio.first=atoi(tok); 
  tok=strtok(NULL, " ");  inicio.second=atoi(tok);
  tok=strtok(NULL, ":");  fin.first=atoi(tok);
  tok=strtok(NULL, " ");  fin.second=atoi(tok);
  tok=strtok(NULL, "\n"); num=atoi(tok);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  cout.tie(NULL);
  pair<int, int> h_i, h_f; //hora_inicio, hora_final;
  int num;
  h_i.first=h_i.second=h_f.second=h_f.first=24;
  while(read(h_i, h_f, num), h_i.first!=24){
    int total=0;
    while(!(h_f.first==h_i.first && h_f.second==h_i.second)){
      if(h_i.first/10==num || h_i.second/10==num || h_i.first%10==num || h_i.second%10==num) total++;
      h_i.second++;
      if(h_i.second==60){
        h_i.second=0;
        h_i.first++;
      }
    }
    if(h_i.first/10==num || h_i.second/10==num || h_i.first%10==num || h_i.second%10==num) total++;
      h_i.second++;
    printf("%d\n", total);
  }
  return 0;
}
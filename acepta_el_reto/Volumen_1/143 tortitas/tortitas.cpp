/**    5
 * 1   5   
 * 2   4
 * 3   3
 * 4   2
 * 5   1
 * 
 *     3  2
 * 1   3  2 
 * 2   2  3
 * 3   1  1
 * 4   4  4
 * 5   5  5
 * 
 * 
 */ 

#include <bits/stdc++.h>
using namespace std;
void input(short &num){
  num=0;
  char c = getchar_unlocked();
  while(isspace(c)) c=getchar_unlocked();
  if(c=='-'){
    c=getchar_unlocked(); //nos quitamos el 1
    num=-1;
    return;
  }
  while(isdigit(c)){
    num=(num<<3) + (num<<1) + c-'0';
    c=getchar_unlocked();
  }
  return;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  short aux;
  input(aux);
  while(aux!=-1){
    vector<short> vi;
    vi.push_back(aux);
    input(aux);
    while(aux!=-1){ //mientras recivas vas metiendo en las tortitas
      vi.push_back(aux);
      input(aux);
    }
    //cin>>aux; //guardas el numero de veces que volteas
    input(aux);
    while(aux--){ //das las vueltas
      short tort;
      //cin>>tort; //guardas el numero de tortitas que coges
      input(tort);
      short a, b, c, d;
      //desde la posicion que dicen (max-tort) tienes que hacer los cambios
      for(a=0, b=tort/2, c=vi.size()-tort--, d=vi.size()-1; a!=b; a++){
        iter_swap(vi.begin() + (d--), vi.begin() + (c++));
      }
    }
    printf("%d\n", vi.back());
    input(aux);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
short input(int &h, int &min){
  h=min=0;
  register char f=getchar_unlocked();
  while(!isdigit(f)) f=getchar_unlocked();
  while(isdigit(f)){
    h=(h<<3) + (h<<1) + f -'0';
    f=getchar_unlocked();
  }
  f=getchar_unlocked();
  while(!isdigit(f)) f=getchar_unlocked();
  while(isdigit(f)){
  min=(min<<3) + (min<<1) + f -'0';
  f=getchar_unlocked();
  }
  if(min==0 && h==0)
    return 0;
  min*=-1; h*=-1;
  return 1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  register int h, min; //horas y minutos en short para que ocupe menos :-)
  while(input(h, min)){ //mientras que leas datos todo gucci todo fresh
    h+=23; min+=60;
    //60=2^5+2^4+2^3+2^2 
    //h*60 se ppodria poner con desplazadores logicos y tal vez se ahorre tiempo no se -\(-_-)/-
    printf("%d\n", h*60+min)
  }
  return 0;
}
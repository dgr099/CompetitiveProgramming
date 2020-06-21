#include <iostream>
using namespace std;

bool isBalanced(int pi, int di, int pd, int dd, int *peso){
  bool left=true, right=true;
  int pii=0, dii=0, pid=0, did=0, pdd=0, ddd=0, pdi=0, ddi=0; /*peso izquiera del izquierdo...*/
  if(!pi){
    cin>>pii>>dii>>pdi>>ddi;
    left=isBalanced(pii, dii, pdi, ddi, &pi);
  }
  if(!pd){
    cin>>pid>>did>>pdd>>ddd;
    right=isBalanced(pid, did, pdd, ddd, &pd);
  }
  *peso=pi+pd;
  return left && right && pi*di==pd*dd;

}

int main(){
  int pd, pi, di,dd, w; /*peso derecha, peso izquiera, distancia izquierda, distancia derecha*/
  while(cin>>pi>>di>>pd>>dd && (pi!=0 || pd!=0 || di!=0 || dd!=0)){
    cout<<(isBalanced(pi, di, pd, dd, &w)==true ? "SI" : "NO")<<endl;
  }
  return 0;
}
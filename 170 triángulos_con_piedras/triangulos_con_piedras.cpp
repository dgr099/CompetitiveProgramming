/**Lado 1 -> 1 piedras
 * Lado 2 -> 2+1=3 piedras   
 * Lado 3 -> 3+2+1=6 piedras
 * Lado 4 -> 4+3+2+1=10
 * Para hacer un nuevo triangulo mayor basta con añadir la ultima fila al triangulo inmediatamente menor 
 * El numero de piedras del nuevo triangulo es:
 *    las piedras del triangulo inmediatamente menor + las piedras del lado del nuevo triángulo
 * se podría abordar con programación dinámica? imposible muchos casos :(
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int piedras;
  while(cin>>piedras && piedras!=0){
    int suma, i;
    for(i=suma=0; suma<=piedras;){
      i++;
      suma+=i;
    }
    suma-=i;
    i--;
    printf("%d %d\n", i, piedras-suma);
  }
  return 0;
}
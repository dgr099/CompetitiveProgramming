#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
  int num;
  while(scanf("%d", &num) && num!=0){
    //int *array;
    int array[num];
    //array=(int*)calloc(num, sizeof(int)); //creas la tabla con memoria dinamica para gastar lo justo y necesario
    for(int i=0; i!=num; i++){
      scanf("%d", &array[i]); //guardas los valores en la tabla
    }
    sort(array, array+num); //ordenas el array
    int lol=num/2;
    (num%2==0 ? printf("%d\n", array[lol]+array[lol-1]) : printf("%d\n", array[lol]<<1));
    //free(array); //liberas la memoria
  }
  return 0;
}
 #include <bits/stdc++.h>
 #define MAX 100
using namespace std;
void sig(long long *num){
  long long aux=*num;
  *num=0;
  while(aux){ //mientras que existe el num
  /**voy cogiendo digito a digito sus valores y elevandolos al cubo
   * por si no se ve, esto lo que hace es por ejemplo 342, al dividrlo por 10=34.2 el operador % recoge ese resto entonces tienes el 2 y lo eleva al cuvo
   * luego divido el numero entre 10, 34.2, como es un long long no guarda los decimales y entonces se queda en 34 y vuelta a empezar*/
    *num+=(aux%10)*(aux%10)*(aux%10); //podria usar pow si, pero no es muy fiable asi que mejor manual y todos happy
    aux/=10;
  }
}

int main(){
  long long num, aux, sec[MAX];
  /*ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);*/
  //while(cin>>num && num){
  while(cin>>num && num){ //mientras que leas un numero y este exista todo ok, todo correcto y yo que me alegro
    cout<<num;
    if(num==1){
      cout<<" -> cubifinito.\n"; //si el propio numero es el 1 todos felices
      continue;
    }
    sec[0]=num;
    int i=0;
    do{
      sig(&num);  sec[i+1]=num; //vamos guardando los numeros en la secuencia
      cout<<" - "<<num; //vas imprimiendo los numeros
      i++;
      for(int j=0; j<i; j++){
        if(sec[j]==sec[i]){ //si se cumple que has llegado a un punto de retorno de la secuencia
          i=0; //pones i=0 para salir del bucle
          break;
        }
      }
    }while(num!=1 && i); //en el momento en el que sea igual a 1 o que se repita dejará de mostrar
    if(num==1){
      cout<<" -> cubifinito.\n"; //si el propio numero es el 1 todos felices
      continue;
    }
    cout<<" -> no cubifinito.\n"; //si no es cubinfinito pues no lo es, fin del debate
  }
}
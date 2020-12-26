/**2025
 * 2020-2021-2022-2023-2024-2025-2026-2027-2028-2029-2030; el siguiente es el 2031 que ya no tiene ningun numero repetido
 */

#include <bits/stdc++.h>
using namespace std;
bool c_r(int num){ //cifras repetidas
  //el primer paso es ver si se trata de un numero con cifras repetidas o no
  bool *cifras, repetido=false; cifras=(bool*)calloc(10, sizeof(bool));
  for(; num!=0; num/=10){
    if(cifras[num%10]){
      free(cifras);
      return true;
    } 
    cifras[num%10]=true;
  }
  free(cifras); //ya no necesitamos la array, unicamente se emplea para ver si hay numeros repetidos o no
  return false;
}
/*CODIGO PARA CUANDO SE REPITEN DIGITOS*/
void repeticion_inf(pair<int, int> &info, int &year){
  if(!c_r(year)){ //el punto de parada es cuando ya no se repiten cifras
    info.first=year+1; //por tanto el año anterior es el ultimo
    return;
  }
  info.second++; //en cambio sí si tenía numeros repetidos sumamos 1 al numero de años con esa caracteristica
  year--; //bajamos un año
  return repeticion_inf(info, year); //va a ir bajando años de forma recursiva
}

void repeticion_sup(pair<int, int> &info, int &year){
  if(!c_r(year)){ //el punto de parada es cuando ya no se repiten cifras
    return; //no nos importa cual es el ultimo, solo requerimos del primero y de los años
  }
  info.second++; //en cambio sí si tenía numeros repetidos sumamos 1 al numero de años con esa caracteristica
  year++; //subimos un año
  return repeticion_sup(info, year); //va a ir subiendo años de forma recursiva
}
void repeticion(pair<int, int> &info, int &year){
  int aux=year;
  year++;
  repeticion_inf(info, aux); //el aux ira bajando los años
  repeticion_sup(info, year); //en cambio en year se conserva el año desde el que empieza e irá subiendo desde este (para evitar tener que repetir numeros hasta este)
}
/*****************************/

/*CODIGO PARA CUANDO NO SE REPITEN DIGITOS*/
void no_repeticion_inf(pair<int, int> &info, int &year){
  if(c_r(year)){ //el punto de parada es cuando ya no se repiten cifras
    info.first=year+1; //por tanto el año anterior es el ultimo
    return;
  }
  info.second++; //en cambio sí si tenía numeros repetidos sumamos 1 al numero de años con esa caracteristica
  year--; //bajamos un año
  return no_repeticion_inf(info, year); //va a ir bajando años de forma recursiva
}

void no_repeticion_sup(pair<int, int> &info, int &year){
  if(c_r(year)){ //el punto de parada es cuando ya no se repiten cifras
    return; //no nos importa cual es el ultimo, solo requerimos del primero y de los años
  }
  info.second++; //en cambio sí si tenía numeros repetidos sumamos 1 al numero de años con esa caracteristica
  year++; //subimos un año
  return no_repeticion_sup(info, year); //va a ir subiendo años de forma recursiva
}
void no_repeticion(pair<int, int> &info, int &year){
  int aux=year;
  year++;
  no_repeticion_inf(info, aux); //el aux ira bajando los años
  no_repeticion_sup(info, year); //en cambio en year se conserva el año desde el que empieza e irá subiendo desde este (para evitar tener que repetir numeros hasta este)
}
/****************************/


int main(){
  cin.tie(NULL);  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int casos;
  cin>>casos;
  while(casos--){
    int ano;
    cin>>ano;
    pair<int, int> info;  info.first=info.second=0;
    //(c_r(ano)==true ? repeticion(info, ano) : no_repetido(info));
    if(c_r(ano))  repeticion(info, ano);
      else  no_repeticion(info, ano);
    printf("%d %d\n", info.first, info.second);
  }
  return 0;
}
/** Los barcos no pueden tocarse si en horizontal ni en vertical ni en diagonal
 *
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  int n_b, aux, cas, aux_2, x_aux, size;
  //vector<pair<pair<int, int>, pair<int, int>>> lb; //coordenadas
in:
  while(cin>>n_b && (n_b!=0)){
    static bool tab[129][129], flag=false; //en el bool ponemos los puntos donde hay barco, le añado una barrera protectora de falses :-)
    map<int, int> barcos;
    vector<pair<pair<int, int>, pair<int, int>>> cord;
    vector<pair<int, int>> cord_s; //coordenadas sueltas (de varcos verticales)
    flag=false;
    for(int i=0; i!=n_b; i++){
      cin>>aux;
      barcos[aux]++;
    }
    cin>>cas; //lees el numero de casillas
    x_aux=size=0;
    //reseteo las booleanas
    flag=false;
    for(int a=0; a<=cas+1; a++){
      for(int b=0; b<=cas+1; b++){
        tab[a][b]=false;
      }
    }

    for(int i=1; i<=cas; i++){ //van de 0 cas-1
      for(int j=1; j<=cas; j++){
        cin>>aux;
        int z;
        if(flag==1){
          continue; //en el momento que detecta algun fallo termina el flujo nomral del problema
        }
        if(aux==1){
          // abajo no puedes hacer comparaciones porque aun no has leido los datos, todas las comprobaciones deben ser de datos superiores
          /* 1111  1111
          *     1
          * miras a ver, si esta en posicion ilegal independientemente de si es un barco vertical u horizontal (en aluna diagonal)
          */
          if(tab[j-1][i-1]==true || tab[j+1][i-1]==true){
            flag=1;//si alguna de las diagonales tiene problemas mal vamos
          }
          tab[j][i]=true; //ponemos esa posicion a true porque hay un trozo de barco
          x_aux=j; //guardas la posicion del inicio
          if(j==cas){
            goto v; //si esta en la ultima no puede ser horizontal
          }
          cin>>aux_2; //esto es para comprobar si es un barco horizontal
          j++; //incrementars la posicion de las x
          
          
          if(aux_2==1){ //si se trata de un barco horizontal
            /*aqui ya sabes que es horizontal así que compruebas si tenia alguno por arriba*/
            if(tab[x_aux][i-1]==true) //si concatenas dos barcos (hay barco arriba y abajo) pones la flag en true (compruebas arriba)
              flag=true;
            tab[j][i]=true; //vas poniendo los 1
            z=j;
            while(j<cas){
              cin>>aux_2;
              j++; //te vas desplazando horizontalmente
              z++;
              if(aux_2!=1){
                z--;
                break;
              }
              tab[j][i]=true; //vas poniendo los 1
              if(tab[j][i-1]==true || tab[z-1][i-1]==true || tab[z+1][i-1]==true) //si concatenas dos barcos (si arriba o en las diagonales hay) pones la flag en true
                flag=true;
            } //mientras leas 1 significa que estas aun en el barco horizontal
            //al terminar compruebas nuevamente las diagonales
            /** 1111   1111
             *     11111
             */
            if(tab[z-1][i-1]==true || tab[z+1][i-1]==true)
              flag==true;
            cord.push_back(make_pair(make_pair(x_aux, i), make_pair(z, i))); //guardas el inicio y finale de ese barco 
            if(--barcos[ cord[size].second.first - cord[size].first.first + 1]<0){ //restas uno al numero de barcos restantes de esa longitud
              flag=true; //si son negativos o 0 los barcos de esa longitud la flag se pondrá a true
            }
            size++; //aumentamos en 1 el size del vector cord
            //j++; //sumas la coordenada que no es un 1
            continue;
          }
          v:
          //si no se trata de un horizontal debe ser un vertical
          //las diagonales ya las has comprobado por lo que aquí simplemente los insertas en las coordenadas que tienes sueltas
          if(tab[x_aux][i-1]==false)//si es un nuevo barco lo introduces, si no, no es necesario, es uno nuevo si arriba no tenia barcos anteriores
            cord_s.push_back(make_pair(x_aux, i));
        }
      }
    }
    //al llegar aquí ya tenemos una leve idea de si esta bien o no y tenemos formado el mapa booleano
    if(flag==1){ //si alguno de ellos tuvo algún error
      printf("NO\n");
      continue;
    }
    //si no, hay que comprobar los verticales, ya sabes que los barcos estan bien colocados, falta saber si todos los barcos estan
    for(auto p : cord_s){ //vamos a ir mirando las coordenadas sueltas que teniamos para mirar los barcos
      int j, z;
      for(j=1, z=p.second; tab[p.first][z]==1; z++, j++);
      if(--barcos[j-1]<0){
        printf("NO\n");
        goto in;
      }
    }
    //miramos a ver si falta algun barco por colocar
    for(auto p : barcos){
      if(p.second>0){
        flag==true;
        break;
      }
    }
    printf((!flag ? "SI\n" : "NO\n")); //si despues de todas las comprobaciones no hay problemas, todo gucci 
  }
  return 0;
}
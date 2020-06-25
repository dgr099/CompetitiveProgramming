/** Planteamiento lógico
 * te piden las varillas de longitud determinada necesarias para fabricar los paraguas y la suma de la longitud de los excedentes
 * 200
 * 8 1 60 8 3 20 -1
 * 
 * 200->largo_s de la varilla
 * 8->nervios
 * 1->segmentos
 * 60->longitud por segmento
 * necesitas 8 segmentos en total, con cada varilla de 200 te da para 200/60=20/6=3.33 redondeas para abajo 3 (como usamos enteros redondea automatico)
 * dos casos principales:
 *    -si es multiplo los segmentos que puedes conseguir con cada varilla y el numero de segmentos necesarios ya lo tendriamos, por ejemplo si necesitaos 12 y con cada varilla hacemos 3, entonces necesitamos un total de 4 varillas, los retales mediran lo que midan los restos por las varillas - 1 ya que la ultima aun puede aprovecharse
 *    -si no es multiplo te dará un decimal, redondeas para arriba y todos felices por ejemplo 8, 8/3=2.6->3 con esto obtienes las varillas necesarias, ahora hay que calcular la long del ultimo retal que en este caso varia pues puedes necesitar hacer solo un trozo más, dos etc. el exceso del ultimo sera la longitud de la varilla menos lo que quites de la ultima varilla
 * hay que tener en cuenta que el ultimo retal lo puede aprovechar para el siguiente paraguas, pues el problema dice que lo desecha si es más corto de lo que necesita pero al cambiar de paraguas puede valer para este
 * 
 * 
 * */

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
  static long long largo_s, nervios, n_var, l_var, vs, vnp, vn, retales, retal_act, long_resto, sol_parcial,aux; //vs es varillas por superficie (las varillas que puedes hacer con la barilla grande que tienes), vn son las varillas necesarias
  int flag=0;
  while(cin>>largo_s && !(largo_s==-1)){ //guardas el largo_s en cm
    flag=aux=retales=vnp=vn=retal_act=0; //reseteamos los valores
    while(cin>>nervios && (nervios!=-1)){ //vas a ir guardando los grupos de paraguas
      cin>>n_var>>l_var;
      if(flag)
        continue; //leemos los numeros pero no operamos porque se sabe ya que es imposible
      /*
            \  |  /
             \ | /
         _ _ _\|/_ _ _ (simétrico por la parte de abajo) tiene 8 nervios, cada uno de ellos con 3 segmentos que miden x, 3*8 seran los segmentos totales
      
      */
    if(largo_s<l_var || l_var<=0){ //si el largo_s de cada varilla es mayor que le maximo o la longitud es negativa o innexistente
      cout<<"IMPOSIBLE"<<endl;
      flag=1;//esto nos saca del while principal pero seguimos en el ultimo, por eso necesitamos un flag porque despues tendremos más casos de prueba pero como hay uno imposible debe poner imposible directamente
      continue; 
    }
    vs=largo_s/l_var; //vs con esto sacas las varillas que puedes producir con cada larga
    vnp=nervios*n_var; //vnp varillas necesarias parciales, por cada nervio hay x segmentos y el producto será el numero de varillas necesarias parciales
    long_resto=largo_s-(vs*l_var);
    if(retal_act){ //si tenemos un retal act distinto 0 debemos comprobar si nos sirve o no
      if(retal_act/l_var){ //si es aprovechable
        if(retal_act>=vnp*l_var){ //si ademas de ser aprovechable, es más o justo lo que necesitamos, entonces no necesitamos nada más de lo que tenemos por lo tanto, unicamente actualizamos lo que nos quedaba del retal, y no sumamos retales porque aun puede servir para uno nuevo
          retal_act-=vnp*l_var;
          //no sumamos a retales ni a vn porque no hemos necesitado de más, hemos aprovechado los restos y aún, tal vez puedan volver a aprovecharse
          continue;
        }
        else{ //si no es más de lo que necesitamos pero aún sirve
          aux=retal_act/l_var; //lo que nos queda entre lo que mide una var para saber cuantas var podemos conseguir y se lo quitamos al numero total de varillas
          vnp-=aux;
          //no hace falta actualizar el retal actual porque más abajo se vuelve a actualizar, no es como ántes que tenía un continue
          //sumas lo que te queda al largo total de los retales
          retales+=retal_act-(aux*l_var); //el retal actual menos lo que gasta en las varillas que necesitas te da el resto y como sabes que no has llegado a terminar el paraguas los sumas a los retales
        }
      }
      else{
        retales+=retal_act; //sumas lo que te quedaba a la long total de los retales
        //innecesario lo de abajo porque después se actualiza su valor
        //retal_act=0; //quitas el resto que te queda porque no sirve (lo tiras)
      }
    }
    if(vnp%vs==0){ //si son multiplos
      sol_parcial=vnp/vs; //a las varillas necesarias se le suman las varillas necesarias para el paraguas/las varillas que puede producir cada segmento
      retal_act=long_resto;//guarda el resto por si sirve para el siguiente paraguas
    }
    else{ //si no es multiplo
      sol_parcial=ceil((long double)vnp/vs); //redondeas para arriba porque no puedes pedir una barra y media por ej
      retal_act=largo_s-((vnp-((sol_parcial-1)*vs))*l_var); //al largo_s de la ultima varilla le quitamos lo que necesitemos al final es decir del total de varillas le quitamos las que conseguimos máx utilizando a full cada varilla y el resto lo multiplicamos por la long de la varilla
    }
    //guardo la solucion parcial para hacer más eficiente el calculo de los retales
    retales+=long_resto*(sol_parcial-1); //-1 porque el ultimo puede servir para el nuevo paraguas
    vn+=sol_parcial; //sumas al numero total de partes las nuevas partes necesarias
    }
    retales+=retal_act;
    if(flag!=1)
      cout<<vn<<" "<<retales<<endl;
  }
  return 0;
}
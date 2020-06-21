#include <iostream>
#include <map>
using namespace std;
int main(){
  string categoria, equipo_1, equipo_2, *winner, *looser;
  int p1, p2, *win, *loo, c;
  long long partidos_t=0;
  map<string, int> map;
  pair<string, int> best;
  while(cin>>categoria && categoria.compare("FIN")!=0){ //mientras lea algo y lo que lea sea distinto de fin
    partidos_t=0;//iniciamos a 0 los partidos;
    map.clear();
    best=make_pair("EMPATE", 0);
    while(cin>>equipo_1 && equipo_1.compare("FIN")!=0){
      cin>>p1>>equipo_2>>p2;//recoges los valores restantes
      if(p1>p2){ //asignamos los puntos en funcion del ganador
        map[equipo_1]+=2;
        win=&map[equipo_1];
        loo=&map[equipo_2];
        winner=&equipo_1;
        looser=&equipo_2;
        map[equipo_2]++;
      }
      else{
        map[equipo_2]+=2;
        win=&map[equipo_2];
        loo=&map[equipo_1];
        winner=&equipo_2;
        looser=&equipo_1;
        map[equipo_1]++;
      }
      partidos_t++; //aumentamos los partidos
      //actualizamos los valores del campeon
      if((*win)>best.second){
        best=make_pair(*winner, *win);
      }
      else if((*win)==best.second){
        best=make_pair("EMPATE", *win);
      }
      if((*loo)>best.second){
        best=make_pair(*looser, *loo);
      }
      else if((*loo)==best.second){
        best=make_pair("EMPATE", *loo);
      }

    }
    c=map.size();
    //una vez se termina la liga se calcula los partidos restantes
    partidos_t=(c*(c-1))-partidos_t;
    cout<<best.first<<" "<<partidos_t<<endl;
  }
}

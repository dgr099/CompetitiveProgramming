#include <bits/stdc++.h>
using namespace std;

int main(){
  int p_i, c_b, aux, aux_1, i, j; //p_i puntos de interes, c_b carril bici
  set<int> ll; //un set con los puntos a los que puedes llegar desde tu casa
  //vector<pair<int, int>> v_no;
  ios_base::sync_with_stdio(false);
  while(scanf("%d %d", &p_i, &c_b)==2){
    ll.clear(); //limpias el set 
    /*for(i=0; i!=100; i++){ //limpiamos los vectores
      v[i].clear();
    }*/
    vector<int> v[100]; //100 vectores por los 100 puntos que puede haber
    for(i=0; i!=c_b; i++){
      //cin>>aux>>aux_1;
      scanf("%d %d", &aux, &aux_1);
      //(aux_1<aux ? v[aux_1-1].push_back(aux-1) : v[aux-1].push_back(aux_1-1)); //vas insertando los edges
      v[aux-1].push_back(aux_1-1);
      v[aux_1-1].push_back(aux-1);
    }
    //vamos a probar con algo similar a una busqueda en anchura de un arbol
    //en el set insertamos todos los edges
    ll.insert(0); //insertamos el 0 porque partimos de casa, a ese edge se puede llegar siempre porque es tu inicio
    queue<int> q;
    //en la queue vamos quitando y metiendo los ejes en los que podemos ir desde la posicion en la que estamos
    q.push(0);
    while(!q.empty()){ //mientras que no hemos hecho todos los caminos posibles
      aux=q.front();
      q.pop(); //extraemos el primer elementos
      aux_1=v[aux].size();
      for(i=0; i!=aux_1; i++){
        //si estaba sin visitar se añade al set de edges y se inserta en la pila para que se recorran todas sus uniones        
        if(ll.count(v[aux][i])!=0)  continue;
          ll.insert(v[aux][i]);
          q.push(v[aux][i]);
        //si ya esta en el set es que ya se ha visitado
      }
    }
    //recurs(&ll, &v[0]);
    if(ll.size()==p_i){ //si has visitado tantoss puntos de interes como el total es que puedes llegar a todos los sitios
      printf("BICI\n");
      continue;
    }
    printf("A PIE\n");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long p;
void g_add(pair<vector<int>, int> g[], int a, int b){
    g[a].first.push_back(b);
    g[b].first.push_back(a);
}

void b(pair<vector<int>, int> g[]){
    queue<int> q;
    bool vis[p];
    int l=0;
    memset(vis, false, sizeof(vis)); //todo a falso
    q.push(0); //pones la raiz
    int aux, aux_2, aux_3;
    while(!q.empty()){
        vector<int> hijos;
        while(!q.empty()){ //sacas todos los hijos del nuevo nivel
            hijos.push_back(q.front());
            q.pop();
        }
        while(!hijos.empty()){
            aux=hijos.back(); //lees el hijo
            g[aux].second=l; //pones su nivel
            hijos.pop_back(); //borras el hijo del vector
            aux_2=g[aux].first.size(); //nº de hijos
            for(aux_3=0; aux_3!=aux_2; aux_3++){
                if(!vis[g[aux].first[aux_3]]){ //si el hijo no se ha visitado va pal saco
                    q.push(g[aux].first[aux_3]); //lo metes a la lista de hijos de un nivel más
                    vis[g[aux].first[aux_3]]=true; //lo marcas como visitado
                }
            }
        }
        l++; //aumentas en uno el nivel
    }
    return;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);  cout.tie(NULL);
    long long cases;
    scanf("%lld\n", &cases);
    while(cases--){
        long long d;
        cin>>p>>d;
        /*long long graph[p][p]; grafo de conexiones*/
        pair<vector<int>, int> G[p]; /*sus v adyacentes y su peso*/
        /*Don Giovani es el 0*/
        while(d--){ /*leer las parejas*/
            long long aux1, aux2;
            cin>>aux1>>aux2;
            g_add(G, aux1, aux2); //añades los vértices al grafo
        }
        //al llegar aquí deberías tener el grafo
        b(G);
        //saltamos el 0
        for(d=1; d!=p; d++){
            printf("%d\n", G[d].second);
        }
        if(cases) //entre 2 casos hay que poner separador 
            printf("\n");
    }
    return 0;
}
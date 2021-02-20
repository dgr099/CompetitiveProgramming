#include "bits/stdc++.h"
using namespace std;
typedef struct Node Node;
struct Node
{
    long long valor;
    Node *left=NULL;
    Node *right=NULL;
};



void crearArbol_rec(Node *nodo)
{
    cin >> nodo->valor;
    if (nodo->valor == -1)
        return;
    //creamos el hijo izq
    if(!nodo->left){
        nodo->left = (Node *)calloc(1, sizeof(Node));
    }
    crearArbol_rec(nodo->left);
    //creamos el hijo derecho
    if(!nodo->right){
        nodo->right = (Node *)calloc(1, sizeof(Node));
    }
    crearArbol_rec(nodo->right);
    return;
}



void crearArbol(Node *arbol)
{
    cin >> arbol->valor;
    if (arbol->valor == -1)
        return;
    //creamos el izq
    if(!arbol->left){
        arbol->left = (Node *)calloc(1, sizeof(Node));
    }
    //leemos el izquierdo
    crearArbol_rec(arbol->left);
    //creamos el derecho
    if(!arbol->right){
        arbol->right = (Node *)calloc(1, sizeof(Node));
    }
    //leemos el derecho
    crearArbol_rec(arbol->right);
}



void sumaArbol_rec(Node *nodo_1, Node *nodo_2)
{
    //si ambos valen -1 pues por esa rama ya hemos finiquitado
    if (nodo_1->valor == nodo_2->valor && nodo_1->valor == -1)
    {
        cout << " -1";
        return;
    }

    if (nodo_1->valor == -1){ //si es el fin de 1, ya no puede tener ni izq ni derecha
        cout << ' ' << nodo_2->valor;
        sumaArbol_rec(nodo_1, nodo_2->left);
        sumaArbol_rec(nodo_1, nodo_2->right);
        return;
    }
        
    if (!nodo_2 || nodo_2->valor == -1){
        cout << ' ' << nodo_1->valor;
        sumaArbol_rec(nodo_1->left, nodo_2);
        sumaArbol_rec(nodo_1->right, nodo_2);
        return;        
    }
    else
        cout << ' ' << nodo_1->valor + nodo_2->valor;
        sumaArbol_rec(nodo_1->left, nodo_2->left);
        sumaArbol_rec(nodo_1->right, nodo_2->right);
        return;  

}



void sumaArbol(Node *arbol_1, Node *arbol_2)
{
    if(arbol_1->valor!=-1 && arbol_2->valor!=-1){
        cout << arbol_1->valor +arbol_2->valor;
        sumaArbol_rec(arbol_1->left, arbol_2->left);
        sumaArbol_rec(arbol_1->right, arbol_2->right);
        return;
    }
    if(arbol_1->valor==-1){
        cout << arbol_2->valor;
        sumaArbol_rec(arbol_1, arbol_2->left);
        sumaArbol_rec(arbol_1, arbol_2->right);
        return; 
    }
    else{
        cout << arbol_1->valor;
        sumaArbol_rec(arbol_1->left, arbol_2);
        sumaArbol_rec(arbol_1->right, arbol_2);
        return; 
    }
}



int main()
{
    Node arbol_1;
    Node arbol_2;
    while (true)
    {
        crearArbol(&arbol_1);
        crearArbol(&arbol_2);
        /*si estan vacios los arboles*/
        if (arbol_1.valor == arbol_2.valor && arbol_1.valor == -1)
            return 0;
        sumaArbol(&arbol_1, &arbol_2);
        cout << endl;
    }
    return 0;
}

//2 5 2 5 -> 4 + 10 <-> 14*3=42
/**Planteamineto logico
   * ---
   * --1
   * -12
   * 123
   * 23-
   * 3--
   * ---
   * Tienes que calcular todos los cambios
   * Al desplazarse de derecha a izquierda, siempre ocurre que el numero n sustituye al numero n-1
   * si te fijas en este caso, el 2 siempre sustituye al 1, el 1 siempre sustituye a la nada y asi.
   * ¿Cuántas veces el 1 sustituye a la nada? tantas como long del cartel, en este caso 3 veces
   * Que el uno sustituya a la nada implica 2 cambios
   * Que el 2 sustituya al 1 implica 5 cambios
   * Que el 3 sustituya al 2 implica 2 cambios
   * Que cualquier numero desaparezca no cuenta como cambio
   * En total sumando son 42  cambios
   * Cambios ida, vuelta (consideramos ida mientras sigan apareciendo numero y vuelta cuando por la izquierda aparece nada)
   * Lo que es lo mismo ida + vuelta -> ( (2) + (2+5) + (2+5+2) )+(Vuelta)) -> ( (2) + (2+5) + (2+5+2) ) + ( (2+5+5) + (2+5) + (5) )  -> (18) + (24)
 * planteamiento aritmetico:                           
 * cuentas el numero total de numeros
 * Ida=sumas el numero total por el cambio de nada al numero 1 + (numero total-1) por el cambio del numero 2 al numero 1 y asi hasta que el numero total sea 0 (recursividad)
 * Vuelta=cambio del numero ultimo a nada)*(n de vueltas) + (cambio del numero posterios a numero anterios) *(n de vueltas -1).... hasta que numero de vueltas sea 0
 * 
 * 
 * 
 * */
#include <iostream>
#include <vector>
using namespace std;
//para no repetir cálculos vamos a utilizar programación dinámica
void calcula_pasos(int **matriz_cambios, int origen, int destino){
  int fa[11][7]={ //aqui guardo los filos activos para cada numero empezando por el 0
  {1, 1, 1, 1, 1, 0, 1}, //el 0 que son todos activados menos el del medio
  {0, 0, 0, 1, 1, 0, 0}, //el 1 solo activados el 4 y 5
  {0, 1, 1, 0, 1, 1, 1}, // el 2 el 2, 3, 5, 6
  {0, 0, 1, 1, 1, 1, 1}, //el 3 todos menos el 1 y 2
  {1, 0, 0, 1, 1, 1, 0}, //el 4
  {1, 0, 1, 1, 0, 1, 1}, //el 5 todos menos el 2 y 5
  {1, 1, 1, 1, 0, 1, 1}, //el 6 todos menos el 5
  {0, 0, 0, 1, 1, 0, 1}, //el 7 como el 1 usando el 7
  {1, 1, 1, 1, 1, 1, 1}, //el 8 todos activados
  {1, 0, 1, 1, 1, 1, 1}, //el 9 todos menos el 2
  {0, 0, 0, 0, 0, 0, 0}, //la nada
  };
  /*   __       7
      |  |  1       5
      |  |      
      |__|      6
      |  | 
      |__|  2       4
                3
  
  */
 int cont=0;
 for(int i=0; i!=7; i++){
   if(fa[origen][i]!=fa[destino][i])
    cont++; //voy contando las diferencias entre ambos números
 } 
 matriz_cambios[origen][destino]=matriz_cambios[destino][origen]=cont; //el cambio de pasar de 1 a 2 es lo mismo que de 2 a 1
 return;
}

int numero_pasos_ida(vector<int> vi, int ida, int index, int **matriz_cambios){
  if(ida==0){ //condicion de parada de la recursividad
    return 0;
  }
  if(matriz_cambios[vi[index-1]][vi[index]]==0){
    /* si no tengo ese cambio llamo a una funcion para que me lo calcule*/
    calcula_pasos(matriz_cambios, vi[index-1], vi[index]);
  }
  return (matriz_cambios[vi[index]][vi[index-1]]*ida + numero_pasos_ida(vi, --ida, ++index, matriz_cambios));
}

int numero_pasos_vuelta(vector<int> vi, int ida, int index, int**matriz_cambios){
  if(ida==0){
    return 0;
  }
  if(matriz_cambios[vi[index]][vi[index+1]]==0){
    calcula_pasos(matriz_cambios, vi[index], vi[index+1]);
  }
  return (matriz_cambios[vi[index]][vi[index+1]]*ida + numero_pasos_vuelta(vi, --ida, --index, matriz_cambios));
}

int main(){
  int **cambios; 
  vector<int> numeros; //utilizo un vector porque desconozco el ancho max
  int aux; //utilizo un int porque los numeros son de 0 a 9 no me preocupa un overflow
  int ida; //aquí empleo un int porque desconozco el ancho entonces pueden liarmela y producir overflow
  int ct; //cambios totales
  //formateo los cambios (me quito valores residuales)
  cambios=(int**)calloc(11, sizeof(int*));//utilizamos 11 porque son los numeros entre 0 y 9 más el caso nada (que será el 10), voy a guardar cambios entre origen y destino
  for(ct=0; ct!=11; ct++)
    cambios[ct]=(int*)calloc(11, sizeof(int));
  
  while(cin>>aux && !(aux==-1)){
    numeros.clear(); //limpiamos el vector para evitar valores residuales
    ct=0; //reinicio el contador de cambios
    //Esto lo puedo omitir creo pero me viene bien 
    numeros.push_back(10); //el 10 representa la nada que será a lo que sustituira el primer número que se introduzca
    numeros.push_back(aux); //añadimos el leido
    ida=1; //reiniciamos los valores de ida
    while(cin>>aux && !(aux==-1)){
      numeros.push_back(aux); //vamos insertando los números leidos
      ida++; //sumamos 1 a la ida (la ida cuenta la longitud del cartel)
    }
    numeros.push_back(10); //inserto el 10 que representa la nada al final que irá sustituyendo al último número
    //una vez terminemos es hora de calcular los pasos, para ello, voy a emplear programación dinámica y recursividad
    ct+=numero_pasos_ida(numeros, ida, 1, cambios);
    ct+=numero_pasos_vuelta(numeros, ida, ida, cambios);
    /*if(cambios[0][numeros[0]]==0){ 
      //si no esta calculado los pasos de nada al numero los calculo
    }*/
    cout<<ct<<endl;
  }
  //creo que se puede omitir liberar memoria pero por si las moscas yo lo pongo :-)
  for(ct=0; ct!=11; ct++)
    free(cambios[ct]);
  free(cambios);
  return 0;
}

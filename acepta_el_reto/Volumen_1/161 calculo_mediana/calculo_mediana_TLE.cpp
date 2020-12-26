#include <bits/stdc++.h>
using namespace std;
typedef struct _SET{
  int *num_ini=NULL;
  int *cant=NULL;
  struct _SET *next=NULL;
}Setito;
void Insert(Setito *setito,int num){
  if(!setito->next){ //si no tienes next hay dos casos posibles, o solo hay un elemento o estas al final
    setito->next=(Setito*)calloc(1, sizeof(Setito));
    setito->next->num_ini=(int*)calloc(1, sizeof(int));
    if((*setito->num_ini)>num){
      (*setito->next->num_ini)=*(setito->num_ini);
      (*setito->num_ini)=num;
    } else  (*setito->next->num_ini)=num;
    return;
  }
  if(*(setito->num_ini)>num){ //si el dato es menor que el 1º se hace esto :-)
    Setito *ne;
    ne=(Setito*)calloc(1, sizeof(Setito));  (ne)->num_ini=(int*)calloc(1, sizeof(int));  *(ne->num_ini)=num;
    *ne->num_ini=(*setito->num_ini); 
    *(setito->num_ini)=num;
    ne->next=setito->next; 
    setito->next=ne;
    return;
  }
  if(*(setito->next->num_ini)>num){ //si hay 3-4-5 queres insertar el 4  3-4-4-5  o si estas 3-5 y quieres insertas el 4
    Setito *ne; ne=(Setito*)calloc(1, sizeof(Setito));  
    (ne)->num_ini=(int*)calloc(1, sizeof(int));  *(ne->num_ini)=num;
    ne->next=setito->next; setito->next=ne;
    return;
  }
  return Insert(setito->next, num); //te vas desplazando en la array
}


/*int calculo_mediana(set<long> &valores){
  auto p = valores.begin();
  int num=valores.size();
  if(num%2!=0){ //si es impar 
    num=(num/2.0); //si son 11; 11/2=5.5 redondeo para arriba, 6; 5 de un lado, 5 de otro y en el 6 la mediana, por ejemplo 13, 13/2=6.5 redondeo para arriba 7, 6 de un lado, 6 del otro y en la mitad (el 7) la mediana 
    while(num--){
      p++;
    }
    return (*p)*2;
  }
  num=(num/2); //si son 12; 12/2=6; 5 de un lado, el 6 y el septimo y 5 del otro
  while(num--){
    p++;
  }
  return ((*p) + (*(--p)));
}*/

int calculo_mediana(Setito &setito){
  Setito *seti=&setito;
  if(*(setito.cant)%2!=0){ //si es impar 
    (*setito.cant)/=2.0; //si son 11; 11/2=5.5 redondeo para arriba, 6; 5 de un lado, 5 de otro y en el 6 la mediana, por ejemplo 13, 13/2=6.5 redondeo para arriba 7, 6 de un lado, 6 del otro y en la mitad (el 7) la mediana 
    while((*setito.cant)--){
      seti=seti->next;
    }
    return (*(seti->num_ini))*2;
  }
  (*setito.cant)/=2.0; //si son 12; 12/2=6; 5 de un lado, el 6 y el septimo y 5 del otro
  (*setito.cant)--;
  while((*setito.cant)--){
    seti=seti->next;
  }
  return ((*seti->num_ini))+(*seti->next->num_ini);
}

void Delete(Setito *setito){
  if(!setito->next){
    free(setito->num_ini);
    free(setito);
    return;
  }
  return Delete(setito->next);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  cout.tie(NULL);
  int num;
  while(scanf("%d", &num) && num){
    //set<long> valores; //uso un set porque se ordenan de menor a mayor
    Setito *first=NULL;  first=(Setito*)calloc(1, sizeof(Setito)); 
    (*first).cant=(int*)calloc(1, sizeof(int));  *((*first).cant)=num;
    first->num_ini=(int*)calloc(1, sizeof(int));
    int aux;  scanf("%d", &aux);
    (*first->num_ini)=aux;  num--;
    while(num--){
      scanf("%d", &aux);
      Insert(first, aux);
      //valores.insert(aux);
    }
    printf("%d\n", calculo_mediana(*first));
    free(first->cant);
    Delete(first);
  }
  return 0;
}
#include <iostream>
using namespace std;
#define MAX_MIN 'A'-'a'
#define VOCAB 'Z'-'A'

int contar_voc(string frase){
  int i, n=frase.length(), cont;
  for(i=cont=0; i!=n; i++){
    if(frase[i]=='a' || frase[i]=='a'+ MAX_MIN || frase[i]=='e' || frase[i]=='e'+MAX_MIN || frase[i]=='i' || frase[i]=='i'+MAX_MIN|| frase[i]=='o' || frase[i]=='o'+MAX_MIN|| frase[i]=='u' || frase[i]=='u'+MAX_MIN)
      cont++;
  }
  cout<<cont<<endl;
}

string des(string frase){
  int cod, n, i;
  char aux1, aux2;
  if(frase[0]=='p'){
    return frase;
  }
  cod='p'- frase[0];
    for(i=0, n=frase.length(); i!=n; i++){
      aux1=frase[i];
      if(frase[i]<='Z' && frase[i]>='A'){
        aux2=(frase[i]-'A'+cod)%(VOCAB+1)+'A';
        if(aux2<'A'){
          aux2='Z'-('A'-aux2)+1;
        }
        frase[i]=aux2;
      }
      else if(frase[i]<='z' && frase[i]>='a'){
        aux2=(frase[i]-'a'+cod)%(VOCAB+1)+'a';
        if(aux2<'a'){
          aux2='z'-('a'-aux2)+1;
        }
        frase[i]=aux2;
      }
    }
    return frase;    
}

int main(){
  string frase_original, frase_des;
  while(getline(cin, frase_original)){
    frase_des=des(frase_original);
    if(frase_des.compare("pFIN")==0){
      return 0;
    }    
    contar_voc(frase_des);
  }
  return 0;
}
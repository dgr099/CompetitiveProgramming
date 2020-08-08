twitter/insta: @dgr_099 ;-)
#include <iostream>
using namespace std;
  
void conf_electronica(long long *z, int *nivel, int *pos){
  char  subniveles[]={'s', 'p', 'd', 'f'};
  int atom[]={2, 6, 10, 14};
    if(*pos==-1){
      switch (*nivel)
      {
      case 2:
        *pos=0;
        *nivel=2;
        break;
      case 3:
        *pos=1;
        *nivel=2;
        break;
      case 4:
        *nivel=3;
        *pos=1;
        break;
      case 5:
        *nivel=3;
        *pos=2;
        break;
      case 6:
        *nivel=4;
        *pos=2;
        break;
      case 7:
        *nivel=4;
        *pos=3;
        break;
      case 8:
        *nivel=5;
        *pos=3;
        break;
    }
    }
    if((*pos==0 && *nivel==8) || *z<=0){
      return;
    }
    if(*nivel!=1){
      cout<<" ";
    }
    cout<<*nivel<<subniveles[*pos]<<(*z>=atom[*pos] ? atom[*pos] : *z);
    (*z)-=atom[*pos];
    (*nivel)++;
    (*pos)--;
    conf_electronica(z, nivel, pos);
  }



int main(){
  string elemento;
  long long z;
  int nivel=0, pos=0;

  while(cin>>elemento && elemento.compare("Exit")){
    cin>>z;
    nivel=1;
    pos=0;
    if(z==0){
      cout<<"1s0"<<endl;
      continue;
    }
    conf_electronica(&z, &nivel, &pos);
    //cout<<'\b';
    cout<<endl;
  }
  return 0;
}

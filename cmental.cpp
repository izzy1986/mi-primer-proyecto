#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.c> // incluimos esta librería para poder utilizar los colores//
using namespace std;
const int tmax=10;
typedef char TCadena[20];
struct TJugador{
       TCadena nombre;
       int puntos;
       bool metido;
       };
typedef TJugador TListaJ[30];
struct TJugadores{
       TListaJ lista;
       int n_jug;
       };


void Actualizar_Record(TJugador &jug,TJugadores &lista); 
//Actualiza los records cada vez que se ejecuta la opcion 3 del menú//

int aleat(const int inf, int sup); //genera un numero aleatorio entre dos valores//

int Buscar_Jug(TJugador &jug,TJugadores &lista);/*Busca si hay un jugador
con el mismo nombre del actual, para no repetirlo */

void Dificultad(int &dif);/*visualiza el menu de dificultad y guarda la 
selección en una variable */

void Jugar(TJugador &jug , TJugadores &lista, int dif); /* es el juego en sí,
este subprograma saca por pantalla las operaciones y comprueba si están bien
o mal */

void Menu(TJugadores &lista); /*saca por pantalla el menú principal y utiliza 
el programa que ejecuta las distintas opciones */

void NuevoJug(TJugador &jug); //Crea un nuevo jugador//

void Opcion( int seleccion,TJugadores &lista,TJugador &jug,int &dif);
/* Según la selección del usuario, este procedimiento llama a los distintos
subprogramas que rigen los distintos apartados del juego*/

void Ordenar_Lista(TJugadores &lista); /* Subprograma encargado de ordenar por 
puntos la estructura de datos en la que se guardan los jugadores y sus puntos*/

void Record(TJugadores &lista); /*Saca por pantalla y ordenados por puntos
la lista de jugadores con un formato adecuado*/



void Actualizar_Record(TJugador &jug,TJugadores &lista){
  int i;
  i=Buscar_Jug(jug,lista);
  if((i!=-1)&&(lista.lista[i].puntos<jug.puntos)){
    lista.lista[i]=jug;
  }else if((lista.n_jug<30)&&(i==-1)){
    lista.lista[lista.n_jug]=jug;
    lista.n_jug++;
  }else if((lista.n_jug==30)&&(i==-1)){
    if(lista.lista[lista.n_jug-1].puntos<jug.puntos){
      lista.lista[lista.n_jug-1]=jug;
    }
    
  }
  Ordenar_Lista(lista);
}

       
int Buscar_Jug(TJugador &jug,TJugadores &lista){
  int i;
  for (i=0;i<lista.n_jug;i++){
  if (int(strcmp(lista.lista[i].nombre,jug.nombre))==0){
    return i;
  }
  }
  return -1; //Este -1 indica que no lo ha encontrado// 
  }
  

int aleat(const int inf, int sup){
  return(rand()%(sup-inf+1)+inf);
}
       


void Dificultad(int &dif){

  system("CLS");
  
  textcolor(LIGHTGREEN);
  cout<<"Nivel de dificultad"<< endl;
  cout<<"--------------------"<<endl;
  textcolor(WHITE);
  cout<<"Pulse 1 para menor dificultad y 5 para dificultad maxima"<< endl;
  do{
    cout<<"Seleccion[1..5]:";
    cin>>dif;
  }while((dif<1)||(dif>5));
}

void Jugar(TJugador &jug , TJugadores &lista, int dif){
  int nmin, nmax, nop,i,signo,num,suma,intro;
  float tiempo;
  time_t ti,tf;
    
  nop=2;
  nmin=1;
  nmax=dif+4;
  jug.puntos=0;
  do{
    system("CLS");
    suma=0;
    textcolor(LIGHTGREEN);
    cout<<jug.nombre<<"          PUNTOS: "<<jug.puntos<<endl<<endl;
    cout<<"--------------------------------"<<endl;
    textcolor(WHITE);
    for(i=1;i<=nop;i++){
      signo=aleat(1,2);
      num=aleat(nmin,nmax);
      if(i==1){
        if(signo==2){
          cout<<'-';
          suma=suma - num;
        }else{
          suma=suma + num;
        }
        cout<<num;
      }else{
        if(signo==1){
          cout<<" + ";
          suma=suma+num;
        }else{
          cout<<" - ";  
          suma=suma-num;        
        }
        cout<<num;
      }
    }
    cout<<endl;
    ti=time(NULL);
    cin>>intro;
    tf=time(NULL);
    tiempo=difftime(tf,ti);
    if((intro==suma)&&(tiempo<=tmax)){
      textcolor(LIGHTGREEN);
      cout<<endl;
      cout<<"CORReCTo"<<endl<<endl;
      textcolor(WHITE);
      jug.puntos=jug.puntos+dif+nop-1+10-int(tiempo);
      nop++;
      
    
    }else if(intro!=suma){
      textcolor(LIGHTGREEN);
      cout<<endl;
      cout<<"iNCoRReCTo;";
      cout<<"ReSuLTaDo CoRReCTo: "<<suma<<endl<<endl;
      textcolor(WHITE);
    }else{
      textcolor(LIGHTGREEN);
      cout<<endl;
      cout<<"DeMaSiaDo LeNTo"<<endl<<endl;
      textcolor(WHITE);
    }
    system("PAUSE");
  }while((intro==suma)&&(tiempo<=tmax));
  Actualizar_Record(jug,lista);
  
}

void Menu(TJugadores &lista)
{ 
  int dif;
  dif=1;
  TJugador jug;
  jug.metido=false;
  int seleccion;
  do{
    system("CLS");
    cout << endl <<endl;
    textcolor(LIGHTGREEN);
    cout << endl << endl <<"                  ";
    cout << "JueGo De CaLCuLo MeNTaL"<< endl;
    textcolor(WHITE);
    cout << "                ___________________________ "<< endl;
    cout << "               | 1. Nuevo Jugador          |"<< endl;
    cout << "               | 2. Seleccionar dificultad |"<< endl;
    cout << "               | 3. Lista de Records       |"<< endl;
    cout << "               | 4. Comenzar Partida       |"<< endl;
    cout << "               | 0. Salir                  |"<< endl;
    cout << "               | Elija opcion [0-4]        |"<< endl;
    cout << "               |___________________________|"<< endl;
    textcolor(LIGHTGREEN);
    cout << "                                    by KASH "<< endl;
    textcolor(WHITE);
    cout << endl;
    cin >> seleccion;
    if (seleccion <= 4) {
      Opcion(seleccion,lista,jug,dif);
    }
  }while(seleccion!=0)  ;
} 

void NuevoJug(TJugador &jug){
  system("cls");
  textcolor(LIGHTGREEN);
  cout << "Introduzca su nombre:" << endl;
  textcolor(WHITE);
  cin.ignore();
  cin.getline(jug.nombre,20);
  jug.metido=true;

}

void Opcion( int seleccion,TJugadores &lista,TJugador &jug,int &dif)
{
 
switch (seleccion) {
case 0: 
        break;
case 1: NuevoJug(jug);
        break;
case 2: Dificultad(dif);
        break; 
case 3: Record(lista);
        break;
case 4:
        if(jug.metido){
          Jugar(jug,lista,dif);
        }else{
          system("CLS");
          textcolor(LIGHTGREEN);
          cout<<"Crea antes un jugador."<<endl<<endl;
          textcolor(WHITE);          
          system("PAUSE");          
        }
        break;
                }
}

void Ordenar_Lista(TJugadores &lista){
  TJugador apoyo,apoyo2;
  int i,j;
  apoyo=lista.lista[lista.n_jug-1];
  i=0;
  while(lista.lista[i].puntos>apoyo.puntos){
    i++;
  }
  if(i!=lista.n_jug-1){
    apoyo2=lista.lista[i];
    lista.lista[i]=apoyo;
    for(j=lista.n_jug-1;j>i+1;j--){
      lista.lista[j]=lista.lista[j-1];
    }
    lista.lista[i+1]=apoyo2;
  }
   
} 

void Record(TJugadores &lista){
  int i;
  system("cls");
  textcolor(LIGHTGREEN);
  cout<<"NOMBRE                        PUNTOS"<<endl;
  cout<<"    ------------------              "<<endl;
  textcolor(WHITE);
  for(i=0;i<=lista.n_jug-1;i++){
    
    cout<<lista.lista[i].nombre<<"     ";
    cout<<lista.lista[i].puntos<<endl;
  }
  textcolor(LIGHTGREEN);
  cout<<"    ------------------              "<<endl<<endl;
  textcolor(WHITE);
  system("PAUSE");
}   
  

int main(){
  TJugadores tabla;
  srand(time(0));
  tabla.n_jug=0;
  textcolor(WHITE);
  Menu(tabla);
  
system("PAUSE");	
  return 0;
}

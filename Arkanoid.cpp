#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "teleco.hpp"


using namespace std;
const int FIL=5, COL=60 ,ladrillo=254, TAMPALA=6, VIDAS=3;
const int IZQ=30, DRCH=50, ARRIBA=7, ABAJO=9, MAXLISTA=10;

typedef bool TMatriz[FIL][COL];

typedef char TCadena[10];

struct TMuro {
       TMatriz matriz;
       int nladrillos;
       };

struct TBola {
       int x,y;
       int vx,vy;
       };

struct TPala {
       int x,y;
       };

struct TTablero {
       int x0,y0;
       int x1,y1;
       };
       
struct TRecord{
       TCadena nombre;
       int puntos;
       bool metido;
       };
typedef TRecord TListaJ[MAXLISTA];

struct TJugadores{
       TListaJ lista;
       int n_jug;
       };
       
struct TFronton {
       TMuro muro;
       TBola bola;
       TPala pala;
       TTablero tablero;
       int delaybola;
       int vidas;
       int puntos;
       };

void ActualizaMuro(TFronton &todo);
void ActualizarRecord(TRecord &jugador,TJugadores &lista);
void CalcularV(TFronton &todo);
void DibujarBola(const TFronton todo);
void DibujarBordes(const TFronton todo);
void DibujarCuadro(const int izq,int drch,int arriba,int abajo);
void DibujarGameOver(const TFronton todo);
void DibujarGanador(const TFronton todo);
void DibujarMuro(const TFronton todo);
void DibujarPala(const TFronton todo);
void DibujarTitulo();
void InicializarDatos(TFronton & todo);
void InicializarMuro(TFronton & todo);
void InicializarRecord(TJugadores &lista);
void Jugar(TFronton &todo, TJugadores &lista, TRecord &jugador);
void Menu(TFronton &todo,TJugadores &lista, TRecord &jugador);
void MeterRecord(const TFronton todo,TRecord &jugador);
void MoverBola(TFronton &todo);
void MoverDerecha(TFronton &todo);
void MoverIzquierda(TFronton &todo);
void Opcion(const int seleccion,TFronton &todo,TJugadores &lista, TRecord &jugador);
void Ordenar_Lista(TJugadores &lista);
void Records(TJugadores &lista);
void RepintarBola(TFronton &todo);
void Velocidad(TFronton &todo);


       
void ActualizaMuro(TFronton &todo){
  if ((todo.bola.y<FIL+todo.tablero.y0+1) && (todo.muro.matriz[todo.bola.y-todo.tablero.y0-1][todo.bola.x-todo.tablero.x0-1])){
    todo.muro.matriz[todo.bola.y-todo.tablero.y0-1][todo.bola.x-todo.tablero.x0-1]=false;
    todo.muro.nladrillos++;
    todo.puntos=todo.puntos+(10-todo.bola.y);
  }
  
}

void ActualizarRecord(TRecord &jugador,TJugadores &lista){

  if(lista.n_jug<MAXLISTA){
    lista.lista[lista.n_jug]=jugador;
    lista.n_jug++;
  }else if(lista.n_jug==MAXLISTA){
    if(lista.lista[lista.n_jug-1].puntos<jugador.puntos){
      lista.lista[lista.n_jug-1]=jugador;
    }
    
  }
  Ordenar_Lista(lista);
}


void CalcularV(TFronton &todo){
    
   if((todo.bola.x==todo.tablero.x0+1) && (todo.bola.vx==-1)) {
    todo.bola.vx=1;
   }if((todo.bola.x==todo.tablero.x1-1) && (todo.bola.vx==1)){
    todo.bola.vx=-1;
   } 
   if(((todo.bola.y==todo.tablero.y0+1) && (todo.bola.vy==-1)) 
      || ((todo.bola.y<FIL+todo.tablero.y0+1) && (todo.muro.matriz[todo.bola.y-todo.tablero.y0-1][todo.bola.x-todo.tablero.x0-1]))){
         todo.bola.vy=-todo.bola.vy;
   }
   if((todo.bola.y==todo.pala.y-1)&&(todo.bola.x+todo.bola.vx>=todo.pala.x)&&(todo.bola.x+todo.bola.vx<=todo.pala.x+TAMPALA-1)){
     todo.bola.vy=-todo.bola.vy;
     if(todo.bola.x+todo.bola.vx<=todo.pala.x+(TAMPALA/3)-1){
       
       todo.bola.vx=-1;
     }else if(todo.bola.x+todo.bola.vx<=todo.pala.x+(TAMPALA/3)*2-1){  

       todo.bola.vx=0;
     }else{

       todo.bola.vx=1;
     }    
   }
   if((todo.bola.x==todo.tablero.x0+1) && (todo.bola.vx==-1)) {
    todo.bola.vx=1;
   }if((todo.bola.x==todo.tablero.x1-1) && (todo.bola.vx==1)){
    todo.bola.vx=-1;
   }

}


void DibujarBola(const TFronton todo) {
   textcolor(LIGHTRED);
   gotoxy(todo.bola.x,todo.bola.y);
   cout << "O" ;
   }
   
   
void DibujarBordes(const TFronton todo){ 
//dimensiones del tablero: x0,y0=(10,3) x1,y1=(70,20)
   int i,j;
   
   textcolor(WHITE);
   gotoxy(todo.tablero.x0,todo.tablero.y0);
   cout << char(218);
   gotoxy(todo.tablero.x1,todo.tablero.y0);
   cout << char(191);
   
   for(i=todo.tablero.x0+1;i<=todo.tablero.x1-1;i++){
       gotoxy(i,todo.tablero.y0);
       cout << char(196) ;
       }
   for(j=todo.tablero.y0+1;j<=todo.tablero.y1;j++){
       gotoxy(todo.tablero.x0,j);
       cout << char(179);
       }
   for(j=todo.tablero.y0+1;j<=todo.tablero.y1;j++){
       gotoxy(todo.tablero.x1,j);
       cout << char(179);
       }
   cout << endl;
    } 


void DibujarCuadro(const int izq,int drch,int arriba,int abajo){
int i,j;   
   //IZQ=30;DRCH=50;ARRIBA=7;ABAJO=9;
   textcolor(WHITE);
   gotoxy(izq,arriba);
   cout << char(218);
   gotoxy(drch,arriba);
   cout << char(191);
   gotoxy(izq,abajo);
   cout << char(192);
   gotoxy(drch,abajo);
   cout << char(217);
   
   
   for(i=izq+1;i<drch;i++){
       gotoxy(i,arriba);
       cout << char(196) ;
       }
   for(i=izq+1;i<drch;i++){
       gotoxy(i,abajo);
       cout << char(196);
       }
   for(j=arriba+1;j<abajo;j++){
       gotoxy(izq,j);
       cout << char(179);
       }
   for(j=arriba+1;j<abajo;j++){
       gotoxy(drch,j);
       cout << char(179);
       }
}

void DibujarGameOver(const TFronton todo){
   DibujarBordes(todo);
   DibujarPala(todo);
   DibujarCuadro(IZQ,DRCH,ARRIBA,ABAJO);
   gotoxy(IZQ+6,ARRIBA+1);
   textcolor(LIGHTRED);
   cout <<"GAMEOVER";
   gotoxy(20,1);
   textcolor(WHITE);
   system("PAUSE");
   system("CLS");
}

void DibujarGanador(const TFronton todo){
   DibujarBordes(todo);
   DibujarPala(todo);
   DibujarCuadro(IZQ,DRCH,ARRIBA,ABAJO);
   gotoxy(IZQ+3,ARRIBA+1);
   textcolor(LIGHTRED);
   cout <<"LO CONSEGUISTE!!";
   gotoxy(20,1);
   textcolor(WHITE);
   system("PAUSE");  
   system("CLS");
}

    
void DibujarMuro(const TFronton todo) {
int i,j;
    textcolor(LIGHTMAGENTA);
    for(i=0;i<FIL;i++){
       for(j=0;j<COL;j++){
          switch(i%5){
            case 0:
              textcolor(LIGHTGREEN);
              break;
            case 1:
              textcolor(LIGHTBLUE);
              break;
            case 2:
              textcolor(CYAN);
              break;
            case 3:
              textcolor(YELLOW);
              break;
            case 4:
              textcolor(LIGHTCYAN);
              break;  
          }
          if (todo.muro.matriz[i][j]==true){
            gotoxy(todo.tablero.x0+(j+1),todo.tablero.y0+(i+1));
            cout << char(ladrillo);
            }else{
            gotoxy(todo.tablero.x0+(j+1),todo.tablero.y0+(i+1));
            cout << " ";
          }
        }
    }
}
    
void DibujarPala(const TFronton todo) {
int i;
   textcolor(WHITE);
   gotoxy(todo.pala.x,todo.pala.y);
   for(i=todo.pala.x;i<todo.pala.x+TAMPALA;i++){
       cout << char(220);
    }
}

void DibujarTitulo(){
   DibujarCuadro(IZQ-3,DRCH-3,ARRIBA+1,ABAJO+1);
   gotoxy(IZQ+4,ARRIBA+2);
   textcolor(LIGHTRED);
   cout <<"ARKANOID";
   textcolor(WHITE);
   gotoxy(IZQ-6,ABAJO+2);
   cout << "Por Carlos Alberto Hernandez";
   gotoxy(19,25);
   system("PAUSE");
   system("CLS");
}

void InicializarDatos(TFronton & todo) {

   todo.tablero.x0=10;
   todo.tablero.y0=3; 
   todo.tablero.x1=71; 
   todo.tablero.y1=20;

   todo.pala.x=20;
   todo.pala.y=20;

   todo.bola.x=22;
   todo.bola.y=11;
   todo.bola.vx=0;
   todo.bola.vy=1;
   
   
}


void InicializarRecord(TJugadores &lista){
int i;

lista.n_jug=0;
for(i=0;i<MAXLISTA;i++){
   lista.lista[i].metido=false;
   lista.lista[i].puntos=0;
   }

}


void InicializarMuro(TFronton & todo){
int i,j;
   for(i=0;i<FIL;i++){
      for(j=0;j<COL;j++){
      todo.muro.matriz[i][j]=true;
      }
   }
   todo.muro.nladrillos=0;
}

  
   
    
void Jugar(TFronton &todo, TJugadores &lista, TRecord &jugador) { 
  InicializarMuro(todo);
  todo.puntos=0;
  todo.vidas=VIDAS;
  int tecla,num;
  num=1;
system("CLS");
do{  
    InicializarDatos(todo);
    DibujarBordes(todo);
    DibujarPala(todo);
    DibujarBola(todo);
    DibujarMuro(todo);

  do{
    textcolor(WHITE);
    delay(1);
    if(num>todo.delaybola) {
      num=1;
    }else{  
    
      num++;
    }  

    if(kbhit()){
      tecla = getkey();
   
        if (tecla==KEY_LEFT) {
          MoverIzquierda(todo);
  
  
       }else if (tecla==KEY_RIGHT){
          MoverDerecha(todo);
       }
    }

    if(num%todo.delaybola==0){  
      MoverBola(todo);
    }  
  
  textcolor(WHITE);
  gotoxy(1,24);
  cout<< "Ladrillos restantes:" << (FIL*COL)-(todo.muro.nladrillos);
  gotoxy(35,24);
  cout<< "Vidas restantes:" <<todo.vidas;
  gotoxy(65,24);
  cout<< "Puntos:" <<todo.puntos;
  }while((todo.bola.y<todo.pala.y)&&(todo.muro.nladrillos<FIL*COL));
  todo.vidas--;
  gotoxy(20,1);
  system("PAUSE");  
  system("CLS");
}while((todo.vidas>-1)&&(todo.muro.nladrillos<FIL*COL));  
   
   if(todo.vidas=-1){
      DibujarGameOver(todo);
   }else {
      DibujarGanador(todo);
   }
   
   Ordenar_Lista(lista);
  // if(lista.lista[lista.n_jug-1].puntos<todo.puntos){
      MeterRecord(todo,jugador);
      ActualizarRecord(jugador,lista);
    //  }
   
   
  
  }

void Menu(TFronton & todo,TJugadores &lista, TRecord &jugador){
int seleccion;   
   
   do{
      DibujarCuadro(25,50,5,14);
      gotoxy(34,6);
      textcolor(LIGHTRED);
      cout<<"ARKANOID";
      textcolor(WHITE);
      gotoxy(26,8);
      cout << "1. Comenzar Partida";
      gotoxy(26,9);
      cout << "2. Velocidad";
      gotoxy(26,10);
      cout << "3. Lista de Records";
      gotoxy(26,11);
      cout << "0. Salir";
      gotoxy(29,13);
      textcolor(LIGHTRED);
      cout << "Elija opcion [0-3]";   

     do{
      textcolor(WHITE);
      cin >> seleccion;
          if (seleccion <= 3) {
           Opcion(seleccion,todo,lista,jugador);
          }
        }while((seleccion<0) || (seleccion>4))  ;
   }while(seleccion!=0);
}


void MeterRecord(const TFronton todo,TRecord &jugador){
  jugador.puntos=todo.puntos;
  jugador.metido=true;
  DibujarCuadro(14,61,9,11);
  gotoxy(15,10);
  textcolor(LIGHTRED);
  cout << "INTRODUZCA SU NOMBRE (max.10 char): ";
  textcolor(WHITE);
  cin.ignore();
  cin.getline(jugador.nombre,10);
  system("CLS");
}
 
 
void MoverBola(TFronton &todo){
  
   textcolor(LIGHTRED);
   RepintarBola(todo);
   CalcularV(todo);
   ActualizaMuro(todo);
}


void MoverDerecha(TFronton &todo){
  
   if (todo.pala.x+TAMPALA<todo.tablero.x1) {
      gotoxy (todo.pala.x,todo.pala.y);
      cout << " ";
      todo.pala.x=todo.pala.x+1;
      gotoxy (todo.pala.x+TAMPALA-1,todo.pala.y);
      cout << char(220);;
   }
}


void MoverIzquierda(TFronton &todo){
  
   if (todo.pala.x>todo.tablero.x0+1) {
      gotoxy (todo.pala.x+TAMPALA-1,todo.pala.y);
      cout << " ";
      todo.pala.x=todo.pala.x-1;
      gotoxy (todo.pala.x,todo.pala.y);
      cout << char(220);
   }
}

void Opcion(const int seleccion,TFronton &todo,TJugadores &lista, TRecord &jugador)
{
 
switch (seleccion) {
case 0: 
        break;
case 1: Jugar(todo,lista,jugador);
        break;
case 2: Velocidad(todo);
        break; 
case 3: Records(lista);
        break;
       
        }
}


void Ordenar_Lista(TJugadores &lista){
  TRecord apoyo,apoyo2;
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
void Records(TJugadores &lista){
   int i;
   textcolor(LIGHTRED);
   system("CLS");
   gotoxy(22,4);
   cout << "NOMBRE";
   gotoxy(38,4);
   cout << "PUNTOS";
   textcolor(WHITE);
   for(i=0;i<MAXLISTA;i++){
      if(lista.lista[i].metido==true){
          gotoxy(22,6+i);
          cout << lista.lista[i].nombre;
          gotoxy(38,6+i);
          cout << lista.lista[i].puntos;
          }
   }
   gotoxy(20,25);
   textcolor(WHITE);
   system("PAUSE");
   system("CLS");  
}



void RepintarBola(TFronton &todo){
   textcolor(LIGHTRED);
   gotoxy(todo.bola.x,todo.bola.y);
   cout << ' ';
   todo.bola.x=todo.bola.x+todo.bola.vx;
   todo.bola.y=todo.bola.y+todo.bola.vy;
   gotoxy(todo.bola.x,todo.bola.y);
   cout << 'O';
   }

void Velocidad(TFronton &todo){
  int seleccion;
   
   system("CLS");
   DibujarCuadro(IZQ-9,DRCH+8,ARRIBA,ABAJO+1);
   gotoxy(IZQ-8,ARRIBA+1);
   textcolor(LIGHTRED);
   cout <<"Introduzca velocidad de la bola(1-4)";
   gotoxy(IZQ-8,ARRIBA+2);
   do {
      textcolor(WHITE);
      cin >> seleccion;
   }while ((seleccion<0) || (seleccion>5));
   switch (seleccion){
      case 1: todo.delaybola=10;
      break;
      case 2: todo.delaybola=8;
      break;
      case 3: todo.delaybola=6;
      break;
      case 4: todo.delaybola=4;
      break;
   }
   system("CLS");
   }
   
   
int main(int argc, char *argv[])
{
  DibujarTitulo();
  TFronton fronton; 
  TJugadores lista;
  TRecord jugador;
  fronton.delaybola=8;
  InicializarRecord(lista);
  InicializarMuro(fronton);
   
  Menu(fronton,lista,jugador);
       
  gotoxy(20,25);
  textcolor(WHITE);
  system("PAUSE");
  return 0;
}

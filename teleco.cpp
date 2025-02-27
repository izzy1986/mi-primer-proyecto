 #include <iostream.h>
 #include <ctype.h>
 #include <time.h>
 #include "teleco.hpp"
void delay(int milisegundos) {    
   clock_t fin;
   fin = clock () + (clock_t)(milisegundos * CLK_TCK/1000) ;
   while (clock() < fin);
}
int getkey() {
   int valor;
   valor=toupper(getch());
   // Es curioso pero el codigo para caracteres
   // especiales es el 224
   // Para las teclas de funcion el valor es 0
   if ((valor==224) || (valor==0)) {
      valor=getch()+100;
   }
   return valor;
}
    // Esta funcion devuelve true si se ha producido un error en la ultima operacion
// de Entrada/Salida. En ese caso limpia el buffer de teclado. 
// Devolvera false si la ultima lectura fue correcta
bool IOError() {
   bool error;
   // char buff[255];
   if (cin.fail()) {
      cin.clear();  // Borra el flag
      cin.ignore(10000,'\n');
      //cin.getline(buff,255); // Borra el buffer (ignora caracteres hasta salto-linea)
      error=true;
   } else {
      error=false;
   }
   return error;
}

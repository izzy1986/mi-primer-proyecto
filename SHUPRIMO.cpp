#include <iostream>
#include <stdlib.h>
#include <conio.c>

using namespace std;

void DibujarIntro(){
textcolor(LIGHTGREEN);
cout << endl << endl << endl << endl;
cout << "            #   ####  #   #    #   #    #   #   # #     " << endl;
cout << "           # #  #   # #  #    # #  #    #  # #  # # #   " << endl;
cout << "          #   # #   # # #    #   # ##   # #   # # #  #  " << endl;
cout << "          #   # ####  ##     #   # # #  # #   # # #  #  " << endl;
cout << "          ##### ##    # #    ##### #  # # #   # # #  #  " << endl;
cout << "          #   # # #   #  #   #   # #   ## #   # # #  #  " << endl;
cout << "          #   # #  #  #   #  #   # #    #  # #  # # #   " << endl;
cout << "          #   # #   # #    # #   # #    #   #   # #     " << endl;
  
cout << endl << endl << endl;
textcolor(WHITE);
cout << "Por Carlos Alberto Hernandez" << endl << endl;
cout << endl << endl << endl << endl;
}


int main(int argc, char *argv[])
{  
  DibujarIntro();
  system("PAUSE");	
  return 0;
}


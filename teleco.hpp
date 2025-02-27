 #include <conio.h>
// Permite parar la ejecucion del programa durante un tiempo. El tiempo se indica
// en milisegundos
// Ejemplos: delay(2000) pararia la ejecucion 2 segundo
//           delay(100) pararia una decima de segundo
void delay(int milisegundos);
// Esta funcion lee una tecla sin mostrar ECO en pantalla. Devuelve un codigo de tecla
// De acuerdo a la lista de codigos que se definen abajo
int getkey();
// Esta funcion devuelve true si se ha producido un error en la ultima operacion
// de Entrada/Salida. En ese caso limpia el buffer de teclado. 
// Devolvera false si la ultima lectura fue correcta
 bool IOError() ;
 
 
//   LISTA DE CODIGOS DE TECLAS (Devuelta por getKey())
#define KEY_A                 65
#define KEY_B                 66
#define KEY_C                 67
#define KEY_D                 68
#define KEY_E                 69
#define KEY_F                 70
#define KEY_G                 71
#define KEY_H                 72
#define KEY_I                 73
#define KEY_J                 74
#define KEY_K                 75
#define KEY_L                 76
#define KEY_M                 77
#define KEY_N                 78
#define KEY_O                 79
#define KEY_P                 80
#define KEY_Q                 81
#define KEY_R                 82
#define KEY_S                 83
#define KEY_T                 84
#define KEY_U                 85
#define KEY_V                 86
#define KEY_W                 87
#define KEY_X                 88
#define KEY_Y                 89
#define KEY_Z                 90
#define KEY_0                 48
#define KEY_1                 49
#define KEY_2                 50
#define KEY_3                 51
#define KEY_4                 52
#define KEY_5                 53
#define KEY_6                 54
#define KEY_7                 55
#define KEY_8                 56
#define KEY_9                 57
#define KEY_F1               159
#define KEY_F2               160
#define KEY_F3               161
#define KEY_F4               162
#define KEY_F5               163
#define KEY_F6               164
#define KEY_F7               165
#define KEY_F8               166
#define KEY_F9               167
#define KEY_F10              168
#define KEY_F11              233
#define KEY_F12              234
#define KEY_ESC               27
#define KEY_TILDE             39
#define KEY_MINUS             45
#define KEY_EQUALS            61
#define KEY_BACKSPACE          8
#define KEY_TAB                9
#define KEY_OPENBRACE        123
#define KEY_CLOSEBRACE       125
#define KEY_ENTER             13
#define KEY_QUOTE             34
#define KEY_BACKSLASH         92
#define KEY_COMMA             44
#define KEY_SLASH             47
#define KEY_SPACE             32
#define KEY_INSERT           182
#define KEY_DEL              183
#define KEY_HOME             171
#define KEY_END              179
#define KEY_PGUP             173
#define KEY_PGDN             181
#define KEY_LEFT             175
#define KEY_RIGHT            177
#define KEY_UP               172
#define KEY_DOWN             180
#define KEY_ASTERISK          42
#define KEY_PLUS	          43


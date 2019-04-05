#include "kernel.h"
#include "screen.h"


#define TXT_BLANCO 0x07 //blanco sobre negro


char *memoria_video = (char *) 0xb8000;

unsigned int linea = 0;

void kernel_main(){
    limpiar_pantalla();


    imprimir_pantalla(".__           .__");
    imprimir_pantalla("|  |__   ____ |  | _____              ____  ______");
    imprimir_pantalla("|  |  \\ /  _ \\|  | \\__  \\    ______  /  _ \\/  ___/");
    imprimir_pantalla("|   Y  (  <_> )  |__/ __ \\_ /_____/ (  <_> )___ \\");
    imprimir_pantalla("|___|  /\\____/|____(____  /          \\____/____  >");
    imprimir_pantalla("\\/                 \\/                     \\/");

                             
}



void limpiar_pantalla(){
    unsigned int i = 0;
    while (i < (80*25*2)){
        memoria_video[i] = ' ';
        i++;
        memoria_video[i] = TXT_BLANCO;
        i++;
    }
}



unsigned int imprimir_pantalla(char *string){

    unsigned int i = 0;

    i = (linea*80*2);

    while(*string != 0){
        if (*string == '\n'){
            linea++;
            i = (linea*80*2);
            *string++;
        } else {
            memoria_video[i] = *string;
            *string++;
            i++;
            memoria_video[i] = TXT_BLANCO;
            i++;
        }
    }
    linea++;

    return(1);
}

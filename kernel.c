
#define TXT_BLANCO 0x07 //blanco sobre negro

void limpiar_pantalla();
unsigned int imprimir_pantalla(char *, unsigned int );
void update_cursor(int , int );


char *memoria_video = (char *) 0xb8000;

void kernel_main(){
    limpiar_pantalla();
    imprimir_pantalla("Hola-OS!",0);
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



unsigned int imprimir_pantalla(char *string, unsigned int linea){
    
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
    
    return(1);
}

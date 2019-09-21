#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcions.h"

void print_image(FILE *fptr);

int main (void){
    int men;
    struct Personaje personatges;
    char *filename = ".image.txt"; // arxiu invisible
    FILE *fptr = NULL;
    
    system("vlc --qt-start-minimized .musica.mp3 > /dev/null 2>&1 &");  //música (arxiu invisible)
 
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"No s'ha pogut obrir la portada! %s\n",filename);
        return 1;
    }
 
    print_image(fptr);
 
    fclose(fptr);
    
    do{
        men=menu();
        switch(men){
            case 1:
                Introducir(personatges);
				break;
            case 2:
				VisualitzaTot(personatges);
				break;
            case 3:
                VisualitzaPaP(personatges);
				break;
            case 4:
                BuscaCasa(personatges);
				break;
            case 5:
                muerte(personatges);
				break;
            case 6:
                IntroducirInP(personatges);
				break;
            case 7:
                mostarMuertos(personatges);
				break;
            case 8:
                ordenaMitjana(personatges);
				break;
			case 9:
                printf("Adèu!\n");
                printf("\n'L'amor és la mort del deure.' Mestre Aemon\n");
                system("killall vlc");
				break;
            default:
                printf("Opció no valida!\n\n");
				break;
        }
    }while(men!=9);
    return 0;
}

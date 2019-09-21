#include "struct.h"

#define N_CRITIQUES 3.0
#define MAX_NAME 30
#define MAX_V 50
#define MAX_LEN 128

int menu(void);

void Introducir(struct Personaje p); //introdueix personange
void VisualitzaTot(struct Personaje p); //visualitza tot el vector
void VisualitzaPaP(struct Personaje p); //visualitza d'un punt del vector a un altre
void BuscaCasa(struct Personaje p); //visualitza la casa que el usuari vulgui
void muerte(struct Personaje p); //esborra personatge del vector amb el nom i cognom
void IntroducirInP(struct Personaje p); //permet introduir un personatge en el punt del vector que ens digui l'usuari
void mostarMuertos(struct Personaje p); //obre un arxiu on mostra el morts més i menys importants
void ordenaMitjana (struct Personaje p); //ordena per mitjana i permet moificar la nota


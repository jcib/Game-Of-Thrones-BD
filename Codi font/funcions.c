#include <stdio.h>
#include <string.h>
#include "funcions.h"

#define N_CRITIQUES 3.0
#define MAX_NAME 30
#define MAX_V 50
#define MAX_LEN 128

FILE * fp;
FILE * fpmort;

void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}

int menu(void){
    int opcio;
    printf("1) Introduir personatge.\n");
    printf("2) Visualitzar personatges.\n");
    printf("3) Visualitzar personatges d'un punt del vector al altre.\n");
    printf("4) Visualitzar personatge buscant la casa/familia. \n");
    printf("5) Matar personatge pel nom. \n");
    printf("6) Insertar personatge a cualsevol punt del vector. \n");
    printf("7) Cementiri dels personatges. \n");
    printf("8) Ordenar personatges segons la mitjana. \n");
    printf("9) Exir del programa. \n");
    printf("------------------------------------------------------------\n");
    printf("Selecciona opció: "); scanf("%d",&opcio);
    getchar();
    return opcio;
}
void Introducir(struct Personaje p){
    int trobat,ok=0;
    char nom [MAX_NAME], cognom [MAX_NAME];  
    struct Personaje m;
    if((fp = fopen("GoT.bin","rb")) == NULL){
		if((fpmort = fopen("morts.bin","rb")) == NULL){
			fp=fopen("GoT.bin","wb");
			printf("Diga'm nom: "); gets(p.nom);
			printf("Diga'm cognom: "); gets(p.cognom);
			printf("Diga'm Família: "); gets(p.familia);
			
			ok=0;
			do{
				printf("Diga'm Puntuació 1: "); scanf("%d",&p.punt1);
				if(p.punt1<0 || p.punt1>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);

			ok=0;
			do{
				printf("Diga'm Puntuació 2: "); scanf("%d",&p.punt2);
				if(p.punt2<0 || p.punt2>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);
				
			ok=0;
			do{
				printf("Diga'm Puntuació 3: "); scanf("%d",&p.punt3);
				if(p.punt3<0 || p.punt3>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);
			
			
			p.media=(p.punt1+p.punt2+p.punt3)/N_CRITIQUES;
			fwrite(&p, sizeof(struct Personaje), 1, fp);
			printf("\n\n\n");
			fclose(fp);
		}
		else{
			fclose(fpmort);
			fpmort=fopen("morts.bin","rb");
			do{
				printf("Diga'm nom: "); gets(nom);
				printf("Diga'm cognom: "); gets(cognom);
				trobat=0;
				while(fread(&m, sizeof(struct Personaje),1,fpmort) == 1){
					if((strcmp(nom,m.nom)==0)&&(strcmp(cognom,m.cognom)==0)){
						 trobat=1;
						 printf("El personatge es troba mort, no ho pots afegir!\n\n");
					 }
				}
			}while(trobat!=0);
			fclose(fpmort);
			fp=fopen("GoT.bin","wb");
			strcpy( p.nom,nom);
			strcpy( p.cognom,cognom);
			printf("Diga'm Família: "); gets(p.familia);
			
			ok=0;
			do{
				printf("Diga'm Puntuació 1: "); scanf("%d",&p.punt1);
				if(p.punt1<0 || p.punt1>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);

			ok=0;
			do{
				printf("Diga'm Puntuació 2: "); scanf("%d",&p.punt2);
				if(p.punt2<0 || p.punt2>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);
				
			ok=0;
			do{
				printf("Diga'm Puntuació 3: "); scanf("%d",&p.punt3);
				if(p.punt3<0 || p.punt3>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);
			
			p.media=(p.punt1+p.punt2+p.punt3)/N_CRITIQUES;
			fwrite(&p, sizeof(struct Personaje), 1, fp);
			printf("\n\n\n");
			fclose(fp);
		}
		
    }
    
    else{
		fclose(fp); // es tanca l'arxiu perquè la comprovació anterior ha deixat "fp" com obert
		
		if((fpmort = fopen("morts.bin","rb")) == NULL){
			fp = fopen("GoT.bin", "rb");
			do{
				printf("Diga'm nom: "); gets(nom);
				printf("Diga'm cognom: "); gets(cognom);
				trobat=0;	
				while(fread(&p, sizeof(struct Personaje),1,fp) == 1){
					if((strcmp(nom,p.nom)==0)&&(strcmp(cognom,p.cognom)==0)){
						 trobat=1;
						 printf("No es pot repetir les dades!\n\n");
					 }
				}
			}while(trobat!=0);//Serveix per comprovar si el personatje existeix
			fclose(fp);
			if(trobat==0){
				fp = fopen("GoT.bin",  "a+b");	
				strcpy( p.nom,nom);
				strcpy( p.cognom,cognom);	
				printf("Diga'm Família: "); gets(p.familia);

			ok=0;
			do{
				printf("Diga'm Puntuació 1: "); scanf("%d",&p.punt1);
				if(p.punt1<0 || p.punt1>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);

			ok=0;
			do{
				printf("Diga'm Puntuació 2: "); scanf("%d",&p.punt2);
				if(p.punt2<0 || p.punt2>10) printf("LLa puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);
				
			ok=0;
			do{
				printf("Diga'm Puntuació 3: "); scanf("%d",&p.punt3);
				if(p.punt3<0 || p.punt3>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);

				p.media=(p.punt1+p.punt2+p.punt3)/N_CRITIQUES;
				fwrite(&p, sizeof(struct Personaje), 1, fp);
				printf("\n\n\n");
				fclose(fp);
			}
		}
		else{
			fclose(fpmort);
			fp = fopen("GoT.bin", "rb");
			fpmort = fopen("morts.bin", "rb");
			do{
				printf("Diga'm nom: "); gets(nom);
				printf("Diga'm cognom: "); gets(cognom);
				trobat=0;	
				while(fread(&p, sizeof(struct Personaje),1,fp) == 1){
					if((strcmp(nom,p.nom)==0)&&(strcmp(cognom,p.cognom)==0)){
						 trobat=1;
						 printf("No es pot repetir les dades!\n\n");
					 }
				}
				while(fread(&m, sizeof(struct Personaje),1,fpmort) == 1){
					if((strcmp(nom,m.nom)==0)&&(strcmp(cognom,m.cognom)==0)){
						 trobat=1;
						 printf("El personatge es troba mort, no ho pots afegir\n\n");
					 }
				}
			}while(trobat!=0);//Serveix per comprovar si el personatje existeix
			fclose(fp);
			fclose(fpmort);
			if(trobat==0){
				fp = fopen("GoT.bin",  "ab");
				strcpy( p.nom,nom);
				strcpy( p.cognom,cognom);	
				printf("Diga'm Família: "); gets(p.familia);

			ok=0;
			do{
				printf("Diga'm Puntuació 1: "); scanf("%d",&p.punt1);
				if(p.punt1<0 || p.punt1>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);

			ok=0;
			do{
				printf("Diga'm Puntuació 2: "); scanf("%d",&p.punt2);
				if(p.punt2<0 || p.punt2>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);
				
			ok=0;
			do{
				printf("Diga'm Puntuació 3: "); scanf("%d",&p.punt3);
				if(p.punt3<0 || p.punt3>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
				else ok=1;
			}while(!ok);

			p.media=(p.punt1+p.punt2+p.punt3)/N_CRITIQUES;
			fwrite(&p, sizeof(struct Personaje), 1, fp);
			printf("\n\n\n");
			fclose(fp);
			}
			
		}
	}
}
void VisualitzaTot(struct Personaje p){
    
    if((fp = fopen("GoT.bin","rb")) == NULL) printf("No hi ha cap personatge registrat!\n\n");
    else{
		while(fread(&p, sizeof(struct Personaje),1,fp) == 1){
			printf("Nom: %s\n",p.nom);
			printf("Cognom: %s\n",p.cognom);
			printf("Família: %s\n",p.familia);
			printf("Puntuació 1: %d\n",p.punt1);
			printf("Puntuació 2: %d\n",p.punt2);
			printf("Puntuació 3: %d\n",p.punt3);
			printf("Mitjana: %.2f\n",p.media);
			printf("-------------------------\n\n"); 
		}
		fclose(fp);
    }
    
}
void VisualitzaPaP(struct Personaje p ){
    int punto1,punto2,i,true,quantitatPj,POSTEMP;
    struct Personaje c[MAX_V];

    if((fp = fopen("GoT.bin","rb")) == NULL) printf("No hi ha cap personatge registrat!\n\n");
    else{   
		
		fseek(fp, 0, SEEK_END); 
		quantitatPj = ftell(fp) / sizeof(struct Personaje);
		fclose(fp);
	 
		true=0;
		do{
			printf("Des d'on vols visualitzar? "); scanf("%d",&punto1);
			if(punto1<=0 || punto1>quantitatPj) printf("No pots iniciar a menys de 1 o més gran que el número total de personatges!\n");
			else true=1;			
		}while(true==0); //comprovem que sigui més gran que 0 i menys que el total
		
		true=0;
		do{
			printf("Fins a on vols visualitzar? "); scanf("%d",&punto2);
			if(punto2<punto1 || punto2>quantitatPj) printf("No pots iniciar menor al valor inicial o més gran que el vector.\n");
			else true=1;
		}while(true==0); //comprovem que sigui més gran que punto1 i menys que el total
		
		if((fp = fopen("GoT.bin","rb")) == NULL) printf("No hi ha cap personatge registrat!\n\n");
		else{
			fclose(fp);
			
			fp = fopen("GoT.bin","rb");
			fseek(fp, (punto1-1)*sizeof(struct Personaje), SEEK_SET); // no volem que el vector copii més del compte

			fread(c, sizeof(struct Personaje), (punto2+1)-punto1, fp);  
			fclose(fp);
			
			for(i=0;i<(punto2+1)-punto1;i++){
				printf("Nom: %s\n",c[i].nom);
				printf("Cognom: %s\n",c[i].cognom);
				printf("Família: %s\n",c[i].familia);
				printf("Puntuació 1: %d\n",c[i].punt1);
				printf("Puntuació 2: %d\n",c[i].punt2);
				printf("Puntuació 3: %d\n",c[i].punt3);
				printf("Mitjana: %.2f\n",(c[i].punt1+c[i].punt2+c[i].punt3)/N_CRITIQUES);
				printf("-------------------------\n\n");
			}
		}
	}
}
void BuscaCasa(struct Personaje p){
    char busca[MAX_NAME];
    int trobat=0;
     if((fp = fopen("GoT.bin","rb")) == NULL) printf("No hi ha cap personatge registrat!\n\n");
    else{
		printf("Introdueix nom de la família/casa: "); gets(busca);
		
		while(fread(&p, sizeof(struct Personaje),1,fp) == 1){
			if(strcmp(busca,p.familia)==0) {
				printf("Nom: %s\n",p.nom);
				printf("Cognom: %s\n",p.cognom);
				printf("Familia: %s\n",p.familia);
				printf("Puntuació 1: %d\n",p.punt1);
				printf("Puntuació 2: %d\n",p.punt2);
				printf("Puntuació 3: %d\n",p.punt3);
				printf("Mitjana: %.2f\n",p.media);
				printf("-------------------------\n\n");
				trobat=1;
				}
			}
		fclose(fp);
		
		if(!trobat) printf("No hi ha cap que familia '%s'\no potser ho has escrit malament! ",busca); //en cas que no mostrara aquest misatge
	}
}
void muerte(struct Personaje p){
	char nom[MAX_NAME], cognom [MAX_NAME];
	int i,j,trobat=0,posicion=-1;
	 if((fp = fopen("GoT.bin","rb")) == NULL) printf("No hi ha cap personatge registrat!\n\n");
     else{
		struct Personaje m;
		printf("Diga'm el nom: "); gets(nom);
		printf("Diga'm el cognom: "); gets(cognom);
		struct Personaje c[MAX_V];	
		while(fread(&p, sizeof(struct Personaje),1,fp) == 1){ 
			posicion++;
			strcpy( c[posicion].nom,p.nom);
			strcpy( c[posicion].cognom,p.cognom);
			strcpy( c[posicion].familia,p.familia);
			c[posicion].punt1=p.punt1;
			c[posicion].punt2=p.punt2;
			c[posicion].punt3=p.punt3;
			c[posicion].media=p.media;
		}
		fclose(fp);
		
		for(i=0;i<=posicion && trobat==0;i++){
			if((strcmp(nom,c[i].nom)==0)&&strcmp(cognom,c[i].cognom)==0){ 
				trobat=1;
				fpmort=fopen("morts.bin","ab");
				strcpy( m.nom,c[i].nom); 
				strcpy( m.cognom,c[i].cognom);
				strcpy( m.familia,c[i].familia); 
				m.punt1=c[i].punt1; 
				m.punt2=c[i].punt2; 
				m.punt3=c[i].punt3; 
				m.media=c[i].media;
				fwrite(&m, sizeof(struct Personaje), 1, fp);
				fclose(fpmort);
			}
			
		}
		
		if(trobat){
			
			for(j=i-1;j<posicion;j++){
				strcpy(c[j].nom,c[j+1].nom);
				strcpy(c[j].cognom,c[j+1].cognom);
				strcpy(c[j].familia,c[j+1].familia);
				c[j].punt1=c[j+1].punt1;
				c[j].punt2=c[j+1].punt2;
				c[j].punt3=c[j+1].punt3;
				c[j].media=c[j+1].media;
			}
			
			fp = fopen("GoT.bin",  "wb");
			for (i = 0; i <= posicion-1; i++){
				strcpy( p.nom,c[i].nom);
				strcpy( p.cognom,c[i].cognom);
				strcpy( p.familia,c[i].familia);
				p.punt1=c[i].punt1;
				p.punt2=c[i].punt2;
				p.punt3=c[i].punt3;
				p.media=c[i].media;
				fwrite(&p, sizeof(struct Personaje), 1, fp);
			}
			fclose(fp);
			printf("Has matat un personatge, ets un assassí!\n\n");
		}
		else printf("El personatge %s %s no existeix en la BD!\n",nom,cognom);
	}	
}
void IntroducirInP(struct Personaje p){
    int lloc,valid,i,trobat,j,posicion=-1;
    struct Personaje c[MAX_V],m;
    if((fp = fopen("GoT.bin","rb")) == NULL) printf("No hi ha cap personatge registrat!\n\n");
	else{ 
		while(fread(&p, sizeof(struct Personaje),1,fp) == 1){ 
			posicion++;
			strcpy( c[posicion].nom,p.nom);
			strcpy( c[posicion].cognom,p.cognom);
			strcpy( c[posicion].familia,p.familia);
			c[posicion].punt1=p.punt1;
			c[posicion].punt2=p.punt2;
			c[posicion].punt3=p.punt3;
		}
		fclose(fp);
		
		do{
			valid=0;
			printf("Agafa una posició entre 1 i %d: ",posicion+1); scanf("%d",&lloc);
			lloc--;
			if(valid<0 || valid>posicion) printf("No pot ser menor que 0 ni majorque %d!\n\n",posicion);
			else valid=1;
		}while(valid!=1);
		posicion++; //Al afegir un personatge incrementem el llarg del vector
		for(i=posicion;i>lloc;i--){
			strcpy(c[i].nom,c[i-1].nom);
			strcpy(c[i].cognom,c[i-1].cognom);
			strcpy(c[i].familia,c[i-1].familia);
			c[i].punt1=c[i-1].punt1;
			c[i].punt2=c[i-1].punt2;
			c[i].punt3=c[i-1].punt3;
		} 
	   
		getchar();
		do{
			trobat=0;
			printf("Diga'm nom: "); gets(c[i].nom);
			printf("Diga'm cognom: "); gets(c[i].cognom);
			for(j=0;j<posicion && trobat==0;j++){
				if((strcmp(c[j].nom,c[i].nom)==0)&&(strcmp(c[j].cognom,c[i].cognom)==0)){
					if(i!=j){
						trobat=1;
						printf("No pots repetir el personatge.\nTorna a introduir les dades.\n\n");
					}
				}
			}
			if((fpmort = fopen("morts.bin","rb")) != NULL){			
					while(fread(&m, sizeof(struct Personaje),1,fpmort) == 1){
						if((strcmp(c[i].nom,m.nom)==0)&&(strcmp(c[i].cognom,m.cognom)==0)){
							 trobat=1;
							 printf("El personatge es troba mort, no ho pots afegir!\n\n");
						 }
					}
				fclose(fpmort);
			}
		}while(trobat!=0);//Serveix per comprovar si el personatje existeix
		printf("Diga'm Família: "); gets(c[i].familia);
		printf("Diga'm Puntuació 1: "); scanf("%d",&c[i].punt1);
		printf("Diga'm Puntuació 2: "); scanf("%d",&c[i].punt2);
		printf("Diga'm Puntuació 3: "); scanf("%d",&c[i].punt3);    
		
		fp = fopen("GoT.bin",  "wb");
			for (i = 0; i <= posicion; i++){
				strcpy( p.nom,c[i].nom);
				strcpy( p.cognom,c[i].cognom);
				strcpy( p.familia,c[i].familia);
				p.punt1=c[i].punt1;
				p.punt2=c[i].punt2;
				p.punt3=c[i].punt3;
				p.media=(p.punt1+p.punt2+p.punt3)/N_CRITIQUES;
				fwrite(&p, sizeof(struct Personaje), 1, fp);
			}
			fclose(fp);
		
		printf("\n\n\n");
		}
}

void mostarMuertos(struct Personaje p){
	 int mediaP=0,i=0;
	 fp=fopen("morts.bin","rb");
	
	if(fp == 0 ) printf("No ha mort cap personatge!\n\n");
	else {
		 while(fread(&p, sizeof(struct Personaje),1,fp) == 1){
			i++;
			mediaP+=p.media; 
		}
		fclose(fp);
		mediaP/=i;
		printf("Personatges més importants segons la valoració:\n\n");
		fp=fopen("morts.bin","rb");
		while(fread(&p, sizeof(struct Personaje),1,fp) == 1){
			if (mediaP<=p.media){
			printf("Nom: %s\n",p.nom);
			printf("Cognom: %s\n",p.cognom);
			printf("Família: %s\n",p.familia);
			printf("Puntuació 1: %d\n",p.punt1);
			printf("Puntuació 2: %d\n",p.punt2);
			printf("Puntuació 3: %d\n",p.punt3);
			printf("Mitjana: %.2f\n",p.media);
			printf("-------------------------\n\n"); 
			}
		}
		fclose(fp);
		printf("Personatges menys importants segons la valoració:\n\n");
		fp=fopen("morts.bin","rb");
		while(fread(&p, sizeof(struct Personaje),1,fp) == 1){
			if (mediaP>p.media){
			printf("Nom: %s\n",p.nom);
			printf("Cognom: %s\n",p.cognom);
			printf("Família: %s\n",p.familia);
			printf("Puntuació 1: %d\n",p.punt1);
			printf("Puntuació 2: %d\n",p.punt2);
			printf("Puntuació 3: %d\n",p.punt3);
			printf("Mitjana: %.2f\n",p.media);
			printf("-------------------------\n\n"); 
			}
		}
		fclose(fp);
	} 
    
}
void ordenaMitjana (struct Personaje p){	
	int i,j,quantitatPj,valid,trobat=0,posPJ,ok=0;
	char resposta[3],auxNom[20],auxCog[20];
	struct Personaje vector[MAX_V],aux;

	if((fp = fopen("GoT.bin", "rb"))==NULL)printf("No hi ha cap personatge registrat a la base de dades!\n\n");
	else{
		fseek(fp, 0, SEEK_END); 
		quantitatPj = ftell(fp) / sizeof(struct Personaje);
		fseek(fp, 0, SEEK_SET);
		
		fread(vector, sizeof(struct Personaje), quantitatPj, fp);
		
		fclose(fp);
		
		for(i=0; i<quantitatPj; i++){
			for(j=0; j<quantitatPj-1; j++){
				if (vector[j].media < vector[j+1].media){
					
				   strcpy(aux.nom,vector[j].nom);
				   strcpy(aux.cognom,vector[j].cognom);
				   strcpy(aux.familia,vector[j].familia);
				   aux.punt1=vector[j].punt1;
				   aux.punt2=vector[j].punt2;
				   aux.punt3=vector[j].punt3;
				   aux.media=vector[j].media;
				   
				   
				   strcpy(vector[j].nom,vector[j+1].nom);
				   strcpy(vector[j].cognom,vector[j+1].cognom);
				   strcpy(vector[j].familia,vector[j+1].familia);
				   vector[j].punt1=vector[j+1].punt1;
				   vector[j].punt2=vector[j+1].punt2;
				   vector[j].punt3=vector[j+1].punt3;
				   vector[j].media=vector[j+1].media;
				   
						   
				   strcpy(vector[j+1].nom,aux.nom);
				   strcpy(vector[j+1].cognom,aux.cognom);
				   strcpy(vector[j+1].familia,aux.familia);
				   vector[j+1].punt1=aux.punt1;
				   vector[j+1].punt2=aux.punt2;
				   vector[j+1].punt3=aux.punt3;   
				   vector[j+1].media=aux.media;          
				}
			} 
		}
		
		fp = fopen("GoT.bin", "wb");
		  
		fwrite(vector, sizeof(struct Personaje), quantitatPj, fp);
		
		fclose(fp);
		printf("\n***Els personatges han sigut ordenats de major mitjana a menor mitjana!***\n\n");
		
		valid=0;
		do{
			printf("Vols canviar alguna nota? (Opcions: si/no)\n"); gets(resposta);
			if(strcmp("si",resposta) == 0){

				printf("Introdueix el nom del personatge que vols canviar: "); gets(auxNom);
				printf("Introdueix el cognom del personatge que vols canviar: "); gets(auxCog);
				
				trobat=0;
				fp = fopen("GoT.bin","rb");
				while(fread(&p, sizeof(struct Personaje),1,fp) == 1){
					if((strcmp(auxNom,p.nom) && strcmp(auxCog,p.cognom)) ==0) {
						trobat=1;
						posPJ=ftell(fp) / sizeof(struct Personaje); //per sapiguer on és el personatge del qual volem canviar notes
						fclose(fp);
												
						fp = fopen("GoT.bin","r+b"); //utilitzem r+b per fer un update de les notes	
						fseek(fp, posPJ*sizeof(struct Personaje), SEEK_SET); //index * tamany del struct = num. pj buscat
							
						printf("Introdueix les notes: "); 
						
						ok=0;
						do{
							printf("Diga'm puntuació 1: "); scanf("%d",&p.punt1);
							if(p.punt1<0 || p.punt1>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
							else ok=1;
						}while(!ok);

						ok=0;
						do{
							printf("Diga'm puntuació 2: "); scanf("%d",&p.punt2);
							if(p.punt2<0 || p.punt2>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
							else ok=1;
						}while(!ok);
							
						ok=0;
						do{
							printf("Diga'm puntuació 3: "); scanf("%d",&p.punt3);
							if(p.punt3<0 || p.punt3>10) printf("La puntuació no pot ser menor que 0 ni major que 10!\n");
							else ok=1;
						}while(!ok);
						
						p.media=(p.punt1+p.punt2+p.punt3)/N_CRITIQUES;
						
						fwrite(&p, sizeof(struct Personaje), 1, fp);
						
						
						fclose(fp);
					}
				}
				
				if(trobat==0) printf("No s'ha trobat el personatge.");
				valid=1;
			}							
			else if(strcmp("no",resposta) == 0){
				valid=1;
			}
			
			else printf("Escriu 'si' o 'no'!\n");
		}while(valid!=1);
	}
}

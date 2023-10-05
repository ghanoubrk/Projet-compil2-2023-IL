#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TS.h"
#include "RS.h"

extern int indexStruct;
extern int indexTS;


int yyerror (char*);


int isDeclaredVariable(char * nom){
    for(int i=0;i<indexTS;i++){
        if(strcmp(TS[i].nom,nom)==0)
            return 1;
    }
    return 0;
}


void rsVerifierDec(char * nom){
	if(! isDeclaredVariable(nom)){
		printf("\n erreur semantique variable %s non declare",nom);
        yyerror("");
	}
}

void rsDoubleDec(char *nom){
    if(rechercher(nom)!=-1){
        printf("\n Double declaration de la variable %s. ",nom);
        yyerror("");
    }
}

void rsVerifierDecChamp(char *str, char *IDF){
	if(getIndexChamp(str,IDF)==-1){
		printf("\n le champ %s n\'apartient pas a la structure %s. ",IDF,str);
        yyerror("");
	}
}

char* SupPar(char *s){
	char dest[20];
	s[strlen(s)-1]='\0';//supprimer le ) 
	for(int i=0;i<strlen(s)-1;i++){
		s[i]=s[i+1];
	}
	s[strlen(s)-1]='\0';//on décrémente la taille de la chaine
	return s;
}

int checkSign(char *s){
	if(s[0]=='+') return 0;
	return 1;
}

char* SupSign(char *s){
	for(int i=0;i<strlen(s)-1;i++){
		s[i]=s[i+1];
	}
	s[strlen(s)-1]='\0';//on décrémente la taille de la chaine
	return s;
}

void EntierOverflow(int a){
	if(a>32767 || a <-32768) yyerror("valeur de l\'entier doit etre entre -32768 et 32767.");
}

void rsMAJconst(char *IDF){
	if(TS[rechercher(IDF)].constante == 1){
		printf("\n impossible de modifier la valeur de la constante %s. ",IDF);
        yyerror("");
	}
}






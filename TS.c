#include <stdio.h>
#include <string.h>
#include "TS.h"

int indexTS=0;
int indexTab=0;
int indexChamp=0;


extern int indexStruct;


int indexStruct=0;

//fonctions pour TS--------------------------------------

void inserer(char *nom,int type,int taille,int indexStr){
    TS[indexTS].nom=nom;
    TS[indexTS].type=type;
    TS[indexTS].taille=taille;
    TS[indexTS].indexStr=indexStr;
	TS[indexTS].constante=0;
    indexTS++;
}

int rechercher(char* idf){
    int i=0;
    while(i<indexTS && strcmp(TS[i].nom,idf)) i++;
    if(i==indexTS) return -1;
    return i;
}

void insererCst(char *nom, int type, char *val){
	TS[indexTS].nom = nom;
	TS[indexTS].type = type;
	TS[indexTS].taille=-1;
    TS[indexTS].indexStr=-1;
	TS[indexTS].valeur = val;
	TS[indexTS].constante = 1;
	indexTS++;
}

void insererTab(char *IDF){
	Tab[indexTab] = IDF;
	indexTab++;
}

void MAJtype(int type, int indexStr){
	for(int i=0;i<indexTab;i++){
		TS[rechercher(Tab[i])].type = type;
		TS[rechercher(Tab[i])].indexStr = indexStr;
	}
	indexTab=0;
}

int TypeIDF(char *idf){
    return TS[rechercher(idf)].type;
}

int getIndexStruct(char * nomStruct ){
    for(int i=0;i<indexStruct;i++){
        if(strcmp(tabStruct[i].nom,nomStruct)==0) return i;
	}
    return -1;
}

int getIndexChamp(char *str, char *IDF){
	int p=TS[rechercher(str)].indexStr;
	for(int i=0;i<tabStruct[p].nbChamps;i++){
		if(strcmp(tabStruct[p].chmp[i].nom,IDF)==0) return i;   
	}
	return -1;
}

int TypeChamp(char *structIDF, char *IDF){
	int k = TS[rechercher(structIDF)].indexStr;
	int p = getIndexChamp(structIDF,IDF);
	return tabStruct[k].chmp[p].type;
}


void ajouterStructure(char *nom){
		tabStruct[indexStruct].nom = nom;
		tabStruct[indexStruct].nbChamps = indexChamp;
		int j=0;
		for(int i=0;i<indexChamp;i++){
			tabStruct[indexStruct].chmp[j].nom = champs[i].nom;
			tabStruct[indexStruct].chmp[j].type = champs[i].type;
			j++;
		}
		indexChamp = 0;
		indexStruct++;
}

int ajouterChamps(char *nom,int type){
	for(int i=0;i<indexChamp;i++){
		if(champs[i].nom==nom) return i;
	}
    champs[indexChamp].nom=nom;
    champs[indexChamp].type=type;
	indexChamp++;
	return -1;
}

//fonctions d'affichage----------------------

void afficherTS(){
    printf("\n*******************Table des Symboles************************\n");
    printf("==================================================\n");
    printf(" IDF            |     TYPE            |     Constante            |     Valeur\n"); 
    printf("==================================================\n");
    int i;
    for (i = 0; i < indexTS; i++) { 
        printf("%-10s      |    %-11d      |    %-16d      |    %-10s\n", TS[i].nom,TS[i].type,TS[i].constante,TS[i].valeur); 
    }
}



void afficherStrTable(){
    printf("-----------------------------------------------------\n");
    printf("-----------------------------------------------------\n");
    
     printf("\n*******************Table des Structure************************\n");
    printf("==================================================\n");
    printf(" IDF            |     Nbr de Champs\n"); 
    printf("==================================================\n");
    int i;
    for (i = 0; i < indexStruct; i++) { 
        printf("%-10s      |    %-10d\n", tabStruct[i].nom,tabStruct[i].nbChamps); 
        printf("---------------------------\n");
    }

}

void afficherChamps(){
     printf("\n\n----------------------------------------\n");
    for(int i=0;i<indexStruct;i++){
            printf("\n Les champs de %s  sont : \n",tabStruct[i].nom);
            for(int j=0;j<tabStruct[i].nbChamps;j++){
                printf("\n -- %s",tabStruct[i].chmp[j].nom);
            }
    
    
    }

}


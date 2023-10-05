#ifndef TS_H
#define TS_H

#define size 10000


extern int j;
extern int indexTS;

// Les types sont codés comme les suivant:
/*
 1-->entier
 2-->réel
 3-->struct
 4--> tableau d'entier
 5-->tableau de réel
 6-->tableau de structure


*/

//les tables utilisées 
/*
	TS --> table de symbole
	tabStruct --> contient les informations des types déclarés par l'utilisateur
	Dectionnaire --> table auxilière qu'en t on utilise pour MAJ les informations des IDF déclaré (puisque l'insertion et la détermination de types ne se fait pas au même temps)
	champs --> une table auxilière qui sert comme un tempons 
*/

typedef struct 
{
   char *nom;
   int type;  
   int taille;  //si le type est un tableau  
   int indexStr;  //si le type est structure
   int constante;
   char *valeur;
}vars;


typedef struct  
{
   char *nom;
   vars chmp[50];
   int nbChamps; 

}structDetail;



vars TS[size]; // parcourue avec "indexTS"
structDetail tabStruct[size]; //parcourue avec "indexStruct"
vars champs[50]; //table auxilière pour sauvgarder les champs d'un structure. parcourue avec "indexChamp"
char *Tab[100]; //table auxilière pour sauvgarder les variables d'une liste de IDFs parcourue avec "indexTab"

//affichage---------------------------------

void afficherTS();

void afficherStrTable();

void afficherChamps();

//geters---------------------------------

int TypeIDF(char *idf);

int TypeChamp(char *structIDF, char *IDF);

int getIndexStruct(char * );

int getIndexChamp(char *str, char *IDF);


//insertion---------------------------------

int ajouterChamps(char *nom,int type);

void ajouterStructure(char *nom);

void inserer(char *nom,int type,int taille,int indexStr);

int rechercher(char* idf);

void insererCst(char *nom, int type, char *val);

void insererTab(char *IDF);

//MAJ---------------------------------

void MAJtype(int type, int indexStr);


#endif
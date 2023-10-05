#ifndef CodeMachine_H
#define CodeMachine_H


//Fonction pour écrire les quadruplets dans un fichier Text
void createTextQuad();

//Pour générer tous le code Assembleur
void createCodeAssembleur();


/*Fonction qui permet de récuperer  à partir de la TS
 Les variable : entier,réel, tab d'entier,tab de réeel
 et les écrire dans la partie Data Segment
*/
void writeDeclarationSimpleVar(char *,int,int,int,int);

//Cette fonction est pour le type struct ( meme traitement avec la précédente )
void writeDeclarationStructVar(char *,int);

//-----
void write_Oper_Aff(char *,char *,char *,char *,int);


void routineOperation(char *,char *,char *,int);

void writeJumpStataments(char *,char *,char *,char *,int);

void setEtiqs(int );


//Reparcours le tableau des quadruplets pour récupérer les branchement < num quad courant
void getBranchements();

#endif
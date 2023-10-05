#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Quad.h"
#include "CodeMachine.h"
#include "TS.h"


FILE *f;
char x;
int saveBranchments[50];   //Tableau pour sauvagrder les branchement des quadruplets
int indexBr=0;             //Index qui pointe vers la derniere case vide de tableau précédent



//-------------------------------------------------------------------------

//Fonction pour récupers à partir de TS: entier,réel,tableau de réeel, tab int et les écrire dans Data Segment
void writeDeclarationSimpleVar(char *nomVar,int typeVar,int sizeTableau,int isCst,int i){
        fprintf(f,"%s",nomVar);
        if(isCst==1){
                fprintf(f,"  EQU");
                fprintf(f,"  %s \n",TS[i].valeur);
        }
        else {
            if(typeVar==1){
                fprintf(f,"  DB   ?  \n");
            }
            else if(typeVar==2){
                fprintf(f,"  DW   ? \n");
            }
            else if(typeVar==4 ) //Tableau d'entiers
            {
                fprintf(f," DW   %d   dup(?) \n",sizeTableau);
            }
            else if(typeVar==5 ) //Tableau de réel
            {
                fprintf(f," DD   %d   dup(?) \n",sizeTableau);
            }
    }
}


//-------------------------------------------------------------------------

//Fonction pour récuperer les vars de type structure à partir TS et les écrire dans Data segment
void writeDeclarationStructVar(char *nomVar,int i){
        fprintf(f,"\n%s STRUC ",nomVar);
        int j=TS[i].indexStr;
        int nbChamps=tabStruct[j].nbChamps;
        for (int i = 0; i <nbChamps ; i++)    //Les champs sont de type Struct vars 
        {
            if(tabStruct[j].chmp[i].type==1){
                        fprintf(f,"\n%s  DB   ?  ",tabStruct[j].chmp[i].nom);
                    }
            else if(tabStruct[j].chmp[i].type==2){
                        fprintf(f,"\n%s  DW   ? ",tabStruct[j].chmp[i].nom);
                    }
        }
        fprintf(f,"\n%s Ends \n\n",nomVar);
}

//-------------------------------------------------------------------------

void routineOperation(char * opr,char *op2,char *res,int i){
    int number;
    if(sscanf(op2,"%d",&number)!=1){
                    if(op2[0]=='T' && strcmp(q[i-1].res,op2)==0){
                        fprintf(f,"\n\t\tPop BX");
                    }
                    else if(op2[0]=='T'){
                        fprintf(f,"\n\t\tPop AX");
                    }
                    else{
                        fprintf(f,"\n\t\tMov BX,%s",op2);
                    }
                    if(strcmp(opr,"MUL")==0 || strcmp(opr,"DIV")==0)
                        fprintf(f,"\n\t\t%s BX",opr);
                    else
                        fprintf(f,"\n\t\t%s AX,BX",opr);
                    if(i<indq-1 && q[i+1].op1!=NULL && strcmp(q[i+1].op1,res)!=0)
                         fprintf(f,"\n\t\tPush AX");
                }
    else{ 
            fprintf(f,"\n\t\t%s AX,%s",opr,op2);
            fprintf(f,"\n\t\tPush AX");
        }
}




//----------------------------------------------------------------
//
void write_Oper_Aff(char *opr,char *op1,char *op2,char *res,int i){
    int number;
     //Test de 1er opérande
      if(i>0 && op1[0]=='T' && strcmp(q[i-1].res,op1)!=0){
        fprintf(f,"\n\t\tPOP AX");
      }
      else if(i>=1 && strcmp(q[i-1].res,op1)!=0)
          fprintf(f,"\n\t\tMOV AX,%s",op1);    
       else if(i==0){
          fprintf(f,"\n\t\tMOV AX,%s",op1); 
       }
     
     //Test de l'opérateur 
      if(strcmp(opr,"+")==0){
         routineOperation("ADD",op2,res,i);
        }
      else if (strcmp(opr,"-")==0){
         if(sscanf(op1,"%d",&number)==1 && strcmp(op2,"")==0) {
            fprintf(f,"\n\t\tNEG AX");
            fprintf(f,"\n\t\tPUSH AX");
         } 
         else
            routineOperation("SUB",op2,res,i);
        }
      else if (strcmp(opr,"*")==0){
         routineOperation("MUL",op2,res,i);
        }
      else if (strcmp(opr,"/")==0){
         routineOperation("DIV",op2,res,i);
        }
      else if (strcmp(opr,":=")==0){ 
                if(res[0]=='T'){
                     fprintf(f,"\n\t\tPUSH AX");
                }
                else
                     fprintf(f,"\n\t\tMOV %s,AX",res);
        }
}
//-------------------------------------------------------------------------


void writeJumpStataments(char *opr,char *op1,char *op2,char *res,int i){
    int number;
        saveBranchments[indexBr]=atoi(op1);
        indexBr++;
     
       
           if(i>0 && op2[0]=='T' && strcmp(q[i-1].res,op2)!=0){
                 fprintf(f,"\n\t\tPOP CX");      //charger op1 
             }
           else if(i>=1 && strcmp(q[i-1].res,op2)!=0 && strcmp(op2,"")!=0 )
                 fprintf(f,"\n\t\tMOV CX,%s",op2);    
           else if(i==0 && strcmp(op2,"")!=0){
                fprintf(f,"\tMOV CX,%s",op2); 
            }

            //Ici le 2eme opérande (res) est vide
            if(strcmp(opr,"BZ")==0){
                   if(i>0 && strcmp(q[i-1].res,op2)==0)
                        fprintf(f,"\n\t\tCMP AX,0");
                   else
                        fprintf(f,"\n\t\tCMP CX,0");
                   fprintf(f,"\n\t\tJZ Etiq%s",op1);
             }
             else if ( strcmp(opr,"BNZ")==0 ){
                  if(i>0 && strcmp(q[i-1].res,op2)==0)
                        fprintf(f,"\n\t\tCMP AX,0");
                  else
                        fprintf(f,"\n\t\tCMP CX,0");
                  fprintf(f,"\n\t\tJNZ Etiq%s",op1);
             }  
        
          //Ici le 2eme opérande (res) est non vide 
         //Si l'opérateur est différent de BR incoditionelle ou opération de comparaison avec 0
          else if( strcmp(opr,"BZ")!=0 && strcmp(opr,"BNZ")!=0  && strcmp(opr,"BR")!=0){
            if(sscanf(res,"%d",&number)!=1){
                        if(res[0]=='T'){
                            fprintf(f,"\n\t\tPop DX");
                        }
                        else{
                            fprintf(f,"\n\t\tMov DX,%s",res);
                        }
                         if(i>0 && strcmp(q[i-1].res,op2)==0)
                               fprintf(f,"\n\t\tCMP AX,DX");
                         else
                              fprintf(f,"\n\t\tCMP CX,DX");
                    }
                    else{ 
                        fprintf(f,"\n\t\tCMP CX,%s",res);
                    }
        
                if(strcmp(opr,"BG")==0)
                    fprintf(f,"\n\t\tJG Etiq%s",op1);
                else if(strcmp(opr,"BGE")==0)
                    fprintf(f,"\n\t\tJG Etiq%s",op1);
                else if (strcmp(opr,"BL")==0)
                    fprintf(f,"\n\t\tJL Etiq%s",op1);
                else if (strcmp(opr,"BLE")==0)
                    fprintf(f,"\n\t\tJLE Etiq%s",op1);
                else if (strcmp(opr,"BE")==0)
                    fprintf(f,"\n\t\tJE Etiq%s",op1);
                else if (strcmp(opr,"BNE")==0)
                    fprintf(f,"\n\t\tJNE Etiq%s",op1);
            }
            
            else if(strcmp(opr,"BR")==0){
                fprintf(f,"\n\t\tJMP Etiq%s",op1);
            }

            
}

//----------------------------------------------------------

//Reparcours le tableau des quadruplets pour récupérer les branchement < num quad courant
void getBranchements(){
     for(int i=0;i<indq;i++){
        if(q[i].opr[0]=='B' && atoi(q[i].op1)<i){
                saveBranchments[indexBr]=atoi(q[i].op1);
                indexBr++;
            }
   }
  }
   

//-------------------------------------------------------------------
void setEtiqs(int i){
    //Ecriture des étiquettes
    for(int j=0;j<indexBr;j++){
          if(i==saveBranchments[j]){
            fprintf(f,"\nEtiq%d:",i);
            break;
          }
    }
}



//-------------------------------------------------------------------------


//Generer Tous le code Assembleur
//-------------------------The main Function-------------------------------------
void createCodeAssembleur(){
    int i;
    char quad[100];
    char *TempTab[100];
    int indexTempTab=0;

    f=fopen("Assembleur.asm","w");
    if(f==NULL){
        printf("Error while creating File !");
        exit(-1);
    }

    fprintf(f,"TITLE Assembleur.asm");

    //-----------------------------
    //Partie Declaration des variables
    fprintf(f,"\nData SEGMENT \n");

     for (i=0;i<indexTS;i++){ 
       char *nomVar=TS[i].nom;
       int typeVar=TS[i].type;
       int isCst=TS[i].constante;
       int sizeTableau=TS[i].taille;

       switch (typeVar)
       {
       case 1: 
       case 2: 
       case 4:
       case 5: 
                writeDeclarationSimpleVar(nomVar,typeVar,sizeTableau,isCst,i);
            break;

       case 3: writeDeclarationStructVar(nomVar,i);
            break;
       }        
    }
    fprintf(f,"Data ends \n");

    //--------------------

    //Partie Code
    fprintf(f,"\nCode SEGMENT");
    fprintf(f,"\nASSUME CS:Code ,DS:Data");
    fprintf(f,"\nStart :");
    fprintf(f," MOV AX,DATA");
    fprintf(f,"\n\t\tMOV DS,AX");
    getBranchements();
     for (i=0;i<indq;i++){
        setEtiqs(i);
        if(q[i].opr!=NULL){ 
            if(strcmp(q[i].opr,"+")==0 ||strcmp(q[i].opr,"-")==0 ||strcmp(q[i].opr,"/")==0 || strcmp(q[i].opr,"*")==0 ||strcmp(q[i].opr,":=")==0)
                write_Oper_Aff(q[i].opr,q[i].op1,q[i].op2,q[i].res,i);
            else
                writeJumpStataments(q[i].opr,q[i].op1,q[i].op2,q[i].res,i);
            
        }
    }
    
    fprintf(f,"\nEtiq%d :",indq);
    fprintf(f,"\nCode ENDS");
    fprintf(f,"\nEND Start ");

    fclose(f);
}



//-------------------------------------------------------------------------


//Fonction pour écrire les quadruplets dans un fichier Text
void createTextQuad(){
    int i;
    FILE *f;
    f=fopen("QuadText.txt","w");
    if(f==NULL){
        printf("Error while creating File !");
        exit(-1);
    }
    //Ecriture de contenu des quadruplets dans un ficher text:
    char quad[100];
    for (i=0;i<indq;i++){
        sprintf(quad,"%d-( %s , %s , %s , %s )\n",i,q[i].opr,q[i].op1,q[i].op2,q[i].res);
        fprintf(f,"%s",quad);
    }

    fclose(f);
}

//-------------------------------------------------------------------------


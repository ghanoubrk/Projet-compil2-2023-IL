/*
list des routines sémantiques implémentés:
	* déclaration des variables
	* double déclaration des variables 
	* compatibilité des types dans les instructions
	* la taille maximale des entiers 
	* vérification d'apartenance des champs aux structures 
	* double déclaration des champs dans les structures
	* Division par zéro
	* autres... 
*/
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TS.h"
#include "RS.h"
#include "Quad.h"
#include "CodeMachine.h"

    
int yylex();
int yyerror(char *);

extern FILE* yyin;
extern int line,colo;

char msg[100];//message d'erreur en générale
//variable pour les quad--------------------------------
int nTemp=1; char tempC[12]="";
int sauv_BNE,sauv_BR,sauv_BE,sauv_BLE,sauv_BL,sauv_BGE,sauv_BG,sauv_BNZ,sauv_BZ,sauv_res,sauv_pos;
char *quadNum;
char *tempStr;
char position[12]="";
%}

%union {char* nom; 
			struct {char* name; int type; char* res; int nbr; int pos; int debut;}NT; 
			struct {char* nom; int val;}DECT;
			struct {char* nomIndice; char* etape; int debutCond; int sauv_BZ; int sauv_BNZ;}boucle;
			struct {int sauv_BZ; int sauv_BR;}Cond;
			struct{int indexStr;}structure;
		}

%token<nom> VAR CODE INTEGER FLOAT STRUCT IF CONST ELSE FOR WHILE 
%token<nom> IDF REEL ENTIER REEL_SGN ENTIER_SGN
%token AFF ADD SUB MUL DIV
%token '(' ')' '{' '}' ';' ':' '[' ']' ',' '.'
%token  OR AND NOT
%token G GE L LE E NE

%left OR
%left AND
%left NOT

%left ADD SUB
%left MUL DIV

%type<NT> exp term factor NUMBER condition instruction
%type<DECT> listIDF
%type<boucle> FORpartie1 FORpartie2 FORpartie3 FORpartie4 WHILEpartie1 WHILEpartie2
%type<Cond> IFpartie1 IFpartie2 IFpartie3
%type<structure> STRuse

%%
S:IDF '{' VAR '{' declaration '}' CODE '{' instruction'}' '}';

//-------------partie Declaration---------------------------------------

declaration:
             INTEGERdecPartie1  declaration                       		{}	
																		     
            |INTEGER  IDF'['ENTIER']' ';' declaration           		{rsDoubleDec($2); inserer($2,4,atoi($4),-1);}

            |FLOATdecPartie1 declaration                 				{}   
            |FLOAT IDF '['ENTIER']' ';' declaration     				{rsDoubleDec($2);  inserer($2,5,atoi($4),-1);}

            |STRusePartie2  declaration      							{}
																		  
  

            |CONST IDF AFF ENTIER ';'declaration						{if(rechercher($2)==-1){EntierOverflow(atoi($4)); insererCst($2,1,$4);}
																			else{printf("constante %s deja declare. ",$2); yyerror("");}
																		}
																		
			|CONST IDF AFF ENTIER_SGN ';'declaration					{if(rechercher($2)==-1){EntierOverflow(atoi(SupPar($4))); insererCst($2,1,$4);}
																			else{printf("constante %s deja declare. ",$2); yyerror("");}
																		}

            |CONST IDF AFF REEL ';'declaration                          {if(rechercher($2)==-1){insererCst($2,2,$4);}
																			else{printf("constante %s deja declare. ",$2); yyerror("");}
																		}       

			|CONST IDF AFF REEL_SGN ';'declaration                      {if(rechercher($2)==-1){insererCst($2,2,$4);}
																			else{printf("constante %s deja declare. ",$2); yyerror("");}
																		} 
																		
            |STRdec ';' declaration   							{}  
                                                                         
            | 
            ;

INTEGERdecPartie1 : INTEGER   listIDF							{MAJtype(1,-1);}
				;

FLOATdecPartie1 : FLOAT   listIDF								{MAJtype(2,-1);}
				;

STRusePartie2 : STRuse  listIDF									{MAJtype(3,$1.indexStr);}
				;

STRdec : STRUCT '{' CHAMPS '}' IDF				{if(getIndexStruct($5)!=-1){printf("erreur sémantique double déclaration de structure. "); yyerror("");}
													ajouterStructure($5);
												}
		;
					 
CHAMPS : CHAMP ';' CHAMPS 						{}
		|										{}
		;

listIDF: IDF ';' 			{rsDoubleDec($1); inserer($1,0,-1,-1); insererTab($1); }
		| IDF ',' listIDF	{rsDoubleDec($1); inserer($1,0,-1,-1); insererTab($1); }
		;

CHAMP : INTEGER  IDF							{if(ajouterChamps($2,1)!=-1){printf("erreur semantique; double déclaration de champs. "); yyerror("");}}
		|FLOAT IDF 								{if(ajouterChamps($2,2)!=-1){printf("erreur semantique; double déclaration de champs. "); yyerror("");}}
		;
		
STRuse : STRUCT IDF								{if(getIndexStruct($2)==-1){printf("erreur semantique; structure nest pas declare."); yyerror("");}
													$$.indexStr = getIndexStruct($2);
												}
		;


NUMBER: ENTIER 		{$$.res = strdup($1); $$.type = 1;}
        |REEL 		{$$.res = strdup($1); $$.type = 2;}
        |ENTIER_SGN {$$.type = 1; tempStr=strdup(SupPar($1));
						if(checkSign(tempStr)){sprintf(tempC,"T%d",nTemp); nTemp++; quad("-",strdup(SupSign(tempStr)),"",strdup(tempC)); $$.res=strdup(tempC);}
						else{$$.res=strdup(SupSign(tempStr));}
					}
        |REEL_SGN 	{$$.type = 2; tempStr=strdup(SupPar($1));
						if(checkSign(tempStr)){sprintf(tempC,"T%d",nTemp); nTemp++; quad("-",strdup(SupSign(tempStr)),"",strdup(tempC)); $$.res=strdup(tempC);}
						else{$$.res=strdup(SupSign(tempStr));}
					}
        ; 

//--------------------------partie instruction-------------------------------------------------------
		
instruction : INSTaff ';' instruction 					{}
														
            |INSTaff2';' instruction 					{}
														
            |INSTaff3 ';' instruction 					{}
														
            |INSTaff4 ';' instruction 					{}
														
            |IFpartie3 '}'  instruction 				{}
																										
            |FORpartie4 '}' instruction  				{}
																									
            |WHILEpartie2 '}' instruction 				{}
																									
            |											{}
            ;
/*-------------------------------------- non termineaux affectation --------------------------------*/

INSTaff : IDF AFF exp 										{rsVerifierDec($1); rsMAJconst($1); 
																if(TypeIDF($1)!=$3.type){yyerror("Affectation impossible, types incompatible. ");}
																quad(":=",$3.res,"",$1);
															}
		;
															
INSTaff2 : IDF '.' IDF AFF exp 								{rsVerifierDec($1);
																if(TypeIDF($1)!=3){sprintf(msg,"%s n\'est pas une structure. ",$1); yyerror(msg);}
																rsVerifierDecChamp($1,$3);
																if(TypeChamp($1,$3) != $5.type){yyerror("Affectation impossible, types incompatible. ");}
																sprintf(tempC,"%s.%s",$1,$3);
																quad(":=",$5.res,"",strdup(tempC));
															}
		;
		
INSTaff3 : IDF '[' ENTIER ']' AFF exp						{rsVerifierDec($1);
																if(TypeIDF($1)!=4 && TypeIDF($1)!=5){sprintf(msg,"%s n\'est pas un tableau. ",$1); yyerror(msg);}
																if((TypeIDF($1) - $6.type)!=3){yyerror("types incompatible. ");}
																sprintf(tempC,"%s[%s]",$1,$3);
																quad(":=",$6.res,"",strdup(tempC));
															}
		;
		
INSTaff4 : IDF '[' IDF ']' AFF exp							{rsVerifierDec($1); 
																if(TypeIDF($1)!=4 && TypeIDF($1)!=5){sprintf(msg,"%s n\'est pas un tableau. ",$1); yyerror(msg);}
																if(TypeIDF($3)!=1){yyerror("l\'indice utilise pour acceder aux elements du tableau doit etre entier. ");}
																if((TypeIDF($1) - $6.type)!=3){yyerror("types incompatible. ");}
																sprintf(tempC,"%s[%s]",$1,$3);
																quad(":=",$6.res,"",strdup(tempC));
															}
		;
/*-------------------------------------- non termineaux instruction IF --------------------------------*/

IFpartie3 : IFpartie2 '}' ELSE '{' instruction 							{ sprintf(position,"%d",getIndq());
																			MajQaud($1.sauv_BR,strdup(position));
																		}
			;
			
IFpartie2 : IFpartie1 ')' '{' instruction 								{$$.sauv_BR = quad("BR","","","");
																			sprintf(position,"%d",$$.sauv_BR+1);
																			MajQaud($1.sauv_BZ,strdup(position));
																			
																		}
		;
		
IFpartie1 : IF '(' condition											{$$.sauv_BZ = quad("BZ","",$3.res,"");
																			
																		}
			;
/*-------------------------------------- non termineaux instruction FOR --------------------------------*/

FORpartie4 : FORpartie3 ')' '{' instruction								{sprintf(tempC,"T%d",nTemp); nTemp++;
																			quad("+",$1.nomIndice,$1.etape,strdup(tempC));
																			quad(":=",strdup(tempC),"",$1.nomIndice);
																			sprintf(position,"%d",$1.debutCond);
																			quad("BR",strdup(position),"","");
																			sprintf(position,"%d",getIndq());
																			MajQaud($1.sauv_BNZ,strdup(position));
																		}
			;
			
FORpartie3 : FORpartie2 ':' ENTIER ':' condition						{$$.debutCond = getIndq() - $5.nbr;
																			$$.sauv_BNZ = quad("BNZ","",$5.res,"");
																			$$.etape = strdup($3);
																		}
			;
			
FORpartie2 : FORpartie1 ':' ENTIER 										{quad(":=",$3,"",$1.nomIndice); 
																			
																		}
			;
			
FORpartie1 : FOR '(' IDF 												{rsVerifierDec($3);
																			if(TypeIDF($3)!=1){ printf("erreur sémantique; %s n\'nest pas entier. ",$3); yyerror("");}
																			$$.nomIndice = strdup($3);
																		}
			;
			
/*-------------------------------------- non termineux instruction WHILE --------------------------------*/

WHILEpartie2 : WHILEpartie1 ')' '{' instruction							{sprintf(position,"%d",$1.debutCond);
																			quad("BR",strdup(position),"","");
																			sprintf(position,"%d",getIndq());
																			MajQaud($1.sauv_BZ,strdup(position));
																		}
			;
WHILEpartie1 : WHILE '(' condition										{$$.debutCond = getIndq() - $3.nbr;
																			$$.sauv_BZ = quad("BZ","",$3.res,"");
																		}
			;
/*-------------------------------------- les conditions --------------------------------*/

condition:condition OR condition	{if($1.type != $3.type){yyerror("expressions de types incompatible. ");}else{$$.type = $1.type;}
										sauv_BZ = quad("BZ","",$1.res,"");
										sprintf(tempC,"T%d",nTemp); nTemp++;
										sauv_res = quad(":=","1","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sauv_BNZ = quad("BNZ","",$3.res,"");
										sprintf(position,"%d",sauv_BNZ);
										MajQaud(sauv_BZ,strdup(position));
										sprintf(position,"%d",sauv_res);
										MajQaud(sauv_BNZ,strdup(position));
										quad(":=","0","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										$$.res=strdup(tempC); tempC[0]='\0'; $$.nbr=$3.nbr+5;
									}
        |condition AND condition 	{if($1.type != $3.type){yyerror("expressions de types incompatible. ");}else{$$.type = $1.type;}
										push(quad("BZ","",$1.res,""));
										push(quad("BZ","",$3.res,""));
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","1","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaudPile(strdup(position));
										quad(":=","0","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										$$.res=strdup(tempC); tempC[0]='\0'; $$.nbr=$3.nbr+5;
									}
        |NOT '(' condition ')' 		{$$.type = $3.type;
										sauv_BNZ = quad("BNZ","",$3.res,"");
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BNZ,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										$$.res=strdup(tempC); tempC[0]='\0'; $$.nbr=$3.nbr+4;
									}
        |exp G exp					{if($1.type != $3.type){yyerror("expressions de types incompatible. ");}else{$$.type = $1.type;}
										sauv_BG = quad("BG","",$1.res,$3.res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BG,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										$$.res=strdup(tempC); tempC[0]='\0'; $$.nbr=$1.nbr+$3.nbr+4;
									}
        |exp GE exp					{if($1.type != $3.type){yyerror("expressions de types incompatible. ");}else{$$.type = $1.type;}
										sauv_BGE = quad("BGE","",$1.res,$3.res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BGE,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										$$.res=strdup(tempC); tempC[0]='\0'; $$.nbr=$1.nbr+$3.nbr+4;
									}
        |exp L exp					{if($1.type != $3.type){yyerror("expressions de types incompatible. ");}else{$$.type = $1.type;}
										sauv_BL = quad("BL","",$1.res,$3.res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BL,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										$$.res=strdup(tempC); tempC[0]='\0'; $$.nbr=$1.nbr+$3.nbr+4;
									}
        |exp LE exp					{if($1.type != $3.type){yyerror("expressions de types incompatible. ");}else{$$.type = $1.type;}
										sauv_BLE = quad("BLE","",$1.res,$3.res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BLE,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										$$.res=strdup(tempC); tempC[0]='\0'; $$.nbr=$1.nbr+$3.nbr+4;
									}
        |exp E exp					{if($1.type != $3.type){yyerror("expressions de types incompatible. ");}else{$$.type = $1.type;}
										sauv_BE = quad("BE","",$1.res,$3.res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BE,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										$$.res=strdup(tempC); tempC[0]='\0'; $$.nbr=$1.nbr+$3.nbr+4;
									}
        |exp NE exp 				{if($1.type != $3.type){yyerror("expressions de types incompatible. ");}else{$$.type = $1.type;}
										sauv_BNE = quad("BNE","",$1.res,$3.res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BNE,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										$$.res=strdup(tempC); tempC[0]='\0'; $$.nbr=$1.nbr+$3.nbr+4;
									}
        |NUMBER 					{$$.type = $1.type; $$.res=$1.res;
										sprintf(tempC,"T%d",nTemp); nTemp++;
										if(atoi($1.res)!=0){
											quad(":=","1","",strdup(tempC));
										}
										else quad(":=","0","",strdup(tempC));
										$$.res=strdup(tempC); tempC[0]='\0'; $$.nbr=1;
									}
        ;


exp :    exp SUB term 		{if($1.type != $3.type)	{yyerror("types incompatible. ");} else{$$.type = $1.type;}
								sprintf(tempC,"T%d",nTemp); nTemp++; $$.res=strdup(tempC); tempC[0]='\0';
								quad("-",$1.res,$3.res,$$.res);
								$$.nbr=$1.nbr+$3.nbr+1;
							}
        |exp ADD term 		{if($1.type != $3.type)	{yyerror("types incompatible. ");} else{$$.type = $1.type;}
								sprintf(tempC,"T%d",nTemp); nTemp++; $$.res=strdup(tempC); tempC[0]='\0';
								quad("+",$1.res,$3.res,$$.res);
								$$.nbr=$1.nbr+$3.nbr+1;
							}
        |term 				{$$.res=$1.res; $$.type = $1.type;
								$$.nbr=$1.nbr;
							}
        ;

term: term MUL factor 		{if($1.type != $3.type){yyerror("types incompatible. ");} else{$$.type = $1.type;}
								sprintf(tempC,"T%d",nTemp); nTemp++; $$.res=strdup(tempC); tempC[0]='\0';
								quad("*",$1.res,$3.res,$$.res);
								$$.nbr=$1.nbr+1;
							}
     |term DIV factor 		{if(!strcmp($3.res,"0")){yyerror("division par zero.");} 
								sprintf(tempC,"T%d",nTemp); nTemp++; $$.res=strdup(tempC); tempC[0]='\0';
								quad("/",$1.res,$3.res,$$.res);
								$$.nbr=$1.nbr+1;
							}
     |factor 				{	$$.res =strdup($1.res); $$.type = $1.type; 
								$$.nbr=0;
							}
     ;

factor : IDF 				{rsVerifierDec($1); $$.res=strdup($1); $$.type = TypeIDF($1);}
		|IDF '[' ENTIER ']' {rsVerifierDec($1);
								if(TypeIDF($1)!=4 && TypeIDF($1)!=5){sprintf(msg,"%s n\'est pas un tableau. ",$1); yyerror(msg);}
								$$.type = TypeIDF($1)-3;
								sprintf(msg,"%s[%d]",$1,atoi($3));
								$$.res = strdup(msg);
							}
		|IDF '[' IDF ']'	{rsVerifierDec($1); 
								if(TypeIDF($1)!=4 && TypeIDF($1)!=5){sprintf(msg,"%s n\'est pas un tableau. ",$1); yyerror(msg);}
								if(TypeIDF($3)!=1){yyerror("l\'indice utilise pour acceder aux elements du tableau doit etre entier. ");}
								$$.type = TypeIDF($1)-3;
								sprintf(msg,"%s[%s]",$1,$3);
								$$.res = strdup(msg);
							}
		|IDF '.' IDF		{rsVerifierDec($1);
								if(TypeIDF($1)!=3){sprintf(msg,"%s n\'est pas une structure. ",$1); yyerror(msg);}
								rsVerifierDecChamp($1,$3);
								$$.type = TypeChamp($1,$3);
								sprintf(msg,"%s.%s",$1,$3);
								$$.res = strdup(msg);
							}
        |NUMBER 			{$$.res = $1.res; $$.type = $1.type;}
        |'(' exp ')' 		{$$.res = $2.res; $$.type = $2.type;}
        ; 



%%

int yyerror(char* msg){
    printf (" %s ligne %d colonne %d \n",msg,line,colo); exit (0);return 1;
}

int main (){ 
    yyin = fopen("test.txt", "r");
    yyparse ();
    fclose (yyin);
    afficherTS();
    //afficherStrTable();
	//afficherChamps();
	afficherQuad();
	createTextQuad();
	createCodeAssembleur();
}


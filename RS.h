#ifndef RS_H
#define RS_H


//routine sémantique(rs)

void rsDoubleDec(char *);
void rsVerifierDec(char *);
int isDeclaredVariable(char * );//fonction auxilière
void EntierOverflow(int a);
char* SupPar(char *s);//fonction auxilière, supprimer les parentèses
int checkSign(char *s);//vérifier si l'entier est signé est positive ou négative
char* SupSign(char *s);//supprimer la signe du nombre signé
void rsMAJconst(char *IDF);
void rsVerifierDecChamp(char *str, char *IDF);
void rsDoubleDecChamp(char *str, char *IDF);

#endif
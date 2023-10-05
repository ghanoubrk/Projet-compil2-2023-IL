#ifndef QUAD_H
#define QUAD_H

#define t 100
typedef struct {char*opr;
				 char* op1;
				 char* op2;
				 char* res;}quadruplet;
quadruplet q[t];				 

struct node {
    int info;
    struct node *ptr;  
}*top,*top1,*temp;

extern int indq;

//fonction d'insertion d'un nouveau quad
int quad (char*,char*,char*,char*);
//fonction qui insert un quad dans une position donnée
void quadPos(char*,char*,char*,char*,int);
//fonction qui affiche les quads
void afficherQuad();
//fonction qui retourne le l'indice courant dans la table des quadruplets
int getQC();
//fonction qui MAJ un quad
void MajQaud(int indice,char *val);
//fonction qui MAJ les quad par la pile
void MajQaudPile(char *val);
//fonction qui insert un element dans la pile
void push(int data);
//fonction qui supprime la tête de la pile et retourne sa valeur
int pop();
//fonction qui affiche les elements de la pile 
void display();
//fonction qui retourne indq est l'incrémente
int getIndq();


#endif // QUAD_H

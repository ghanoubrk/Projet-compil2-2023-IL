#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Quad.h"

int indq=0;//indice pour l'insertion dans la table q
int count = 0;//compteur de la pile
int indDec = 0;//indice de décalage
int indQuad = 0;//indice pour l'insertion dans la table T

int quad (char* o,char*o1,char*o2,char*r){
	q[indq].opr=o;
	q[indq].op1=o1;
	q[indq].op2=o2;
	q[indq].res=r;
	indq++;
	return indq-1;
}

int getIndq(){
	return indq;
}
 
void MajQaud(int indice,char *val){
	//strcpy(q[indice].op1,val);
	q[indice].op1=val;
}

void afficherQuad(){ 
	int i;
	printf("\n*******************Table des Quadruplets************************\n");
	for (i=0;i<indq;i++)
	{printf ("%d-( %s , %s , %s , %s )\n",i,q[i].opr,q[i].op1,q[i].op2,q[i].res);}
}

//fonctions de manipulation de la pile--------------------------------------------

// Push() operation on a  stack
void push(int data) {
     if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
    //printf("Node is Inserted\n\n");
}

int pop() {
     top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->ptr;
    int popped = top->info;
    free(top);
    top = top1;
    count--;
    return popped;
}

void display() {
    // Display the elements of the stack
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }
    
    printf("The stack is \n");
    while (top1 != NULL)
    {
        printf("%d--->", top1->info);
        top1 = top1->ptr;
    }
    printf("NULL\n\n");

}

void MajQaudPile(char *val){
	top1 = top;
	
	while(top1 != NULL){
		MajQaud(pop(),val);
	}
}

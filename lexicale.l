%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "syntaxique.tab.h"
extern YYSTYPE yylval;
int line=1,colo=1;
%}

%option noyywrap

chiffre [0-9]
lettre [a-zA-Z]
entier {chiffre}+
entier_sgn [(][+-]{chiffre}+[)]
reel {chiffre}+"."{chiffre}*
reel_sgn [(][+-]{chiffre}+"."{chiffre}*[)]
idf {lettre}([a-z]|{chiffre})*
space ("\t"|" ")+
saut "\n"+
comment "%%".*$

%%
"VAR"       {colo+=yyleng; yylval.nom=strdup(yytext); return (VAR);}
"CODE"      {colo+=yyleng; yylval.nom=strdup(yytext); return (CODE);}
"INTEGER"   {colo+=yyleng; yylval.nom=strdup(yytext); return (INTEGER);}
"FLOAT"     {colo+=yyleng; yylval.nom=strdup(yytext); return (FLOAT);}
"STRUCT"    {colo+=yyleng; yylval.nom=strdup(yytext); return (STRUCT);}
"IF"        {colo+=yyleng; yylval.nom=strdup(yytext); return (IF);}
"CONST"     {colo+=yyleng; yylval.nom=strdup(yytext); return (CONST);}
"ELSE"      {colo+=yyleng; yylval.nom=strdup(yytext); return (ELSE);}
"FOR"       {colo+=yyleng; yylval.nom=strdup(yytext); return (FOR);}
"WHILE"     {colo+=yyleng; yylval.nom=strdup(yytext); return (WHILE);}

{idf}       {
			colo+=yyleng; 
			if(yyleng>8){printf("erreur lexicale dans la ligne %d la colonne %d %s \\Identificateur ne doit pas depasser 8 characteres! \n",line,colo,yytext); exit(0);}
			yylval.nom=strdup(yytext); return (IDF);
			}
{reel}      {colo+=yyleng; yylval.nom=strdup(yytext); return (REEL);}
{entier}    {colo+=yyleng; yylval.nom=strdup(yytext); return (ENTIER);}
{entier_sgn} {colo+=yyleng; yylval.nom=strdup(yytext); return (ENTIER_SGN);}
{reel_sgn}   {colo+=yyleng; yylval.nom=strdup(yytext); return (REEL_SGN);}
{comment}   

"="         {colo+=yyleng; yylval.nom=strdup(yytext); return (AFF);}

"+"         {colo+=yyleng; yylval.nom=strdup(yytext); return (ADD);}
"-"         {colo+=yyleng; yylval.nom=strdup(yytext); return (SUB);}
"*"         {colo+=yyleng; yylval.nom=strdup(yytext); return (MUL);}
"/"         {colo+=yyleng; yylval.nom=strdup(yytext); return (DIV);}

"("         {colo+=yyleng; yylval.nom=strdup(yytext); return '(';}
")"         {colo+=yyleng; yylval.nom=strdup(yytext); return ')';}
"{"         {colo+=yyleng; yylval.nom=strdup(yytext); return '{';}
"}"         {colo+=yyleng; yylval.nom=strdup(yytext); return '}';}
";"         {colo+=yyleng; yylval.nom=strdup(yytext); return ';';}
":"         {colo+=yyleng; yylval.nom=strdup(yytext); return ':';}
"["         {colo+=yyleng; yylval.nom=strdup(yytext); return '[';}
"]"         {colo+=yyleng; yylval.nom=strdup(yytext); return ']';}
","         {colo+=yyleng; yylval.nom=strdup(yytext); return ',';}
"."         {colo+=yyleng; yylval.nom=strdup(yytext); return '.';}

"||"        {colo+=yyleng; yylval.nom=strdup(yytext); return (OR);}    
"&&"        {colo+=yyleng; yylval.nom=strdup(yytext); return (AND);}    
"!"         {colo+=yyleng; yylval.nom=strdup(yytext); return (NOT);}    

">"         {colo+=yyleng; yylval.nom=strdup(yytext); return G;}    
">="        {colo+=yyleng; yylval.nom=strdup(yytext); return GE;}    
"<"         {colo+=yyleng; yylval.nom=strdup(yytext); return L;}    
"<="        {colo+=yyleng; yylval.nom=strdup(yytext); return LE;}    
"=="        {colo+=yyleng; yylval.nom=strdup(yytext); return E;}    
"!="        {colo+=yyleng; yylval.nom=strdup(yytext); return NE;}    

{space}     {colo+=yyleng;}
{saut}      {line+=yyleng; colo=1;}

.           {printf("%s erreur lexicale dans la ligne %d la colonne %d \n",yytext,line,colo); exit(0);}

%%




/*Expressoes regulares*/
#ifndef MAISCULA_H
#define MAISCULA_H

#include <regex>
#include <getopt.h>
#include <string.h>
#include <cstring>
#include <fstream>


using namespace std;


/* Linhas do arquivo*/
string frase;

/*Expressão regular para as palavras*/  
string s("\\[([^\\}]+?)\\]");
regex reg (s);
smatch matches;

/*Contador */
int contador = 0;

int contadorToken = 0;

#endif
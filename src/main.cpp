#include "ArvoreAVL.hpp"

#include <fstream>
#include <string.h>
#include <cstring>
#include <regex>

using namespace std;

int main( int argc, char *argv[])
{

  Verbete palavras[10];

  /* Arquivo de texto*/
  ifstream texto;
  /* Linhas do arquivo*/
  string frase;

  /*Expressão regular para as palavras*/  
  string s("\\[([^\\}]+?)\\]");
  regex reg (s);
  smatch matches;

  /* vetor de palavras*/
  string v_palavras[10];

  /*Abre arquivo de texto*/
  texto.open(argv[1]);

  int contador = 0;

  /* imprimir palavra e significado separadamente*/
  while ( !texto.eof() )
  {
    /*Leio a linha*/
    getline(texto, frase);

    /*Pega a palavra por expressoes regulares*/
    cout << std::boolalpha;       
    regex_search(frase, matches, reg);
    // cout << matches.str(1) << endl;

    /*Criar uma condição que checa se a palavra ja foi adicionada*/
    palavras[contador].palavra = matches.str(1);


    /* Significados */
    char auxiliar_significado[frase.length()];
    char* token;

    strcpy(auxiliar_significado, frase.c_str());

    token = strtok(auxiliar_significado, "]");

    string significado;

    int cont = 0;
    while (token != NULL)
    {
      if(cont == 0)
      {
        token = strtok(NULL, "]");
        cont++;
        continue;
      }
      else
      {
        significado = token;
        token = strtok(NULL, "]");
      }
    }
    
    significado.erase(0,1);
    palavras[contador].AdicionaSignificado(significado);

    contador++;
  } 

  for (int i = 0; i < 10; i++)
  {
     
    palavras[i].ListaSignificados();
  }
  

  return 0;
}
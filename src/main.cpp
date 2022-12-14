#include "ArvoreAVL.hpp"
#include "Hashing.hpp"
#include "variaveis.hpp"
#include <stdlib.h>

/*arquivos de entrada e saida*/
ifstream Arquivo_entrada; 
ofstream Arquivo_saida;

/*Estrutura selecionada*/
char Estrutura[5];
char arvore[5] = "arv";
char Hash[5] = "hash";

void parse_args(int argc,char ** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optx, opty, regmem, lognome
{
  // variaveis externas do getopt
  extern char * optarg;
  // extern int optind;

  // variavel auxiliar
  int c;
  // smtc:

  while ((c = getopt(argc, argv, "i:o:t:")) != EOF)
      switch(c) {
        case 'i':
          Arquivo_entrada.open(optarg);
          break;

        case 'o':
          Arquivo_saida.open(optarg);
          break;

        case 't':
          strcpy(Estrutura,optarg);
          break;
        
        default:
        exit(1);
    }
}

int main( int argc, char *argv[])
{

  // if (!Arquivo_entrada.is_open())
  // {
  //   cout << "Arquivo de entrada nao encontrado, erro fatal!\n";
  //   exit(1);
  // }

  // if (!Arquivo_saida.is_open())
  // {
  //   cout << "Arquivos de saida nao encontrado, erro fatal!\n";
  //   exit(1);
  // }

  ArvoreAVL *Arvore = NULL;
  TabelaHashing Hashing[26];

  
  inicializarTabela(Hashing);
  
  /*Abre arquivo de texto*/
  parse_args(argc, argv);
  
  int contador = 0;

  /* imprimir palavra e significado separadamente*/
  while ( !Arquivo_entrada.eof() )
  {
    
    Verbete verbete_atual;
    
    /*Leio a linha*/
    getline(Arquivo_entrada, frase);

    /*-----------------------------------------------------------------------*/
    
    /*                               TIPO                                    */
    /*Tipo da palavra*/
    verbete_atual.tipo = frase[0];
    
    /*-----------------------------------------------------------------------*/

    /*-----------------------------------------------------------------------*/
    
    /*                              VERBETE                                 */
    /*Pega a palavra por expressoes regulares*/
    cout << std::boolalpha;       
    regex_search(frase, matches, reg);

    /*Criar uma condição que checa se a palavra ja foi adicionada*/
    verbete_atual.palavra = matches.str(1);
    
    /*-----------------------------------------------------------------------*/

    /*-----------------------------------------------------------------------*/
    
    /*                             SIGNIFICADOS                              */
    char auxiliar_significado[frase.length()];
    /*Esse token serve para percorrer toda a frase realizando os splits*/
    char* token;
    /*Copiei para um variavel do tipo char para poder utilizar a função que separa*/
    strcpy(auxiliar_significado, frase.c_str());

    /*Utilizei a o delimitador como "]" porque tudo depois dele é significado, ou não caso nao tenha*/
    token = strtok(auxiliar_significado, "]");

    /* Essa vai ser a string final*/
    string significado;

    /* Esse loop vai fazer o seguinte, ele vai exibir tudo que tem antes e depois do "]", então esse contador
    vai ignorar a primeira iteração que é a letra e a palavra, e na segunda,
    vai pegar a frase de significado e atribuir a string "significado."*/
    int contadorToken = 0;
    while (token != NULL)
    {
      if(contadorToken == 0)
      {
        token = strtok(NULL, "]");
        contadorToken++;
        continue;
      }
      else
      {
        significado = token;
        token = strtok(NULL, "]");
      }
    }
    /*Esse erase ta aqui, porque depois do "]", tem um espaço em branco, entao a maneira mais eficiente de apagar ele
    foi utilizando essa função que com essa configuração, apaga o primeiro caractere da string que nesse caso é
    o espaço em branco */
    significado.erase(0,1);
    
    /*-----------------------------------------------------------------------*/
    
    /*-----------------------------------------------------------------------*/
    /*                         INSERÇÃO DA ÁRVORE                            */

    // ---------------------------------------------------------------
    /*Criar função que retorna 1 ou 0 se o elemento estiver na arvore*/
    // ---------------------------------------------------------------
    
    if(significado.size() != 0)
    {
      verbete_atual.AdicionaSignificado(significado);
    }
    
    /*                    NOVO                                    */
    /*Comentando para implementar hash, depois colocar na estrutura de if abaixo*/
    
    // if(iterativeSearch(Arvore, verbete_atual.palavra))
    // {
    //   Append_significado(Arvore, verbete_atual.palavra, significado);
    //   continue;
    // }

    if(busca_sig(Hashing, verbete_atual.palavra,significado))
    {
      continue;
    }
    
    /*-----------------------------------------------------------------------------------*/
    /* Se a palavra ja estiver no dicionario o codigo vai parar aqui e recomeçar o while */
    contador++;

    /*-----------------------------------------------------------------------*/
    /*Adiciona na Arvore*/
    if(!strcmp(Estrutura, arvore))
    {

      if(((verbete_atual.palavra[0]) >= 'A') && ((verbete_atual.palavra[0]) <= 'Z'))
      {

        verbete_atual.palavra_maiuscula = verbete_atual.palavra;
        transform(verbete_atual.palavra.begin(), verbete_atual.palavra.end(), verbete_atual.palavra.begin(), ::tolower);

        Arvore = Inserir_Palavra(Arvore, verbete_atual);
        
      }
      else 
      {
        verbete_atual.palavra_maiuscula = " ";
        Arvore = Inserir_Palavra(Arvore, verbete_atual);
      }

    }
    else if(!strcmp(Estrutura, Hash))
    {
      if(((verbete_atual.palavra[0]) >= 'A') && ((verbete_atual.palavra[0]) <= 'Z'))
      {
        verbete_atual.palavra_maiuscula = verbete_atual.palavra;
        transform(verbete_atual.palavra.begin(), verbete_atual.palavra.end(), verbete_atual.palavra.begin(), ::tolower);
        
        inserir(Hashing, verbete_atual);
      }
      else{
        verbete_atual.palavra_maiuscula = " ";
        inserir(Hashing, verbete_atual);
      }
    }

  } 


  /*---------------------------------------------------------------------------*/
  /*                              EXIBIÇÃO                                     */
  
  // Exibicao_inOrder(Arvore, Arquivo_saida);
  imprime_tudo(Hashing);


  Arquivo_entrada.close();
  Arquivo_saida.close();
  return 0;
}
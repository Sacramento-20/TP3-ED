#include "Hashing.hpp"

#define TAM 26

int indice[26] = { 19, 20, 21, 22, 23, 24, 25, 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 11, 12, 13, 14, 15, 16, 17,18 };
char vetor[26] = {'h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g'};

void inicializarLista(ListaEnderecada* _dicionario){
  _dicionario -> inicio = NULL;
  _dicionario -> tamanho = 0;
}

void inserir_no_dicionario(ListaEnderecada* _dicionario, Verbete _verbete)
{
  Verbete* nova_palavra = new Verbete();
  // No *novo = new No();


  *nova_palavra = _verbete;
  // novo->proximo = NULL;

  /*primeiro elemento da lista*/
  if(_dicionario -> inicio == NULL)
  {
    _dicionario -> inicio = nova_palavra;
    _dicionario -> tamanho++;
    return;
  }

  else if(nova_palavra->palavra < _dicionario->inicio->palavra)
  {
    nova_palavra -> next = _dicionario->inicio;
    _dicionario -> inicio = nova_palavra;
  }

  else{
    Verbete *aux = _dicionario -> inicio;
    while(aux -> next != NULL && nova_palavra -> palavra > aux -> next -> palavra)
    {
      aux = aux -> next;
    }
    nova_palavra -> next = aux -> next;
    aux -> next = nova_palavra;
    _dicionario -> tamanho++;
    return;
  }

}

void remover_elemento(ListaEnderecada* _dicionario, std::string _verbete)
{
  Verbete* temporario = _dicionario -> inicio;

  Verbete* auxiliar = NULL;

  if(temporario != NULL && temporario -> palavra == _verbete)
  {
    _dicionario -> inicio = temporario -> next;

    delete temporario;
    return;
  } 
  else
  {
    while(temporario != NULL && temporario -> palavra != _verbete)
    {
      auxiliar = temporario;
      temporario = temporario -> next;
    }
    if(temporario == NULL)
    {
      return;
    }

    auxiliar -> next = temporario -> next;

    delete temporario;
  }
}

std::string buscar_no_dicionario(ListaEnderecada* _dicionario, std::string _verbete){
    
  Verbete *aux = _dicionario -> inicio;
  
  while(aux && aux -> palavra != _verbete)
  {
    aux = aux -> next;
  }
  if(aux)
  {
    return aux -> palavra;
  }

  return 0;
}


void inicializarTabela(ListaEnderecada* _dicionario){
  int i;

  for(i = 0; i < TAM; i++)
  {
    inicializarLista(&_dicionario[i]);
  }
}

int funcaoHash(int chave){
  return chave % TAM;
}

void inserir(ListaEnderecada* _dicionario, Verbete _verbete){
  int id = funcaoHash(_verbete.palavra[0]);

  inserir_no_dicionario(&_dicionario[id], _verbete);

}

void remover(ListaEnderecada* _dicionario, std::string _verbete )
{
  int id = funcaoHash(_verbete[0]);
  remover_elemento(&_dicionario[id], _verbete);
}

Verbete busca(ListaEnderecada* _dicionario, std::string _verbete){
  int id = funcaoHash(_verbete[0]);
  return buscar_no_dicionario(&_dicionario[id], _verbete);
}

void imprimir_dicionario(ListaEnderecada* _dicionario)
{
  Verbete *aux = _dicionario -> inicio;
  
  std::cout << " Tam: " << _dicionario -> tamanho << " ";
  
  while(aux)
  {
    std::cout << aux -> palavra << " ";
    aux = aux -> next;
  }
}

void imprimir(ListaEnderecada* _dicionario){
  int i = 0;
  
  while(i < TAM)
  {
    std::cout << vetor[indice[i]] << " = ";
    imprimir_dicionario(&_dicionario[indice[i]]);
    std::cout << "\n";
    i++;
  }
  
}

void imprime_palavras(ListaEnderecada* _dicionario)
{

  Verbete *aux = _dicionario -> inicio;
  
  while(aux != NULL)
  {
    std::cout << aux -> palavra << std::endl;
    aux = aux -> next;
  }

}

void imprime_tudo(ListaEnderecada* _dicionario)
{
  int i = 0;
  
  while(i < TAM)
  {
    imprime_palavras(&_dicionario[indice[i]]);
    i++;
  }

}
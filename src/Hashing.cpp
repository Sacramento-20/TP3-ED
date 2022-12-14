#include "Hashing.hpp"

#define TAM 26

int indice[26] = { 19, 20, 21, 22, 23, 24, 25, 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 11, 12, 13, 14, 15, 16, 17,18 };
char vetor[26] = {'h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g'};

void inicializarLista(TabelaHashing* _dicionario){
  _dicionario -> inicio = NULL;
  _dicionario -> tamanho = 0;
}

void inserir_no_dicionario(TabelaHashing* _dicionario, Verbete _verbete)
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

void remover_elemento(TabelaHashing* _dicionario, std::string _verbete)
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



void inicializarTabela(TabelaHashing* _dicionario){
  int i;

  for(i = 0; i < TAM; i++)
  {
    inicializarLista(&_dicionario[i]);
  }
  
}

int funcaoHash(int chave){
  return chave % TAM;
}

void inserir(TabelaHashing* _dicionario, Verbete _verbete){
  std::string aux;
  aux = _verbete.palavra;

  transform(aux.begin(), aux.end(), aux.begin(), ::tolower);

  int id = funcaoHash(aux[0]);

  inserir_no_dicionario(&_dicionario[id], _verbete);

}

void remover(TabelaHashing* _dicionario, std::string _verbete )
{
  int id = funcaoHash(_verbete[0]);
  remover_elemento(&_dicionario[id], _verbete);
}

int buscar_no_dicionario(TabelaHashing* _dicionario, std::string _verbete){
    
  Verbete *aux = _dicionario -> inicio;
  
  while(aux && aux -> palavra != _verbete)
  {
    aux = aux -> next;
  }
  if(aux)
  {
    return 1;
  }

  return 0;
}

int busca(TabelaHashing* _dicionario, std::string _verbete){
  int id = funcaoHash(_verbete[0]);
  return buscar_no_dicionario(&_dicionario[id], _verbete);
}
/*---------------------------------------------------------------------------------------------------------------*/
bool busca_sig(TabelaHashing* _dicionario, std::string _verbete, std::string _significado)
{
  int id = funcaoHash(_verbete[0]);
  return adiciona_sig(&_dicionario[id], _verbete, _significado);
}

bool adiciona_sig(TabelaHashing* _dicionario, std::string _verbete, std::string _significado)
{

  Verbete *aux = _dicionario -> inicio;
  
  while(aux && aux -> palavra != _verbete)
  {
    aux = aux -> next;
  }
  if(aux)
  {
    aux->AdicionaSignificado(_significado);
    return 1;
  }

  return 0;

}


void imprimir_dicionario(TabelaHashing* _dicionario)
{
  Verbete *aux = _dicionario -> inicio;
  
  std::cout << " Tam: " << _dicionario -> tamanho << " ";
  
  while(aux)
  {
    std::cout << aux -> palavra << " ";
    aux = aux -> next;
  }
}

void imprimir(TabelaHashing* _dicionario){
  int i = 0;
  
  while(i < TAM)
  {
    std::cout << vetor[indice[i]] << " = ";
    imprimir_dicionario(&_dicionario[indice[i]]);
    std::cout << "\n";
    i++;
  }
  
}

int MaiusculaHash(std::string palavra){
  return (((palavra[0]) >= 'A') && ((palavra[0]) <= 'Z'));
}

void imprime_palavras(TabelaHashing* _dicionario)
{

  Verbete *aux = _dicionario -> inicio;
  
  while(aux != NULL)
  {
    if(MaiusculaHash(aux->palavra_maiuscula))
    {
      std::cout << aux-> palavra_maiuscula << " (" << aux->tipo << ")" << std::endl;
      aux -> ListaSignificados();
    }
    else
    {
      std::cout <<  aux -> palavra << " (" << aux->tipo << ")" << std::endl;  
      aux -> ListaSignificados();
    }
    aux = aux -> next;
  }
}

void imprime_tudo(TabelaHashing* _dicionario)
{
  int i = 0;
  while(i < TAM)
  {
    imprime_palavras(&_dicionario[indice[i]]);
    i++;
  }

}
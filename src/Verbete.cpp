#include "Verbete.hpp"

Verbete::Verbete()
{
  this->Head = NULL; 
}

Verbete::Verbete(std::string _palavra)
{
  /*Declaração dos atributos ao inicializar o objeto*/
  this->palavra = _palavra;
  this->Head = NULL;
}

void Verbete::AdicionaSignificado(std::string _significado){
  /*Cria um objeto do tipo significado para armazenar a string*/
  Significado *novo_significado = new Significado(_significado); 
  
  /*Cria um apontador para receber a cebeça da lista encadeada*/
  Significado *ultimo_elemento = this->Head;

  /*Faz o novo objeto apontar para nulo*/
  novo_significado->Next = NULL;
  
  /*Se não existir nenhum elemento na lista*/
  if(Head == NULL)
  {
    Head = novo_significado;
    return;
  }

  /*Enquanto não encontar o ultimo elemento da lista, continua apontando para o proximo*/
  while (ultimo_elemento->Next != NULL)
  {
    ultimo_elemento = ultimo_elemento->Next;
  }
  
  /*O ponteiro proximo do ultimo elemento da lista recebe o novo objeto significado*/
  ultimo_elemento->Next = novo_significado;
  return;
}

bool Verbete::VerificaSignificado()
{
  Significado* auxiliar = this->Head;
  
  if(auxiliar == NULL)
  {
    return 0;
  }
  return 1;
}

void Verbete::ListaSignificados()
{
  /*Cria um objeto auxiliar que irá receber a cabeça da lista de significados*/
  Significado* auxiliar = this->Head;

  /*Exibindo a palavra no inicio da ação de exibir seus significados*/
  std::cout << "Palavra: " << this->palavra << std::endl;
  
  /*Condição que irá exibir uma mensagem caso não exista nenhum significado para a palavra selecionada*/
  if(auxiliar == NULL)
  {
    std::cout << "Palavra sem significados" << std::endl;
    return;
  }

  /*While que irá exibir todos os significados presentes na palavra, caso ouver*/
  while (auxiliar != NULL)
  {
    std::cout << auxiliar -> frase << std::endl;
    auxiliar = auxiliar -> Next;
  }
  
}

void Verbete::ExcluiSignificado(std::string _significado)
{
  /*Objeto temporario recebe a cabeça da lista*/
  Significado* temporario = this->Head;

  /*Objeto auxiliar que será utilizado na remoção*/
  Significado* auxiliar = NULL;

  /*Estrutura de condição que irá checar se a cabeça possui o elemento a se removido*/
  if(temporario != NULL && temporario->frase == _significado)
  {
    this->Head = temporario->Next;

    delete temporario;
    return;
  }
  else
  {
    /*Estrutura de repetição que irá checar entre todos os significados se existe o que foi solicitado*/
    while(temporario != NULL && temporario->frase != _significado)
    {
      auxiliar = temporario;
      temporario = temporario->Next;
    }
    /*Condição que avalia se chegou no ultimo elemento*/
    if(temporario == NULL)
    {
      return;
    }

    auxiliar->Next = temporario->Next;

    delete temporario;
  }


}

Verbete::~Verbete()
{

}

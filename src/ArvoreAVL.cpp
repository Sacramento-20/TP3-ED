#include "ArvoreAVL.hpp"

int Altura(ArvoreAVL *_dicionario)
{
  if (_dicionario == NULL)
  {
    return 0;
  }
  return _dicionario->altura;
}

int Maximo(int a, int b)
{
  return (a > b)? a : b;
}

int Balanco(ArvoreAVL *_dicionario)
{
  if (_dicionario == NULL)
  {
    return 0;
  }
  return Altura(_dicionario->left) - Altura(_dicionario->right);
}

ArvoreAVL* Nova_palavra(Verbete _palavra)
{
  ArvoreAVL* dicionario = new ArvoreAVL();
  dicionario->verbete = _palavra;
  dicionario->left = NULL;
  dicionario->right = NULL;
  dicionario->altura = 1; 

  return(dicionario);
}

ArvoreAVL* Rotacao_Direita(ArvoreAVL *_Arvore)
{
  ArvoreAVL *x = _Arvore->left;
  ArvoreAVL *T2 = x->right;

  x->right = _Arvore;
  _Arvore->left = T2;

  _Arvore->altura = Maximo(Altura(_Arvore->left), Altura(_Arvore->right)) + 1;
  x->altura = Maximo(Altura(x->left), Altura(x->right)) + 1;

  return x;
}
 

ArvoreAVL* Rotacao_Esquerda(ArvoreAVL* _Arvore)
{
  ArvoreAVL *y = _Arvore->right;
  ArvoreAVL *T2 = y->left;

  y->left = _Arvore;
  _Arvore->right = T2;

  _Arvore->altura = Maximo(Altura(_Arvore->left), Altura(_Arvore->right)) + 1;
  y->altura = Maximo(Altura(y->left), Altura(y->right)) + 1;

  return y;
}


ArvoreAVL* Inserir_Palavra(ArvoreAVL* _dicionario, Verbete _palavra)
{
  
  if (_dicionario == NULL)
  {
    return(Nova_palavra(_palavra));
  }

  if (_palavra.palavra < _dicionario->verbete.palavra)
  {
    _dicionario->left = Inserir_Palavra(_dicionario->left, _palavra);
  }

  else if (_palavra.palavra > _dicionario->verbete.palavra)
  {
    _dicionario->right = Inserir_Palavra(_dicionario->right, _palavra);
  }

  else 
  {
    return _dicionario;
  }
  
  _dicionario->altura = 1 + Maximo(Altura(_dicionario->left), Altura(_dicionario->right));

  int balance = Balanco(_dicionario);

  if (balance > 1 && _palavra.palavra < _dicionario->left->verbete.palavra)
  {
    return Rotacao_Direita(_dicionario);
  }

  if (balance < -1 && _palavra.palavra > _dicionario->right->verbete.palavra)
  {
    return Rotacao_Esquerda(_dicionario);
  }

  if (balance > 1 && _palavra.palavra > _dicionario->left->verbete.palavra)
  {
    _dicionario->left = Rotacao_Esquerda(_dicionario->left);
    return Rotacao_Direita(_dicionario);
  }

  if (balance < -1 && _palavra.palavra < _dicionario->right->verbete.palavra)
  {
    _dicionario->right = Rotacao_Direita(_dicionario->right);
    return Rotacao_Esquerda(_dicionario);
  }

  return _dicionario;
}

ArvoreAVL* MenorNo(ArvoreAVL* _no) 
{ 
  ArvoreAVL* current = _no; 

  while (current->left != NULL) 
  {
    current = current->left; 
  }
  return current; 
}

ArvoreAVL* Deletar_Palavra(ArvoreAVL* _dicionario, Verbete _palavra) 
{ 
      
  
  if (_dicionario == NULL) 
  {
    return _dicionario; 
  }
 
  if ( _palavra.palavra < _dicionario->verbete.palavra ) 
  {  
    _dicionario->left = Deletar_Palavra(_dicionario->left, _palavra); 
  }

  else if( _palavra.palavra > _dicionario->verbete.palavra ) 
  {
    _dicionario->right = Deletar_Palavra(_dicionario->right, _palavra); 
  }
 
  else
  { 

    if( (_dicionario->left == NULL) || (_dicionario->right == NULL) ) 
    { 
      ArvoreAVL *temp = _dicionario->left ? _dicionario->left : _dicionario->right; 

      if (temp == NULL) 
      { 
        temp = _dicionario; 
        _dicionario = NULL; 
      } 
      else
      {
      *_dicionario = *temp; 
      }
      
      free(temp); 
    } 

    else
    {   
      ArvoreAVL* temp = MenorNo(_dicionario->right); 

      _dicionario->verbete = temp->verbete; 

      _dicionario->right = Deletar_Palavra(_dicionario->right,temp->verbete);
    } 

  } 

  if (_dicionario == NULL) 
  {
    return _dicionario; 
  }
  
  _dicionario->altura = 1 + Maximo(Altura(_dicionario->left), Altura(_dicionario->right)); 

  int balance = Balanco(_dicionario); 


  if (balance > 1 && Balanco(_dicionario->left) >= 0) 
  {
    return Rotacao_Direita(_dicionario); 
  }
  
  if (balance > 1 && Balanco(_dicionario->left) < 0) 
  { 
    _dicionario->left = Rotacao_Esquerda(_dicionario->left); 
    return Rotacao_Direita(_dicionario); 
  } 
 
  if (balance < -1 && Balanco(_dicionario->right) <= 0) 
  {
    return Rotacao_Esquerda(_dicionario); 
  }
  
  if (balance < -1 && Balanco(_dicionario->right) > 0) 
  { 
    _dicionario->right = Rotacao_Direita(_dicionario->right); 
    return Rotacao_Esquerda(_dicionario); 
  } 

  return _dicionario; 
}

void Insere_em_Vetor(Lista_palavras **vetor_palavras, std::string _palavra)
{
  Lista_palavras* nova_palavra = new Lista_palavras();
  Lista_palavras* ultima_palavra = *vetor_palavras;

  nova_palavra->palavra = _palavra;
  nova_palavra->next = NULL;

  if(*vetor_palavras == NULL)
  {
    *vetor_palavras = nova_palavra;
    return;
  }

  while (ultima_palavra->next != NULL)
  {
    ultima_palavra = ultima_palavra->next;
  }
  
  ultima_palavra->next = nova_palavra;
  return;
}

void Conta_Significados(ArvoreAVL *_dicionario, Lista_palavras **vetor_palavras)
{
  if(_dicionario != NULL)
  {
    if(_dicionario->verbete.VerificaSignificado() == 0 )
    {
      // *contador = *contador +1;
      Insere_em_Vetor(vetor_palavras, _dicionario->verbete.palavra);
      // std::cout << _dicionario->verbete.palavra << " ";
      // Deletar_Palavra(_dicionario, _dicionario->verbete);
    }
    Conta_Significados(_dicionario->left, vetor_palavras);
    Conta_Significados(_dicionario->right, vetor_palavras);
  }
}

void printList(Lista_palavras *no)
{
  while (no != NULL)
  {
    std::cout<< no->palavra << " ";
    no = no->next;
  }
}



void Remocao_sem_Significado(ArvoreAVL *_dicionario, Lista_palavras *vetor_palavras)
{
  
  while(vetor_palavras != NULL)
  {
    _dicionario = Deletar_Palavra(_dicionario, vetor_palavras->palavra);
    vetor_palavras = vetor_palavras->next;
  }

}

void Exibicao_preOrder(ArvoreAVL *_dicionario)
{
  if(_dicionario != NULL)
  {
    std::cout << _dicionario->verbete.palavra << " ";
    Exibicao_preOrder(_dicionario->left);
    Exibicao_preOrder(_dicionario->right);
  }
}

// void Remove(ArvoreAVL *_dicionario)
// {
//   if(_dicionario != NULL)
//   {
//     if(_dicionario->verbete.VerificaSignificado() == 0 )
//     {
//       _dicionario = Deletar_Palavra(_dicionario, _dicionario->verbete);
//       return ;
//     }
//     Remove(_dicionario->left);
//     Remove(_dicionario->right);
//   }
// }
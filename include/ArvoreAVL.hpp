#ifndef ARVOREAVL_H
#define ARVOREAVL_H

#include "Verbete.hpp"

class ArvoreAVL
{
  public:
  Verbete verbete;
  ArvoreAVL *left;
  ArvoreAVL *right;
  int altura;

};

struct Lista_palavras
{
  std::string palavra;
  Lista_palavras *next;
};

/*Metodos de inserção e remoção*/
ArvoreAVL* Nova_palavra(Verbete _palavra);
ArvoreAVL* Inserir_Palavra(ArvoreAVL *_dicionario, Verbete palavra);
ArvoreAVL* Deletar_Palavra(ArvoreAVL* dicionario, Verbete palavra);

// void Conta_Significados(ArvoreAVL *_dicionario, int *contador);
void Conta_Significados(ArvoreAVL *_dicionario, Lista_palavras **vetor_palavras);
void Remocao_sem_Significado(ArvoreAVL *_dicionario, Lista_palavras *vetor_palavras);
void printList(Lista_palavras *no);

/*Métodos de balanceamento da Arvore*/
ArvoreAVL* Rotacao_Direita(ArvoreAVL *_dicionario);
ArvoreAVL* Rotacao_Esquerda(ArvoreAVL *_dicionario);
ArvoreAVL* MenorNo(ArvoreAVL* _no);

/*Métodos auxiliares*/
int Maximo(int a, int b);
int Altura(ArvoreAVL *_dicionario);
int Balanco(ArvoreAVL *_dicionario);

/*Exibição*/
int N_Significados(ArvoreAVL *_dicionario);
void Contador_Significados(ArvoreAVL *_dicionario, int *contador);
void Exibicao_preOrder(ArvoreAVL *_dicionario);

#endif
#ifndef HASHING_H
#define HASHING_H

#include "Verbete.hpp"
#include <fstream>

class ListaEnderecada
{
  public:
  Verbete* inicio;
  int tamanho;

};

void inicializarLista(ListaEnderecada* _dicionario);
void inserir_no_dicionario(ListaEnderecada* _dicionario, Verbete _verbete);
void remover_elemento(ListaEnderecada* _dicionario, std::string _verbete);

std::string buscar_no_dicionario(ListaEnderecada* _dicionario, std::string _verbete);

void inicializarTabela(ListaEnderecada* _dicionario);
int funcaoHash(int chave);

void inserir(ListaEnderecada* _dicionario, Verbete _verbete);
// void remover(ListaEnderecada* _dicionario, Verbete _verbete);
void remover(ListaEnderecada* _dicionario, std::string _verbete);

Verbete busca(ListaEnderecada* _dicionario, std::string _verbete);

void imprimir_dicionario(ListaEnderecada* _dicionario);

void imprimir(ListaEnderecada* _dicionario);
void imprime_palavras(ListaEnderecada* _dicionario);
void imprime_tudo(ListaEnderecada* _dicionario);


#endif
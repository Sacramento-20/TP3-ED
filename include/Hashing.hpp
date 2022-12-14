#ifndef HASHING_H
#define HASHING_H

#include "Verbete.hpp"
#include <fstream>
#include <algorithm>

class TabelaHashing
{
  public:
  Verbete* inicio;
  int tamanho;

};

void inicializarLista(TabelaHashing* _dicionario);
void inserir_no_dicionario(TabelaHashing* _dicionario, Verbete _verbete);
void remover_elemento(TabelaHashing* _dicionario, std::string _verbete);

int buscar_no_dicionario(TabelaHashing* _dicionario, std::string _verbete);

void inicializarTabela(TabelaHashing* _dicionario);
int funcaoHash(int chave);

void inserir(TabelaHashing* _dicionario, Verbete _verbete);
// void remover(TabelaHashing* _dicionario, Verbete _verbete);
void remover(TabelaHashing* _dicionario, std::string _verbete);

int busca(TabelaHashing* _dicionario, std::string _verbete);

bool busca_sig(TabelaHashing* _dicionario, std::string _verbete, std::string _significado);
bool adiciona_sig(TabelaHashing* _dicionario, std::string _verbete, std::string _significado);


void imprimir_dicionario(TabelaHashing* _dicionario);

void imprimir(TabelaHashing* _dicionario);
void imprime_palavras(TabelaHashing* _dicionario);
void imprime_tudo(TabelaHashing* _dicionario);


#endif
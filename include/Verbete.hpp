/* Lista encadeada de palavras */
#ifndef VERBETE_H
#define VERBETE_H
#include "Significado.hpp"

class Verbete
{

  public:
    std::string palavra;
    Significado* Head = nullptr;
    

    /*Construtor padrão*/
    Verbete();
    /*Construtor sobrecarregado*/
    Verbete(std::string _palavra);

    /*Lista todos os siginificados presentes na palavra*/
    void ListaSignificados();
    /*Adiciona um siginificado a uma palavra*/
    void AdicionaSignificado(std::string _significado);
    /*Exclui um significado de uma palavra*/
    void ExcluiSignificado(std::string _significado);
    /*Destrutor virtual*/
    virtual ~Verbete();

};

#endif

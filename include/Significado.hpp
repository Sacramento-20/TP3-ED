/*Lista encadeada de significados*/
#ifndef SIGNIFICADO_H
#define SIGNIFICADO_H

#include <iostream>

class Significado
{
  public:
  
    std::string frase;
    Significado* Next;

    /*Construtor padrão*/
    Significado();
    /*Construtuor sobrecarregado*/
    Significado(std::string frase);
    /*Destrutor virtual*/
    virtual ~Significado();

};

#endif

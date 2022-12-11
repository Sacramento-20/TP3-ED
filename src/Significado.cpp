#include "Significado.hpp"

Significado::Significado()
{
  this->Next = NULL; 
}

Significado::Significado(std::string _frase)
{
  this->frase = _frase;
  this->Next = NULL;
}

Significado::~Significado()
{}

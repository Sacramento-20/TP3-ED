#include "Verbete.hpp"

using namespace std;


int main(){
  Verbete *palavra1 = new Verbete("casa");
  Verbete *palavra2 = new Verbete("carro");
  Verbete *palavra3 = new Verbete("comoda"); 
  
  palavra1->AdicionaSignificado("onde mora");
  palavra1->AdicionaSignificado("onde a familia se encontra");
  palavra1->AdicionaSignificado("Lugar para repousar");

  // palavra2->AdicionaSignificado("Objeto que dirige");
  // palavra2->AdicionaSignificado("possui 4 rodas e 2 ou 4 portas");
  // palavra2->AdicionaSignificado("todos os carros foram construidos pelo homem");

  palavra1->ListaSignificados();
  palavra1->ExcluiSignificado("Lugar para repousar");
  palavra1->ListaSignificados();
  // palavra2->ListaSignificados();
  // palavra3->ListaSignificados();

  delete(palavra1);
  delete(palavra2);
  delete(palavra3);
}
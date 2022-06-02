#include "Operador.h"

Operador::Operador(long codigo, std::string nome, std::string endereco, std::string telefone, Data data, float salarioDiario):Funcionario(codigo, nome, endereco, telefone, data, 1, salarioDiario)
{

}

Operador::~Operador()
{

}

void Operador::aumentoSalarial()
{
    this->salarioDiario+=salarioDiario*0.05;
}
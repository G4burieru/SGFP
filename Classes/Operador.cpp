#include "Operador.h"

Operador::Operador():Funcionario(codigo, nome, endereco, telefone, data, designacao, salarioDiario)
{

}

Operador::~Operador()
{

}

void Operador::aumentoSalarial()
{
    this->salarioDiario+=salarioDiario*0.05;
}
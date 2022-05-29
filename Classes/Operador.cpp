#include "Operador.h"

Operador::Operador():Funcionario(codigo, nome, endereco, telefone, data, designacao, salario)
{

}

Operador::~Operador()
{

}

void Operador::aumentoSalarial()
{
    this->salario+=salario*0.05;
}
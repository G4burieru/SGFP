#include "Gerente.h"

Gerente::Gerente():Funcionario(codigo, nome, endereco, telefone, data, designacao, salarioDiario)
{

}

Gerente::~Gerente()
{

}

std::string Gerente::getAreasupervisao()
{
    return this->areaSupervisao;
}

void Gerente::setAreasupervisao(std::string areaSupervisao)
{
   this->areaSupervisao = areaSupervisao;
}

void Gerente::aumentoSalarial()
{
    this->salarioDiario+=salarioDiario*0.1;
}
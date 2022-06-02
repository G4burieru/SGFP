#include "Gerente.h"

Gerente::Gerente(long codigo, std::string nome, std::string endereco, std::string telefone, Data data, float salarioDiario):Funcionario(codigo, nome, endereco, telefone, data, 2, salarioDiario)
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
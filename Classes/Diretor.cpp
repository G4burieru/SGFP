#include "Diretor.h"

Diretor::Diretor(long codigo, std::string nome, std::string endereco, std::string telefone, Data data, float salarioDiario):Funcionario(codigo, nome, endereco, telefone, data, 3, salarioDiario)
{

}

Diretor::~Diretor()
{

}

std::string Diretor::getAreasupervisao()
{
    return this->areaSupervisao;
}

std::string Diretor::getAreaformacao()
{
    return this->areaFormacao;
}

void Diretor::setAreasupervisao(std::string areaSupervisao)
{
   this->areaSupervisao = areaSupervisao;
}

void Diretor::setAreaformacao(std::string areaFormacao)
{
   this->areaFormacao = areaFormacao;
}

void Diretor::aumentoSalarial()
{
    this->salarioDiario+=salarioDiario*0.2;
}
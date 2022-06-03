#include "Presidente.h"

Presidente::Presidente(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, float salarioDiario):Funcionario(codigo, nome, endereco, telefone, data, 4, salarioDiario)
{

}

Presidente::~Presidente()
{

}

std::string Presidente::getAreaformacao()
{
    return this->areaFormacao;
}

std::string Presidente::getFormacaomaxima()
{
    return this->formacaoMaxima;
}

void Presidente::setAreaformacao(std::string areaFormacao)
{
   this->areaFormacao = areaFormacao;
}

void Presidente::setFormacaomaxima(std::string formacaoMaxima)
{
   this->formacaoMaxima = formacaoMaxima;
}

void Presidente::aumentoSalarial()
{
    this->salarioDiario+=salarioDiario*0.3;
}
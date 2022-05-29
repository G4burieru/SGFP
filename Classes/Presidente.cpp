#include "Presidente.h"

Presidente::Presidente():Funcionario(codigo, nome, endereco, telefone, data, designacao, salario)
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
    this->salario+=salario*0.3;
}
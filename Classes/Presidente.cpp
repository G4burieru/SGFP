#include "Presidente.h"

Presidente::Presidente(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, float salarioDiario, std::string areaFormacao, std::string formacaoMaxima):Funcionario(codigo, nome, endereco, telefone, data, 4, salarioDiario)
{
    this->areaFormacao=areaFormacao;
    this->formacaoMaxima=formacaoMaxima;
}

Presidente::~Presidente()
{

}

std::string Presidente::getAreaFormacao()
{
    return this->areaFormacao;
}

std::string Presidente::getFormacaoMaxima()
{
    return this->formacaoMaxima;
}

void Presidente::setAreaFormacao(std::string areaFormacao)
{
   this->areaFormacao = areaFormacao;
}

void Presidente::setFormacaoMaxima(std::string formacaoMaxima)
{
   this->formacaoMaxima = formacaoMaxima;
}

void Presidente::aumentoSalarial()
{
    this->salarioDiario+=salarioDiario*0.3;
}

std::string Presidente::getAreaSupervisao(){
    return NULL;
}
void Presidente::setAreaSupervisao(std::string areaSupervisao){}
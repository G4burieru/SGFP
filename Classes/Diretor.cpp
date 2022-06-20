#include "Diretor.h"

Diretor::Diretor(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, float salarioDiario, std::string areaSupervisao, std::string areaFormacao):Funcionario(codigo, nome, endereco, telefone, data, 3, salarioDiario)
{
    this->areaSupervisao=areaSupervisao;
    this->areaFormacao=areaFormacao;
}

Diretor::~Diretor()
{

}

std::string Diretor::getAreaSupervisao()
{
    return this->areaSupervisao;
}

std::string Diretor::getAreaFormacao()
{
    return this->areaFormacao;
}

void Diretor::setAreaSupervisao(std::string areaSupervisao)
{
   this->areaSupervisao = areaSupervisao;
}

void Diretor::setAreaFormacao(std::string areaFormacao)
{
   this->areaFormacao = areaFormacao;
}

void Diretor::aumentoSalarial()
{
    this->salarioDiario+=salarioDiario*0.2;
}

std::string Diretor::getFormacaoMaxima(){
    return NULL;
}
void Diretor::setFormacaoMaxima(std::string formacaoMaxima){

}
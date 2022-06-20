#include "Gerente.h"

Gerente::Gerente(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, float salarioDiario, std::string areaSupervisao):Funcionario(codigo, nome, endereco, telefone, data, 2, salarioDiario)
{
    this->areaSupervisao=areaSupervisao;
}

Gerente::~Gerente()
{

}

std::string Gerente::getAreaSupervisao()
{
    return this->areaSupervisao;
}

void Gerente::setAreaSupervisao(std::string areaSupervisao)
{
   this->areaSupervisao = areaSupervisao;
}

void Gerente::aumentoSalarial()
{
    this->salarioDiario+=salarioDiario*0.1;
}

std::string Gerente::getAreaFormacao(){
    return NULL;
}
void Gerente::setAreaFormacao(std::string areaFormacao){}
std::string Gerente::getFormacaoMaxima(){
    return "não";
}
void Gerente::setFormacaoMaxima(std::string formacaoMaxima){}
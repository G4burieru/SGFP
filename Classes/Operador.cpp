#include "Operador.h"

Operador::Operador(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, float salarioDiario):Funcionario(codigo, nome, endereco, telefone, data, 1, salarioDiario)
{

}

Operador::~Operador()
{

}

void Operador::aumentoSalarial()
{
    this->salarioDiario+=salarioDiario*0.05;
}

std::string Operador::getAreaSupervisao(){
    return NULL;
}
void Operador::setAreaSupervisao(std::string areaSupervisao){}
std::string Operador::getAreaFormacao(){
    return NULL;
}
void Operador::setAreaFormacao(std::string areaFormacao){}

std::string Operador::getFormacaoMaxima(){
    return NULL;
}
void Operador::setFormacaoMaxima(std::string formacaoMaxima){}
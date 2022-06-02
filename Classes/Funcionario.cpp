#include "Funcionario.h"

Funcionario::Funcionario(long codigo, std::string nome, std::string endereco, std::string telefone, Data data, int designacao, float salarioDiario)
{
    this-> codigo = codigo;
    this-> nome = nome;
    this-> endereco = endereco;
    this-> telefone = telefone;
    this-> data = data;
    this-> designacao = designacao;
    this-> salarioDiario = salarioDiario;

}

Funcionario::~Funcionario()
{

}

void Funcionario::aumentoSalarial(){

}

long Funcionario::getCodigo()
{
    return this->codigo;
}

std::string Funcionario::getNome()
{
    return this->nome;
}

std::string Funcionario::getEndereco()
{
    return this->endereco;
}

std::string Funcionario::getTelefone()
{
    return this->telefone;
}

Data Funcionario::getData()
{
    return this->data;
}

int Funcionario::getDesignacao()
{
    return this->designacao;
}

float Funcionario::getSalarioDiario()
{
    return this->salarioDiario;
}

void Funcionario::setCodigo(long codigo)
{
   this->codigo = codigo;
}

void Funcionario::setNome(std::string nome)
{
   this->nome = nome;
}

void Funcionario::setEndereco(std::string endereco)
{
   this->endereco = endereco;
}

void Funcionario::setTelefone(std::string telefone)
{
   this->telefone = telefone;
}

void Funcionario::setData(Data data)
{
   this->data = data;
}

void Funcionario::setDesignacao(int designacao)
{
   this->designacao = designacao;
}

void Funcionario::setSalarioDiario(float salario)
{
   this->salarioDiario = salario;
}

FolhaSalarial Funcionario::getFolhaDoMes(int mes){
    return folhaDoMes[mes];
}
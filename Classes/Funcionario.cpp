#include "Funcionario.h"

Funcionario::Funcionario()
{

}

Funcionario::~Funcionario()
{

}

int Funcionario::getCodigo(){
    return this->codigo;
}

std::string Funcionario::getNome(){
    return this->nome;
}

std::string Funcionario::getEndereco(){
    return this->endereco;
}

int Funcionario::getTelefone(){
    return this->telefone;
}

Data Funcionario::getData(){
    return this->data;
}

std::string Funcionario::getDesignacao(){
    return this->designacao;
}

float Funcionario::getSalario(){
    return this->salario;
}

void Funcionario::setCodigo(int codigo){
   this->codigo = codigo;
}

void Funcionario::setNome(std::string nome){
   this->nome = nome;
}

void Funcionario::setEndereco(std::string endereco){
   this->endereco = endereco;
}

void Funcionario::setTelefone(int telefone){
   this->telefone = telefone;
}

void Funcionario::setData(Data data){
   this->data = data;
}

void Funcionario::setDesignacao(std::string designacao){
   this->designacao = designacao;
}

void Funcionario::setSalario(float salario){
   this->salario = salario;
}
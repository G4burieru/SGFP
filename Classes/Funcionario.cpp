#include "Funcionario.h"
#include <iostream>

Funcionario::Funcionario(long codigo, std::string nome, Endereco endereco, std::string telefone, Data data, int designacao, float salarioDiario)
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
    /*----------------------------------------------------------------------------------------------------------
    ---calcular as folhas dos meses anteriores antes de dar o aumento (caso ela ainda n tenha sido calculada)---
    ----------------------------------------------------------------------------------------------------------*/
}

long Funcionario::getCodigo()
{
    return this->codigo;
}

std::string Funcionario::getNome()
{
    return this->nome;
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

void Funcionario::setEndereco(std::string CEP, std::string numeroRua)
{
   this->endereco = Endereco(CEP, numeroRua);
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
    return folhaDoMes[mes-1];
}

Endereco Funcionario::getEndereco(){
    return this->endereco;
}

void Funcionario::setDiasTrabalhadosMes(int dias, int mes){
    folhaDoMes[mes-1].setDiasTrabalhados(dias);
}

void Funcionario::setHorasExtrasMes(float horas, int mes){
    folhaDoMes[mes-1].setHorasExtras(horas);
}

void Funcionario::setSalarioMesBrutoMes(float salarioB, int mes){
    folhaDoMes[mes-1].setSalarioMesBruto(salarioB);
}

void Funcionario::setSalarioMesLiquidoMes(float salarioL, int mes){
    folhaDoMes[mes-1].setSalarioMesLiquido(salarioL);
}

void Funcionario::setDescontoPrevidenciaMes(float descontoP, int mes){
    folhaDoMes[mes-1].setDescontoPrevidencia(descontoP);
}

void Funcionario::setdescontoImpostoRendMes(float descontoI, int mes){
    folhaDoMes[mes-1].setDescontoImpostoRend(descontoI);
}

void Funcionario::calculaFolhaMes(float SalarioDiario, int mes)
{
    folhaDoMes[mes-1].calculaSalario(SalarioDiario);
    folhaDoMes[mes-1].calculaPrevidencia();
    folhaDoMes[mes-1].calculaImportoRend();
    folhaDoMes[mes-1].caculaSalarioLiqudo();
}

void Funcionario::imprimirFolhaMes(int mes)
{
    std::cout << std::endl;
    std::cout << "Funcionario: " << nome << std::endl;
    std::cout << "Salario Bruto: R$ " << folhaDoMes[mes-1].getSalarioMesBruto() << std::endl;
    std::cout << "Desconto da previdencia social: R$ " << folhaDoMes[mes-1].getDescontoPrevidencia() << std::endl;
    std::cout << "Desconto do Imposto de renda: R$ " << folhaDoMes[mes-1].getDescontoImpostoRend() << std::endl;
    std::cout << "Total de Descontos: R$ " << folhaDoMes[mes-1].getDescontoPrevidencia() + folhaDoMes[mes-1].getDescontoImpostoRend() << std::endl;
    std::cout << "Salario Liquido: R$ " << folhaDoMes[mes-1].getSalarioMesLiquido() << std::endl;
    std::cout << std::endl;
}

float Funcionario::getSalarioAno()
{
    float total = 0;
    
    for(int i = 0; i < 12; i++)
    {
        total += folhaDoMes[i].getSalarioMesBruto();
    }

    return total;
    
}

float Funcionario::getImpostoRendAno()
{
    float total = 0;
    
    for(int i = 0; i < 12; i++)
    {
        total += folhaDoMes[i].getDescontoImpostoRend();
    }

    return total;
}

float Funcionario::getPrevidenciaAno()
{
    float total = 0;
    
    for(int i = 0; i < 12; i++)
    {
        total += folhaDoMes[i].getDescontoPrevidencia();
    }

    return total;
}

void Funcionario::imprimirFolhaAnual(){
    std::cout << std::endl;
    std::cout << "Funcionario: " << nome << std::endl;
    std::cout << "Salario Anual Bruto: R$ " << getSalarioAno() << std::endl;
    std::cout << "Desconto anual da previdencia social: R$ " << getPrevidenciaAno() << std::endl;
    std::cout << "Desconto anual do Imposto de renda: R$ " << getImpostoRendAno() << std::endl;
    std::cout << "Total de Descontos: R$ " << getPrevidenciaAno() + getImpostoRendAno() << std::endl;
    std::cout << "Salario Anual Liquido: R$ " << getSalarioAno() - getPrevidenciaAno() - getImpostoRendAno() << std::endl;
    std::cout << std::endl;
}


std::string Funcionario::getAreaSupervisao(){
    return "nao";
}
void Funcionario::setAreaSupervisao(std::string areaSupervisao){

}
std::string Funcionario::getAreaFormacao(){
    return "nao";
}
void Funcionario::setAreaFormacao(std::string areaFormacao){

}
std::string Funcionario::getFormacaoMaxima(){
    return "nao";
}
void Funcionario::setFormacaoMaxima(std::string formacaoMaxima){

}
